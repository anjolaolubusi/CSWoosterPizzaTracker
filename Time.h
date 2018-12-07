#ifndef TIME_H
#define TIME_H

#include <stdexcept>
#include <iostream>
#include <ctime>
using namespace std;
//Group Project: Anjolaoluwa, Chantell, Jack
class Time{
    public:
        Time(); //Constructor. Initalises variables
        Time(int myHour, int myMinute); //Constructor. Sets the hour and minute variables to certain values
        void setTime(int myHour, int myMinute); // Set's the time
        bool isDone(); // Meant to check the elapsed time but as of now it just returns true
        int getHour() const; // Returns the hour of the Time class
        int getMinute() const; // Returns the minute of the Time class
        friend ostream& operator << (ostream& out, const Time& myTime); // Outputs the time
        Time& operator= (Time& otherTime); // Copy Constructor
        int elapsedTime(Time t1, Time t2); //Returns the time difference in minutes

    private:
    int hour;
    int minute;
};

//pre-conditons: None
//post-conditons: the variables, hour and minute, are initalized
Time::Time(){
hour = -1;
minute = -1;
}

//pre-conditions: None
//post-conditons: the variables, hour and minute, have new values
Time::Time(int myHour, int myMinute){
hour = myHour;
minute = myMinute;
}

//pre-condition: 0 <= Hour <= 23 && 0 <= Minute <= 59
//post-condition: hour and minute have new values
void Time::setTime(int myHour, int myMinute){

if(myHour <= 23 && myHour >= 0 && myMinute >= 0 && myMinute <= 59){
hour = myHour;
minute = myMinute;
} else{
cout << "Time is out of bounds" << endl;
}

}


//pre-conditons: None
//post-conditons: returns true
bool Time::isDone(){
return (1+1 == 2);
}

//pre-conditons: None
//post-conditons:Returns the hour
int Time::getHour() const{
return hour;
}

//pre-conditions: none
//post-conditions:Returns the minute
int Time::getMinute() const{
return minute;
}

//pre-conditions: none
//post-conditions: Prints out the time
ostream& operator << (ostream& out, Time& myTime){
if(myTime.getHour() < 10){
    cout << "0" << myTime.getHour() << ":";
} else {
cout << myTime.getHour() << ":";
}

if(myTime.getMinute() < 10){
    cout << "0" << myTime.getMinute();
} else {
    cout << myTime.getMinute();
}

}

//pre-conditions: none
//post-conditions: Copies the data from another Time variable
Time& Time::operator= (Time& otherTime){
    if(&otherTime != this){
    hour = otherTime.hour;
    minute = otherTime.minute;
    }return *this;
}

//pre-conditions: There are two time variables
//post-conditions: Returns the total amount of minutes between the two time variables
int Time::elapsedTime(Time t1, Time t2){
int difHour = abs(t1.getHour() - t2.getHour());
int difMin = abs(t1.getMinute() - t2.getMinute());
return (difHour *60) + difMin;
}

#endif
