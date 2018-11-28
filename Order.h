#ifndef ORDER_H
#define ORDER_H

#include <stdexcept>
#include <iostream>
#include "Time.h"

using namespace std;

class Order{
public:
    Order();
    Order(Time myTime, string MyInfo);
    void setTime(int myHour, int myMinute);
    string GetInfo();
    void setInfo(string myInfo);
    Order& operator= (Order& otherOrder);

private:
Time mytime;
string info;
};

Order::Order(){
mytime.setTime(0, 0);
info = "TEST";
}

Order::Order(Time myTime, string myInfo){
mytime = myTime;
info = myInfo;
}

void Order::setTime(int myHour, int myMinute){
mytime.setTime(myHour, myMinute);
}


string Order::GetInfo(){
return info;
}



Order& Order::operator= (Order& otherOrder2){
otherOrder2.info = info;
}



#endif
