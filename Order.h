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
    Order(Time myTime, string MyInfo); //Sets the variables to certain values
    void setTime(int myHour, int myMinute);// Sets the time variables
    string GetInfo(); //Returns the address, item and quantity
    void setInfo(string myInfo); // Sets the extra infomation
    Order& operator= (Order otherOrder); // Copy Constructor
    void PrintOrder(Order& otherOrder2); // Prints the time and infomation
    string GetInfo(); //Returns the address, item and quanity
   // void setInfo(string myInfo); // Sets the extra infomation
    Order& operator= (Order otherOrder); // Copy Constructor
    void PrintOrder(Order& otherOrder2); // Prints the time and infomation
    string PrintDriver(); //Outputs the current driver
    void SetDriver(string NewDriver); //Sets the current driver
    void SetTimeDeparted(int myHour, int myMinute); //Sets the hour and the minute of departTime
    Time getDepartedTime(); //Returns the departed time variables

private:
Time mytime; //Time variales
string info; // Infomation string
string myDriver;
//double averageOrderTime(Time myTime);
string myDriver; //Current driver
Time timeDeparted; // Time for departed
};

Order::Order(){
info = "";
myDriver = "";
}

Order::Order(Time TheTime, string myInfo){
mytime = TheTime;
info = myInfo;
}

// Sets the time variables
void Order::setTime(int myHour, int myMinute){
    mytime.setTime(myHour, myMinute);
}

//Returns the address, item and quanity
string Order::GetInfo(){
    return info;
}


// Copy Constructor

Order& Order::operator= (Order otherOrder2){
otherOrder2.mytime = mytime;
otherOrder2.info = info;
otherOrder2.myDriver = myDriver;
}

// Prints the time and infomation
void Order::PrintOrder(Order& otherOrder2){
if(otherOrder2.PrintDriver() != ""){
cout << "Driver: " << otherOrder2.PrintDriver() << endl;
}
cout << "Order: " << otherOrder2.GetInfo() << endl;
cout << "Time orderded: " << otherOrder2.mytime << endl;
cout << "Time departed: " <<otherOrder2.timeDeparted << endl;
}


/**
double Order::averageOrderTime(Time myTime) {
    return avgTime;
  }
**/

//Outputs the current driver
string Order::PrintDriver(){
return myDriver;
}

//Sets the current driver
void Order::SetDriver(string NewDriver){
myDriver = NewDriver;
}

void Order::SetTimeDeparted(int myHour, int myMinute){
timeDeparted.setTime(myHour, myMinute);
}

Time Order::getDepartedTime(){
return timeDeparted;
}
#endif
