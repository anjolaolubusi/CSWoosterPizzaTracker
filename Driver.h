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
    private:
    //list<Order> myOrder;
    Order myOrder[13];
    string myDriver;

};

Driver::Driver(){
myDriver = "";
}

void Driver::login(string DriverName){
myDriver= DriverName;
}

void Driver::logout(){

}

void Driver::CreateOrder(Time myTime, string TheInfo){
Order newOrder(myTime, TheInfo);
myOrder[1] = newOrder;
}


#endif
