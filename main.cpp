
#include <iostream>
#include "Driver.h"
#include "Restaurant.h"
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <string>

//Group Project: Anjolaoluwa, Chantell, Jack

using namespace std;
void login(string driver, Restaurant& aRestaurant) throw (logic_error);

void logout(string driver, Restaurant& aRestaurant) throw (logic_error);

void depart(const Time& time, const string driver, Restaurant& aRestaurant);

void deliver(const Time& time, const string driver, const float tip, Restaurant& arestaurant);

void arrive(const Time& time, const string driver, Restaurant& aRestaurant);

void order(const Time& time, const string info, Restaurant& arestaurant);

void serve(const Time& time, Restaurant& arestaurant);

int Commander(Restaurant myRestaurant);

void print_help();

string driver; //a string to hold the driver's name

int main()
{
    Restaurant Dominios;

    string command;

    string string_time; //a string to hold time

    string info; //a string to hold an order's info

    print_help();
    cout << "\n";
    Commander(Dominios);

}

//Command line function:
/**
The idea is you would input a string and the compiler would scan the string for a command it recongize
**/

//pre-conditon: None
//post-condition: Reads commands and processses them
int Commander(Restaurant myRestaurant){
    string cmd;
    cout << " Command: ";
    getline(cin, cmd);
    int blankspace = cmd.find_first_of(" ");

    if(cmd == "Quit" || cmd == "quit"){
        return 0; //Exits cleanly
    }else if(cmd.substr(0, blankspace) == "login"){
        login(cmd.substr(blankspace+1), myRestaurant); //Grabs the name and shoves it to the login
        driver = cmd.substr(blankspace+1);
        Commander(myRestaurant);
    }else if(cmd.substr(0, blankspace) == "order"){
        if(driver != ""){
        blankspace = cmd.find_first_of(":"); //
        if(blankspace != -1){
            Time timeMan;
            timeMan.setTime(stoi(cmd.substr(blankspace-3, blankspace-1)), stoi(cmd.substr(blankspace+1, blankspace+3)));
            order(timeMan, cmd.substr(blankspace+4), myRestaurant);
            Commander(myRestaurant);
            }else {
            cout << "Please retype your time with a : to separate hours and minutes";
            Commander(myRestaurant);
            }
        } else {
        cout << "Please log in" << endl;
        Commander(myRestaurant);
        }
    }else if(cmd.substr(0, blankspace) == "logout"){
        if(blankspace != -1){
        logout(cmd.substr(blankspace+1), myRestaurant);
        Commander(myRestaurant);
        } else {
        cout << "Please put the user's name after the logout" << endl;
        }
    }else if(cmd.substr(0, blankspace) == "serve"){
        Time timeMan;
        blankspace = cmd.find_first_of(":");
        if(blankspace != -1){
            timeMan.setTime(stoi(cmd.substr(blankspace-3, blankspace-1)), stoi(cmd.substr(blankspace+1, blankspace+3)));
            serve(timeMan, myRestaurant);
            Commander(myRestaurant);
        }else {
            cout << "Please retype your time with a : to separate hours and minutes";
            Commander(myRestaurant);
            }
    }else if(cmd.substr(0, blankspace) == "depart"){
    if(driver != ""){
        blankspace = cmd.find_first_of(":"); //
        if(blankspace != -1){
            Time timeMan;
            timeMan.setTime(stoi(cmd.substr(blankspace-3, blankspace-1)), stoi(cmd.substr(blankspace+1, blankspace+3)));
            depart(timeMan, cmd.substr(blankspace+4), myRestaurant);
            Commander(myRestaurant);
        }else {
            cout << "Please retype your time with a : to separate hours and minutes";
            Commander(myRestaurant);
            }
        } else {
        cout << "Please log in" << endl;
        Commander(myRestaurant);
        }
    }else if(cmd.substr(0, blankspace) == "deliver"){
        if(driver != ""){
        blankspace = cmd.find_first_of(":"); //
        if(blankspace != -1){
            Time timeMan;
            timeMan.setTime(stoi(cmd.substr(blankspace-3, blankspace-1)), stoi(cmd.substr(blankspace+1, blankspace+3)));
            float myTip = stof(cmd.substr(cmd.rfind(" ")+1));
            cmd = cmd.substr(blankspace);
            blankspace = cmd.find(" ");
            string NewDriver = cmd.substr(blankspace+1, cmd.rfind(" ")-3);
            deliver(timeMan, NewDriver, myTip, myRestaurant);
            Commander(myRestaurant);
        }else {
            cout << "Please retype your time with a : to separate hours and minutes";
            Commander(myRestaurant);
            }
        } else {
        cout << "Please log in" << endl;
        Commander(myRestaurant);
        }
    }else if(cmd.substr(0, blankspace) == "arrive"){
        if(driver != ""){
        blankspace = cmd.find_first_of(":"); //
        if(blankspace != -1){
            Time timeMan;
            timeMan.setTime(stoi(cmd.substr(blankspace-3, blankspace-1)), stoi(cmd.substr(blankspace+1, blankspace+3)));
            arrive(timeMan, cmd.substr(blankspace+4), myRestaurant);
            Commander(myRestaurant);
         }else {
            cout << "Please retype your time with a : to separate hours and minutes";
            Commander(myRestaurant);
            }
        } else {
        cout << "Please log in" << endl;
        Commander(myRestaurant);
        }
    }else if(cmd.substr(0, blankspace) == "status"){
        if(driver != ""){
        myRestaurant.status();
        Commander(myRestaurant);
        } else {
        cout << "Please log in" << endl;
        Commander(myRestaurant);
        }
    }else if(cmd.substr(0,blankspace) == "summary"){
    myRestaurant.summary();
    Commander(myRestaurant);
    }else{
    Commander(myRestaurant);
    }
}

