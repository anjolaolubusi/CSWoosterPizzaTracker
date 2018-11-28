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
    void login(); //Logs the user in (Works with any name)
    void logout(); //Logouts the user name
    void CreateOrder(int NewHour, int NewMinute, string TheInfo); // Creates an Order and inserts the order in

    private:
    queue<Order> myOrders; //Queue of orders

};

Driver::Driver(){


}

void Driver::login(){

}

void Driver::logout(){

}

void Driver::CreateOrder(int NewHour, int NewMinute, string TheInfo){
Time myTime; //The time variable
Order newOrder(myTime, TheInfo); //Creates Order with a default time
newOrder.setTime(NewHour, NewMinute); //Sets the new Time
myOrders.push(newOrder); //Adds to the Queue
}

#endif
