#ifndef SUMMARY_H
#define SUMMARY_H

#include <stdexcept>
#include <iostream>
#include <queue>
#include <stack>
#include "Order.h"
#include "Driver.h"
#include "Status.h"

using namespace std;

class Summary{
public:

    Summary();
    /*
     * This is the constructor for this class. It has no pre or post conditions
     * It only sets the values of all data members to their default values
     */

    int totalDeliveries();
    /*
    * Pre:none
    * Post: This method adds a delivery to the total number of deliveries then returns that number.
    *
    * This function returns an int value representing the total number of deliveries made.
     * It does this using @totalDeliveries
    */

    double avgDeliveryTime(Time deliverTime, Time arriveTime) throw (logic_error);
    /*
    * Pre:Requires that a delivery time and arrive time be provided.
     * If the delivery time is 0 or <1, a logic error is thrown
    * Post:Returns the average delivery time for all deliveries made

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageTime
    */

    int deliveryByDriver()throw (logic_error);
    /*
    * Pre:
    * Post:

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageTime
    */

    double avgDepartToDeliverTime()throw (logic_error);//this should go in driver class
    /*
    * Pre:
    * Post:

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageTime
    */
    double totalDrivingTime()throw (logic_error);//this should go in driver class
    /*
    * Pre:
    * Post:

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageTime
    */
    double totalTips(double tipAmount)throw (logic_error);
    /*
    * Pre: A given tip amount must be provided. If tip is less than 0 a logic error is thrown
    * Post: Returns a the total value of tips received

    * This function returns an double value representing the total number of tips received.
    * It does this by manipulating the private variable @totalTips
    */

private:
    int totalDeliveries;
    double averageTime;
    double totalTips;

};



void Summary:: totalDeliveries(int ){
    totalDeliveries = 0;
    averageTime = 0.0;
    totalTips = 0.0;
}


double Summary:: avgDeliveryTime(int deliveryTime){

}

int Summary:: deliveryByDriver(){

}

double Summary:: avgDepartToDeliverTime(){

}


double Summary:: totalDrivingTime(){

}

double Summary:: totalTips(){

}

#endif