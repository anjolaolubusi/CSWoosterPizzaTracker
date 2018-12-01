#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
#include "Time.h"

using namespace std;

class Order{
public:
    Order(); //Constructor. Initalises the variables
    Order(Time myTime, string MyInfo); //Sets the variables to certain values
    void setTime(int myHour, int myMinute);// Sets the time variables
    string GetInfo(); //Returns the address, item and quantity
    void setInfo(string myInfo); // Sets the extra infomation
    Order& operator= (Order& otherOrder); // Copy Constructor
    void PrintOrder(Order& otherOrder2); // Prints the time and infomation
    /**
     * pre: @param myTime must be defined and be set to the time the order was made
     * post:
     */
    double averageOrderTime(Time myTime);
private:
Time mytime; //Time variales
    string info; // Infomation string
    double avgTime;
};

Order::Order(){
    info = "";
}

Order::Order(Time TheTime, string myInfo){
    mytime = TheTime;
    info = myInfo;
}


void Order::setTime(int myHour, int myMinute){
    mytime.setTime(myHour, myMinute);
}


string Order::GetInfo(){
    return info;
}



Order& Order::operator= (Order& otherOrder2){
    otherOrder2.mytime = mytime;
    otherOrder2.info = info;
}

void Order::PrintOrder(Order& otherOrder2){
    cout << otherOrder2.GetInfo() << endl;
    cout << otherOrder2.mytime << endl;
}

double Order::averageOrderTime(Time myTime) {
    return avgTime;
}

#endif
