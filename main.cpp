#include <iostream>
#include <string>
#include <algorithm>
#include "Driver.h"
#include "Status.h"
#include "Summary.h"
using namespace std;

int CommandInput(Driver myDriver);
void commands_list();

int main()
{
    Driver myDriver;//This creates a default driver named myDriver
    /**
     Pre Conditions: None
     Post: None

     This method prints out all of the commands available to the user
     It then asks the user if they would like an example of how to enter a command
    */
    commands_list();
    /**
      pre: A string has been entered into the terminal
      post: It calls the method associated to the command entered.

      This method asks the user to enter the command they would lie to use than
      makes a call to the associated method
    */
    CommandInput(myDriver);
}

//Hello there

void commands_list(){
    cout << "Here is the list of commands you can enter:\nLogin <DriverName>"
            "\nLogout <DriverName>\nOrder <Time> <Order Info>\nDepart <Time> <DriverName>"
            "\nDeliver <Time> <DriverName> <tip>\nServe <Time>\nArrive <Time> <DriverName>"
            "\nStatus\nSummary\nHelp\nQuit\n" << endl;
    cout << "Would you like to see examples? Yes or No: ";

    string cmd;
    getline(cin, cmd);
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    if (cmd == "yes"){
        cout << "Here is an example of the ORDER function\n"
                "ORDER TIME QUANTITY TYPE ADDRESS\n"
                "order 9:55 2 veggie to 100 Liberty\n"
                "----------------------------------\n"
                "order 0:02 1 cheese 1 bread sticks "
                "to 123 Holden Hall\n" << endl;
    }
}

//Command line function:
/**
      pre: A string has been entered into the terminal
      post: It calls the method associated to the command entered.

      This method asks the user to enter the command they would lie to use than
      makes a call to the associated method
*/
int CommandInput(Driver myDriver){
    string cmd;
    Time timeMan;
    cout << " Command: ";
    getline(cin, cmd);
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    int blackspace = cmd.find_first_of(" ");

    if (cmd.substr(0,blackspace) == "login"){

        myDriver.login(cmd.substr(blackspace));
        CommandInput(myDriver);
    }
    else if (cmd.substr(0,blackspace) == "logout"){

    }
    else if(cmd.substr(0, blackspace) == "order"){
        if(myDriver.GetCurrentDrivers() != ""){
        blackspace = cmd.find_first_of(":");
        int hour = stoi(cmd.substr(blackspace-3, blackspace-1));
        int minute = stoi(cmd.substr(blackspace+1, blackspace+3));
        myDriver.CreateOrder(hour, minute, cmd.substr(blackspace+4));
        CommandInput(myDriver);
        } else {
        cout << "Please log in" << endl;
        }
    }
    else if (cmd.substr(0,blackspace) == "depart" && myDriver.GetCurrentDrivers() != "") {
    if(myDriver.GetCurrentDrivers() != ""){
        blackspace = cmd.find_first_of(":");
        int hour = stoi(cmd.substr(blackspace-3, blackspace-1));
        int minute = stoi(cmd.substr(blackspace+1, blackspace+3));
        myDriver.depart(hour, minute, cmd.substr(blackspace+4));
        CommandInput(myDriver);
         } else {
        cout << "Please log in" << endl;
        CommandInput(myDriver);
        }
    }
    else if (cmd.substr(0,blackspace) == "deliver") {

    }
    else if (cmd.substr(0,blackspace) == "serve") {

    }
    else if (cmd.substr(0,blackspace) == "arrive") {

    }
    else if (cmd.substr(0,blackspace) == "status") {
        if(myDriver.GetCurrentDrivers() != ""){
        Status currentStatus;
        currentStatus.PrintStatus(myDriver);
        CommandInput(myDriver);
         } else {
        cout << "Please log in" << endl;
        CommandInput(myDriver);
        }
    }
    else if (cmd.substr(0,blackspace) == "summary") {

    }
    else if(cmd == "help"){
        commands_list();
    }
    else if(cmd == "quit"){
        return 0; //Exits cleanly
    }
    else{
        CommandInput(myDriver);
    }
}
