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
    
    void depart(const Time time, const Order o);
    
    void deliver(const Time time, const float tip);
    
    void arrive(const Time time);
    
    string getName() const;
    
    int getTotalDeliveries() const;
    
    int getTotalMinDelivering() const;
    
    int getTotalMinDriving() const;
    
    float getTotalTips() const;
    
    Order getOrder() const;
    
    string toString() const;
    
    float averageDeliveryTime() const;
    
    bool loggedIn() const;
    
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

Driver& Driver::operator=(Driver& anotherDriver)
// pre-condition: none
// post-condition: Sets the Driver to be equivalent to the other and returns a reference to the modified Driver.
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

void Driver::login() 
//pre-condition: Driver is not logged in
//post-condition: Driver is logged in
{
    
    if (isLoggedIn)
        cout << "Driver is already logged in")<< endl;
    
    isLoggedIn = true;
}

void Driver::logout() 
//pre-condition: Driver is logged in
//post-condition: Driver is logged out
{
    if (!isLoggedIn)
    {
        cout << "Driver is already logged out") << endl;
    }
    
    isLoggedIn = false;
}

void Driver::depart(const Time time, const Order o) 
//pre-condition: Driver is not on delivery and is logged in
//post-condition: Driver is on delivery
{
    if (!isLoggedIn)
        cout << "Driver is not logged in" << endl;
    
    if (isOnDelivery)
        cout << "Driver is already delivering" << endl;
    
    isOnDelivery = true;
    timeDepart = time;
    order = o;
    order.depart();
}

void Driver::deliver(const Time time, const float tip) throw(logic_error)
//pre-condition: Driver is on delivery and the order has not been delivered. Tip >= 0
//post-condition: Order has been delivered.
{
    if (!isOnDelivery)
        cout << "Driver is not on delivery" << endl;
    
    if (hasDelivered)
        cout << "Order has been delivered" << endl;
    
    if (tip < 0)
        cout << "Tip has to be equal to or greater than 0" << endl;
    
    order.deliver(time);
    
    hasDelivered = true;
    timeDeliver = time;
    totalDeliveries++;
    totalTips += tip;
    totalMinDelivering = Time::elapsedMin(timeDepart, timeDeliver);
}

void Driver::arrive(const Time time) throw (logic_error)
//pre-condition: Driver is on delivery and the order has been delivered.
//post-condition: Order has been delivered.
{
    if (!isOnDelivery)
        cout << "Driver is not on delivery" << endl;
    
    if (!hasDelivered)
        cout << "Order has not been delivered" << endl;
    
    isOnDelivery = false;
    timeArrive = time;
    totalMinDriving = Time::elapsedMin(timeDepart, timeArrive);
    hasDelivered = false;
}

//pre-condition: none
//post-condition: Returns the driver’s name.
string Driver::getName() const
{
    return name;
}

int Driver::getTotalDeliveries() const
//pre-condition: none
//post-condition: Returns the total number of completed deliveries.
{
    return totalDeliveries;
}

int Driver::getTotalMinDriving() const
//pre-condition: none
//post-condition: Returns the total minutes spent driving
{
    return totalMinDriving;
}

int Driver::getTotalMinDelivering() const
//pre-condition: none
//post-condition: Returns the total minutes spent delivering
{
    return totalMinDelivering;
}

float Driver::getTotalTips() const
//pre-condition: none
//post-condition: Returns the total tips received, in dollars.
{
    return totalTips;
}

Order Driver::getOrder() 
//pre-condition: Driver is delivering.
//post-condition: Returns the order being delivered.
{
    if (!isOnDelivery)
        cout << "Driver is not on delivery" << endl;
    
    return order;
}

string Driver::toString() const
//pre-condition: none
//post-condition: Returns a string containing the driver’s name, state, and, 
//if the driver is delivering an order, the departure time and toString of the order being delivered.
{
    string driver_info;
    driver_info = name + " ";
    
    if (isLoggedIn)
        driver_info.append("is logged in ");
    else
        driver_info.append("is not logged in.");
    
    if (isOnDelivery)
        driver_info += "and departed at" + order.orderInfo();
    
    return driver_info;
}

float Driver::averageDeliveryTime() const
//pre-condition: none
//post-condition:average time per completed delivery of driver (from “depart” to “deliver”). 
//Return N/A if there is no completed delivery
{
    float average_time = (totalDeliveries != 0) ? (float)totalMinDelivering / totalDeliveries : 0;
    
    return average_time;
}

bool Driver::loggedIn() const
//pre-condition: none
//post-condition: Returns true if and only if the driver is logged in.
{
    return isLoggedIn;
}

#endif /* driver_h */
