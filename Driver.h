//
//  driver.h


#ifndef driver_h
#define driver_h

#include <iostream>
#include <string>
#include "Time.h"
#include "Order.h"
using namespace std;

class Driver
{
public:
    Driver(const string aName);

    Driver(Driver& anotherDriver);

    Driver& operator=(Driver& anotherDriver);

    void login() throw (logic_error);

    void logout() throw (logic_error);

    void depart(const Time time, const Order o) throw (logic_error);

    void deliver(const Time time, const float tip) throw (logic_error);

    void arrive(const Time time) throw (logic_error);

    string getName() const;

    int getTotalDeliveries() const;

    int getTotalMinDelivering() const;

    int getTotalMinDriving() const;

    float getTotalTips() const;

    Order getOrder() const throw (logic_error);

    string toString() const;

    float averageDeliveryTime() const;

    bool loggedIn() const;

    bool isDelivering() const;

    bool isComingback() const;

    Time arrival() const;
private:
    string name;//Driver's name

    bool isLoggedIn;//returns true if driver is logged in, else false

    bool isOnDelivery;//True if driver has left for delivery, else false

    bool hasDelivered;//True if the order has been delivered, else false

    int totalDeliveries;//total number of deliveries by the driver

    int totalMinDelivering;//time spent per delivery

    int totalMinDriving;//time spent driving per delivery

    float totalTips;

    Order order;

    Time timeDepart;

    Time timeDeliver;

    Time timeArrive;
};




/***************************** Driver.cpp ***************************************/


Driver :: Driver(const string aName)
//pre-condition: none
//post-condition: creates a logged-in driver with the given name
:name(aName), isLoggedIn(true), isOnDelivery(false), hasDelivered(false), totalDeliveries(0), totalMinDelivering(0), totalMinDriving(0), totalTips(0.0), timeDepart(Time()), timeDeliver(Time()), timeArrive(Time()), order(Order())
{

}

Driver :: Driver(Driver& anotherDriver)
//pre-condition:none
//post-condition: initializes the driver to be equivalent to the driver object parameters
:name(anotherDriver.name), isLoggedIn(anotherDriver.isLoggedIn), isOnDelivery(anotherDriver.isOnDelivery), hasDelivered(anotherDriver.hasDelivered), totalDeliveries(anotherDriver.totalDeliveries), totalMinDelivering(anotherDriver.totalMinDelivering), totalTips(anotherDriver.totalTips), timeDepart(anotherDriver.timeDepart), timeDeliver(anotherDriver.timeDeliver), timeArrive(anotherDriver.timeArrive), order(anotherDriver.order), totalMinDriving(anotherDriver.totalMinDriving)
{

}


// pre-condition: none
// post-condition: Sets the Driver to be equivalent to the other and returns a reference to the modified Driver.
Driver& Driver::operator=(Driver& anotherDriver)
{
    if (&anotherDriver != this)
    {
        name = anotherDriver.name;
        isLoggedIn = anotherDriver.isLoggedIn;
        isOnDelivery = anotherDriver.isOnDelivery;
        hasDelivered = anotherDriver.hasDelivered;
        totalDeliveries = anotherDriver.totalDeliveries;
        totalMinDelivering = anotherDriver.totalMinDelivering;
        totalTips = anotherDriver.totalTips;
        timeDepart = anotherDriver.timeDepart;
        timeDeliver = anotherDriver.timeDeliver;
        timeArrive = anotherDriver.timeArrive;
        totalMinDriving = anotherDriver.totalMinDriving;
    }
    return *this;
}

//pre-condition: Driver is not logged in
//post-condition: Driver is logged in
void Driver::login() throw(logic_error)
{

    if (isLoggedIn)
        throw logic_error("Driver is already logged in");

    isLoggedIn = true;
}

//pre-condition: Driver is logged in
//post-condition: Driver is logged out
void Driver::logout() throw(logic_error)
{
    if (!isLoggedIn)
    {
        throw logic_error("Driver is already logged out");
    }

    isLoggedIn = false;
}

//pre-condition: Driver is not on delivery and is logged in
//post-condition: Driver is on delivery
void Driver::depart( Time time, const Order o) throw (logic_error)
{
    if (!isLoggedIn)
        throw logic_error("Driver is not logged in");

    if (isOnDelivery)
        throw logic_error("Driver is already delivering");

    isOnDelivery = true;
    timeDepart = time;
    order = o;
    order.depart(time, getName());
}

//pre-condition: Driver is on delivery and the order has not been delivered. Tip >= 0
//post-condition: Order has been delivered.
void Driver::deliver(Time time, const float tip) throw(logic_error)
{
    if (!isOnDelivery)
        throw logic_error("Driver is not on delivery");

    if (hasDelivered)
        throw logic_error("Order has been delivered");

    if (tip < 0)
        throw logic_error("Tip has to be equal to or greater than 0");

    order.SetTimeDelivered(time.getHour(), time.getMinute());

    hasDelivered = true;
    timeDeliver = time;
    totalDeliveries++;
    totalTips += tip;
    totalMinDelivering = time.elapsedTime(timeDepart, timeDeliver);
}

//pre-condition: Driver is on delivery and the order has been delivered.
//post-condition: Order has been delivered.
void Driver::arrive(Time time) throw (logic_error)
{
    if (!isOnDelivery)
        throw logic_error("Driver is not on delivery");

    if (!hasDelivered)
        throw logic_error("Order has not been delivered");

    isOnDelivery = false;
    timeArrive = time;
    totalMinDriving = time.elapsedTime(timeDepart, timeArrive);
    hasDelivered = false;
}

//pre-condition: none
//post-condition: Returns the driver’s name.
string Driver::getName() const
{
    return name;
}

//pre-condition: none
//post-condition: Returns the total number of completed deliveries.
int Driver::getTotalDeliveries() const
{
    return totalDeliveries;
}

//pre-condition: none
//post-condition: Returns the total minutes spent driving
int Driver::getTotalMinDriving() const
{
    return totalMinDriving;
}

//pre-condition: none
//post-condition: Returns the total minutes spent delivering
int Driver::getTotalMinDelivering() const
{
    return totalMinDelivering;
}

//pre-condition: none
//post-condition: Returns the total tips received, in dollars.
float Driver::getTotalTips() const
{
    return totalTips;
}

//pre-condition: Driver is delivering.
//post-condition: Returns the order being delivered.
Order Driver::getOrder() const throw(logic_error)
{
    if (!isOnDelivery)
        throw logic_error("Driver is not on delivery");

    return order;
}

//pre-condition: none
//post-condition: Returns a string containing the driver’s name, state, and, if the driver is delivering an order, the departure time and toString of the order being delivered.
string Driver::toString() const
{
    string driver_info;
    driver_info = name + " ";

    if (isLoggedIn)
        driver_info.append("is logged in ");
    else
        driver_info.append("is not logged in.");

    return driver_info;
}

//pre-condition: none
//post-condition:average time per completed delivery of driver (from “depart” to “deliver”). Return N/A if there is no completed delivery
float Driver::averageDeliveryTime() const
{
    float average_time = (totalDeliveries != 0) ? (float)totalMinDelivering / totalDeliveries : 0;

    return average_time;
}

//pre-condition: none
//post-condition: Returns true if and only if the driver is logged in.
bool Driver::loggedIn() const
{
    return isLoggedIn;
}

bool Driver::isDelivering() const{
    return isOnDelivery;
}

bool Driver::isComingback() const{
    return hasDelivered;
}

Time Driver::arrival() const{
    return timeArrive;
}

#endif /* driver_h */
