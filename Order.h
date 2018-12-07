#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
#include "Time.h"
#include "Driver.h"

using namespace std;
//Group Project: Anjolaoluwa, Chantell, Jack
class Order{
public:
    Order(); //Constructor. Initalises the variables
    ~Order();
    Order(Time myTime, string MyInfo); //Sets the variables to certain values
    void setTime(int myHour, int myMinute);// Sets the time variables
    string GetInfo(); //Returns the address, item and quantity
    void setInfo(string myInfo); // Sets the extra infomation
    Order& operator= (Order otherOrder); // Copy Constructor
    void PrintOrder(Order& otherOrder2); // Prints the time and infomation
   // void setInfo(string myInfo); // Sets the extra infomation
    string PrintDriver(); //Outputs the current driver
    Time getDepartedTime(); //Returns the departed time variables
    void SetTimeDelivered(int myHour, int myMinute); //Sets the hour and the minute of departTime
    Time getDeliverTime(); //Returns the departed time variables
    void depart(Time time, string driverName);
    void SetServeTime(int myHour, int myMinute);

private:
Time mytime; //Time variales
Time servetime;
string info; // Infomation string
//double averageOrderTime(Time myTime);
string myDriver; //Current driver
Time timeDeparted; // Time for departed
Time timeDelivered; // Time for delivery
};

//pre-condition: None
//post: Initalizes all the variables
Order::Order(){
info = "";
myDriver = "";
}

Order::~Order(){

}

//pre-condition: None
//post-condition: Copys data from another order
Order::Order(Time TheTime, string myInfo){
mytime = TheTime;
info = myInfo;
}

//pre-condition: 0 <= Hour < 24 and 0<= Minute < 60
//post-condition: myTime has new values
void Order::setTime(int myHour, int myMinute){
    mytime.setTime(myHour, myMinute);
}

//post-condition: None
//pre-condition: Returns the address and any other infomation
string Order::GetInfo(){
    return info;
}

//Pre-condition: None
//Post-condition: Copies data from another order
Order& Order::operator= (Order otherOrder2){
    if(&otherOrder2 != this){
    mytime = otherOrder2.mytime;
    timeDeparted = otherOrder2.timeDeparted;
    info = otherOrder2.info;
    myDriver = otherOrder2.myDriver;
    }
    return *this;
}

// Pre-condition: None
// Post-condition: Prints out the data of the order
void Order::PrintOrder(Order& otherOrder2){
cout << "Order: " << otherOrder2.GetInfo();
    if(servetime.getHour() != -1 && servetime.getMinute() != -1){
        cout << " Time served: " << servetime;
    } else if(timeDeparted.getHour() != -1 && timeDeparted.getMinute() != -1){
        cout << " Time departed: " << timeDeparted;
    } else if(timeDelivered.getHour() != -1 && timeDelivered.getMinute() != -1){
        cout << "Time delivered: " << timeDelivered;
    }else {
    cout << " Time: " << mytime;
    }
}


/**
double Order::averageOrderTime(Time myTime) {
    return avgTime;
  }
**/

//Pre-condition: None
//Post-condition: Returns the driver's name
string Order::PrintDriver(){
    return myDriver;
}


//Pre-condition: None
//Post-condition: Returns the timeDeparted
Time Order::getDepartedTime(){
return timeDeparted;
}

//Pre-condition: None
//Post-condition: timeDeparted has new values
void Order::SetTimeDelivered(int myHour, int myMinute){
timeDelivered.setTime(myHour, myMinute);
}

//Pre-condition: None
//Post-condition: Returns the timeDelivery
Time Order::getDeliverTime(){
return timeDelivered;
}

//pre-condtion: We have a time, a name of a driver
//post-condition: The order has a departed time and the name of the driver that has departed
void Order::depart(Time time, string driverName){
timeDeparted.setTime(time.getHour(), time.getMinute());
myDriver = driverName;
}

//pre-condtion: We have a number for the hour and the minute
//post-condition: The order has a served time variable
void Order::SetServeTime(int myHour, int myMinute){
servetime.setTime(myHour, myMinute);
}
#endif
