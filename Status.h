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
queue<Order> currentOrders = myDriver.getOrders();

while(!currentOrders.empty()){
Order w = currentOrders.front();
w.PrintOrder(w);
currentOrders.pop();
}

}
#endif