//pre-condition: Driver is not logged in
//post-condition: Driver is logged in
void login(string driver, Restaurant& arestaurant) throw (logic_error) {
    Driver* DriverPtr =  arestaurant.getDriver(driver);
    if (DriverPtr == nullptr) {

        Driver* aDriver = new Driver(driver);
        arestaurant.addDriver(aDriver);
    }
    else
        cout << "The driver is already logged in";
}

//pre-condition: Driver is logged in
//post-condition: Driver is logged out
void logout(string driver, Restaurant& arestaurant) throw (logic_error){

    Driver* DriverPtr =  arestaurant.getDriver(driver);

    if (DriverPtr == nullptr) {
        cout << "Driver does not exist";
    }
    (*DriverPtr).logout();
}

//pre-condition: Driver is not on delivery and is logged in
//post-condition: Driver is on delivery
void depart(const Time& time, const string driver, Restaurant& arestaurant) {
    Order*departOrder = arestaurant.departNextOrder();
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    DriverPtr->depart(time, *departOrder);
}

//pre-condition: Driver is on delivery and the order has not been delivered. Tip >= 0
//post-condition: Order has been delivered.
void deliver(const Time& time, const string driver, const float tip, Restaurant& arestaurant) {
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    arestaurant.deliver(DriverPtr, time, tip);
}

//pre-condition: Driver is on delivery and the order has been delivered.
//post-condition: Order has been delivered.
void arrive(const Time& time, const string driver, Restaurant& arestaurant) {
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    DriverPtr->arrive(time);
}

// pre-condition: None
// post-condition: Print help.
void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  help : Print help" << endl;
    cout << "  login DRIVER : Driver logs in" << endl;
    cout << "  logout DRIVER : Driver logs out" << endl;
    cout << "  order TIME INFO : Adds new order. Time format: HH:MM" << endl;
    cout << "  serve TIME : Sends order out for delivery. Time format: HH:MM" << endl;
    cout << "  depart TIME DRIVER : Driver departs with next order for delivery. Time format: HH:MM" << endl;
    cout << "  deliver TIME DRIVER TIP : Driver delivers order and receives tip. Time format: HH:MM" << endl;
    cout << "  arrive TIME DRIVER : Driver returns. Time format: HH:MM" << endl;
    cout << "  status : Status of orders and drivers" << endl;
    cout << "  summary : Statistics of all drivers and orders" << endl;
    cout << "  quit : Terminates the program" << endl;
    cout << endl;
    cout << "Would you like to see an test case? (Yes or No)";

    string answer;
    getline(cin, answer);
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    if(answer == "yes"){
        cout << "Command: login a" << endl;
        cout << "Command: order 01:00 large peperoni pizza" << endl;
        cout << "Command: depart Frank 10:36" << endl;
    }
    else if (answer != "no"){

}
}


//pre-conditons: We have a time variable, a string containing infomation, and Restaurant
//post-conditions: We an order that is in a list
void order(const Time& time, const string info, Restaurant& arestaurant)
{
    Order* anOrder = new Order(time,info);
    arestaurant.addOrder(anOrder);
}

//pre-condition: We have a time and a Restaurant
//post-condition: We move an order from one list to another
void serve(const Time& time, Restaurant& arestaurant)
{
    arestaurant.serveNextOrder(time);
}
