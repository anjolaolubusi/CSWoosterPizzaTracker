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
    int blackspace = cmd.find_first_of(" ");

    if(cmd == "Quit" || cmd == "quit"){
        return 0; //Exits cleanly
    }else if(cmd == "Time" || cmd=="time"){

        Commander(myDriver); //Returns to command line
    }else if(cmd.substr(0, blackspace) == "order "){
        blackspace = cmd.find_first_of(":"); //
        Time timeMan;
        timeMan.setTime(stoi(cmd.substr(blackspace-3, blackspace-1)), stoi(cmd.substr(blackspace+1, blackspace+3)));
        myDriver.CreateOrder(timeMan," Test");
        Commander(myDriver);
    } else if(cmd == "print order"){
    Commander(myDriver);
    }else{
    Commander(myDriver);
    }
}
