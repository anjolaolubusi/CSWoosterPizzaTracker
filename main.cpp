#include <iostream>
#include "Driver.h"

using namespace std;

int Commander(Driver myDriver);


int main()
{
    Driver myDriver;

    Commander(myDriver);
}

//Command line function:
/**
The idea is you would input a string and the compiler would scan the string for a command it recongize
**/
int Commander(Driver myDriver){
    string cmd;
    cout << " Command: ";
    getline(cin, cmd);
    int blankspace = cmd.find_first_of(" ");

    if(cmd == "Quit" || cmd == "quit"){
        return 0; //Exits cleanly
    }else if(cmd.substr(0, blankspace) == "order"){
        blankspace = cmd.find_first_of(":"); // Gets the index of the colon
        int myHour = stoi(cmd.substr(blankspace-3, blankspace-1)); //Gets the value of the hour
        int myMinute = stoi(cmd.substr(blankspace+1, blankspace+3)); //Gets the value of the minute
        myDriver.CreateOrder(myHour, myMinute, cmd.substr(blankspace+4)); //Creates an Ordr object with the specified Info, hour and minute
        Commander(myDriver);
    } else{
    Commander(myDriver);
    }
}
