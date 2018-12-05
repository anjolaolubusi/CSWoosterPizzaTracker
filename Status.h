#ifndef STATUS_H
#define STATUS_H

#include <stdexcept>
#include <iostream>
#include <queue>
#include "Driver.h"
#include "Order.h"

using namespace std;

class Status{
    public:
    void PrintStatus(Driver myDriver);
};

void Status::PrintStatus(Driver myDriver){
queue<Order> WaitingToBeCooked = myDriver.getOrders(); //A copy of the order queue

cout << "Orders waiting to be cooked: "  << "\n" << endl;
while(!WaitingToBeCooked.empty()){

Order w = WaitingToBeCooked.front(); // Gets the front of the queue
    if(w.getDepartedTime().getHour() == -1 && w.getDepartedTime().getMinute() == -1){ // Checks if the order has not been departed
    w.PrintOrder(w);
    }
WaitingToBeCooked.pop();
}

queue<Order> WaitingToBeDelivered = myDriver.getOrders(); //A copy of the order queue

cout << "Orders waiting to be delivered: "  << "\n" << endl;
while(!WaitingToBeDelivered.empty()){

Order w = WaitingToBeDelivered.front();  // Gets the front of the queue
    if(w.getDepartedTime().getHour() != -1 && w.getDepartedTime().getMinute() != -1){ // Checks if the order has not been departed
    w.PrintOrder(w);
    }
WaitingToBeDelivered.pop();
}

}
#endif
