#ifndef DRIVER_H
#define DRIVER_H

#include <stdexcept>
#include <iostream>
#include "Order.h"
#include <list>

using namespace std;

class Driver{
    public:
    Driver();
    void login(string Drivername);
    void logout();
    void CreateOrder(Time myTime, string TheInfo);
    void depart() throw(logic_error);
    void deliver() throw(logic_error);
    void arrive() throw(logic_error);
    private:
    //list<Order> myOrder;
    Order myOrder[13];
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
}

void Driver::logout()
{

}

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

void Driver::CreateOrder(Time myTime, string TheInfo){
Order newOrder(myTime, TheInfo);
myOrder[1] = newOrder;
}


#endif
