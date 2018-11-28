#ifndef DRIVER_H
#define DRIVER_H

#include <stdexcept>
#include <iostream>
#include "Order.h"
#include <queue>

using namespace std;

class Driver{
    public:
    Driver(); //Constructor Initialises the varaiables
    void login(string DriverName); //Logs the user in (Works with any name)
    void logout(); //Logouts the user name
    void CreateOrder(int NewHour, int NewMinute, string TheInfo); // Creates an Order and inserts the order intyo the Queue
    void depart() throw(logic_error);
    void deliver() throw(logic_error);
    void arrive() throw(logic_error);
    private:
    queue<Order> myOrders; //Queue of orders
    string myDriver;
    int orderStatus;
    //shows the status of the order
    //0: order is at the restaurant
    //1: driver is out for delivery
    //2: driver has delivered order 
    //3: driver is back at the restaurant

};

Driver::Driver()
{
myDriver = "";
}

void Driver::login(string DriverName)
{
myDriver= DriverName;
};


void Driver:: depart() throw(logic_error)
/*
*pre-condition: order is at the restaurant
*post-condition: driver is out for delivery
 */
{
    if(orderStatus != 0)
        throw logic_error("Order has not been received at the restaurant");
    orderStatus = 1;
}

void Driver:: deliver() throw(logic_error)
/*
 *pre-condition: driver is out for delivery
 *post-condition: driver has delivered order
 */
{
    if(orderStatus != 1)
        throw logic_error("Driver is not out to deliver order");
    orderStatus = 2;
}

void Driver:: arrive() throw(logic_error)
/*
 *pre-condition: driver has delivered order
 *post-condition: driver is back at the shop
 */
{
    if(orderStatus != 2)
        throw logic_error("Driver has not delivered order");
    orderStatus = 3;
}

void Driver::CreateOrder(int NewHour, int NewMinute, string TheInfo){
Time myTime; //The time variable
Order newOrder(myTime, TheInfo); //Creates Order with a default time
newOrder.setTime(NewHour, NewMinute); //Sets the new Time
myOrders.push(newOrder); //Adds to the Queue

}

#endif
