#ifndef DRIVER_H
#define DRIVER_H

#include <stdexcept>
#include <iostream>
#include "Order.h"
#include <queue>
#include <stack>

using namespace std;

class Driver{
    public:
    Driver(); //Constructor Initialises the varaiables
    void login(string DriverName); //Logs the user in (Works with any name)
    void logout(); //Logouts the user name
    void CreateOrder(int NewHour, int NewMinute, string TheInfo); // Creates an Order and inserts the order intyo the Queue
    void depart(int MyHour, int MyMinute, string DepartDriver) throw(logic_error);
    void deliver() throw(logic_error);
    void arrive() throw(logic_error);
    queue<Order> getOrders(); //Returns the order queue
    stack<string> getDrivers(); //Returns the Driver stack
    Driver& operator= (Driver& otherDriver); //Operator function
    string GetCurrentDrivers(); // Returns the current Driver name

    private:
    queue<Order> myOrders; //Queue of orders
    stack<string> myDrivers;
    stack<string> DeliverDrivers;
    string currentDriver;
    int orderStatus;
    //shows the status of the order
    //0: order is at the restaurant
    //1: driver is out for delivery
    //2: driver has delivered order
    //3: driver is back at the restaurant
};

Driver::Driver()
{

}

//Post-condition: the name of the driver is in a stack
void Driver::login(string DriverName)
{
    myDrivers.push(DriverName);
    currentDriver = DriverName;
};

void Driver::CreateOrder(int NewHour, int NewMinute, string TheInfo, string TheDriver){
    Time myTime; //The time variable
    Order newOrder(myTime, TheInfo, TheDriver); //Creates Order with a default time
    newOrder.setTime(NewHour, NewMinute); //Sets the new Time
    myOrders.push(newOrder); //Adds to the Queue

}

void Driver:: depart(int MyHour, int MyMinute, string DepartDriver) throw(logic_error)
/*
*pre-condition: order is at the restaurant
*post-condition: driver is out for delivery
 */
{
    myOrders.front().SetTimeDeparted(MyHour, MyMinute);
    myOrders.front().SetDriver(DepartDriver);
}

void Driver:: deliver() throw(logic_error)
/*
 *pre-condition: driver is out for delivery
 *post-condition: driver has delivered order
 */
{


}

void Driver:: arrive() throw(logic_error)
/*
 *pre-condition: driver has delivered order
 *post-condition: driver is back at the shop
 */
{

}

queue<Order> Driver::getOrders(){
    return myOrders;
}

//Returns the stack of orders
stack<string> Driver::getDrivers(){
    return myDrivers;
}

//Equals operator
Driver& Driver::operator= (Driver& otherOrder2){
    otherOrder2.currentDriver = currentDriver;
    otherOrder2.myDrivers = myDrivers;
    otherOrder2.myOrders = myOrders;
    otherOrder2.orderStatus = orderStatus;
}

//Returns the name of the current driver
string Driver::GetCurrentDrivers(){
    return currentDriver;
}





#endif
