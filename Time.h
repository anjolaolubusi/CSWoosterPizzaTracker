#ifndef TIME_H
#define TIME_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Time{
    public:
        Time(); //Constructor
        Time(int myHour, int myMinute); //Constructor
        void setTime(int myHour, int myMinute); // Set's the time
        bool isDone(); // Meant to check the elapsed time but as of now it just returns true
        int getHour() const; // Returns the hour of the Time class
        int getMinute(); // Returns the minute of the Time class
        friend ostream& operator << (ostream& out, const Time& myTime);

    private:
    int hour;
    int minute;
};

Time::Time(){
hour = 0;
minute = 0;
}

Time::Time(int myHour, int myMinute){
hour = myHour;
minute = myMinute;
}

void Time::setTime(int myHour, int myMinute){
if(myHour >= 0 && myHour <= 23 && myMinute >= 0 && myMinute <= 59){
hour = myHour;
minute = myMinute;
} else {
cout << "Time is out of bounds" << endl;
}
}

bool Time::isDone(){
return (1+1 == 2);
}

int Time::getHour() const{
return hour;
}

int Time::getMinute(){
return minute;
}

ostream& operator << (ostream& out, Time& myTime){
cout << "Hour " << myTime.getHour() << " Minute " << myTime.getMinute() << endl;
}

#endif
