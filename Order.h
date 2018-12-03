#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
#include "Time.h"
#include "Driver.h"

using namespace std;

class Order{
public:
    Order(); //Constructor. Initalises the variables
    ~Order();
    Order(Time myTime, string MyInfo, string TheDriver); //Sets the variables to certain values
    void setTime(int myHour, int myMinute);// Sets the time variables
    string GetInfo(); //Returns the address, item and quantity
    void setInfo(string myInfo); // Sets the extra infomation
    Order& operator= (Order otherOrder); // Copy Constructor
    void PrintOrder(Order& otherOrder2); // Prints the time and infomation

private:
Time mytime; //Time variales
string info; // Infomation string
string myDriver;
double averageOrderTime(Time myTime);
};

Order(){
    info = "";
    myDriver = "";
}

~Order(){

}


Order::Order(Time TheTime, string myInfo, string TheDriver){
    mytime = TheTime;
    info = myInfo;
    myDriver = TheDriver;
}


void Order::setTime(int myHour, int myMinute){
    mytime.setTime(myHour, myMinute);
}


string Order::GetInfo(){
    return info;
}




Order& Order::operator= (Order otherOrder2){
    otherOrder2.mytime = mytime;
    otherOrder2.info = info;
    otherOrder2.myDriver = myDriver;
}

void Order::PrintOrder(Order& otherOrder2){
    cout << otherOrder2.GetInfo() << endl;
    cout << otherOrder2.mytime << endl;
    cout << otherOrder2.PrintDriver() << endl;
}

double Order::averageOrderTime(Time myTime) {
    return avgTime;
  }

string Order::PrintDriver(){
    return myDriver;
}

#endif
