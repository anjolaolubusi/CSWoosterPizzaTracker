
#include <iostream>
#include "Driver.h"
#include "Restaurant.h"

using namespace std;
void login(string driver, Restaurant& aRestaurant) throw (logic_error);

void logout(string driver, Restaurant& aRestaurant) throw (logic_error);

void depart(const Time& time, const string driver, Restaurant& aRestaurant);

void deliver(const Time& time, const string driver, const float tip, Restaurant& arestaurant);

void arrive(const Time& time, const string driver, Restaurant& aRestaurant);

void print_help();


int main()
{
    Restaurant Dominios;

    string command;

    string driver; //a string to hold the driver's name

    string string_time; //a string to hold time

    string info; //a string to hold an order's info

    Driver myDriver;

    Commander(myDriver);

    print_help();
    cin >> command;


    while (command != "quit") {

        //Handles input and calls the corresponding function
        if (command == "help") {
            print_help();
        }
        else if (command == "login")
        {
            cin >> driver;
            login(driver, Dominios);
        }

        else if (command == "logout")
        {
            cin >> driver;
            logout(driver, Dominios);
        }

        else if (command == "order")
        {
            cin >> string_time;
            getline(cin, info);
            Time time(string_time);
            order(time, info, Dominios);
        }

        else if (command == "serve")
        {
            cin >> string_time;
            Time time(string_time);
            serve(time, Dominios);
        }

        else if (command == "depart")
        {
            cin >> string_time;
            Time time(string_time);
            cin >> driver;
            depart(time, driver, Dominios);
        }

        else if (command == "deliver")
        {
            cin >> string_time;
            Time time(string_time);
            cin >> driver;
            float tip;
            cin >> tip;
            deliver(time, driver, tip, Dominios);
        }

        else if (command == "arrive")
        {
            cin >> string_time;
            Time time(string_time);
            cin >> driver;
            arrive(time, driver, Dominios);
        }

        else if (command == "status")
            status(Dominios);

        else if (command == "summary")
            summary(Dominios);

        else
            cout << "Not a valid command" << endl;

        cin >> command;
    }

    return 0;
}

//Command line function:
/**
The idea is you would input a string and the compiler would scan the string for a command it recongize
**/

void login(string driver, Restaurant& arestaurant) throw (logic_error) {
    Driver* DriverPtr =  arestaurant.getDriver(driver);
    if (DriverPtr == nullptr) {

        Driver* aDriver = new Driver(driver);
        arestaurant.addDriver(aDriver);
    }
    else
        throw logic_error("The driver is already logged in");
}


void logout(string driver, Restaurant& arestaurant) throw (logic_error){

    Driver* DriverPtr =  arestaurant.getDriver(driver);

    if (DriverPtr == nullptr) {
        throw logic_error("Driver does not exist");
    }
    (*DriverPtr).logout();
}
void depart(const Time& time, const string driver, Restaurant& arestaurant) {
    Order*departOrder = arestaurant.departNextOrder();
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    DriverPtr->depart(time, *departOrder);
}

void deliver(const Time& time, const string driver, const float tip, Restaurant& arestaurant) {
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    arestaurant.deliver(DriverPtr, time, tip);
}

void arrive(const Time& time, const string driver, Restaurant& arestaurant) {
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    DriverPtr->arrive(time);

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
    }

    void order(const Time& time, const string info, Restaurant& arestaurant)
    {
        Order* anOrder = new Order(time,info);
        arestaurant.addOrder(anOrder);
    }

    void serve(const Time& time, Restaurant& arestaurant)
    {
        arestaurant.serveNextOrder();
    }