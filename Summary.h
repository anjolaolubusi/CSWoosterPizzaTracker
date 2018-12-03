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

    /*
     * -	total number of deliveries completed
        -	average time per order (from “order” to “deliver”)
        -	number of deliveries completed by each driver
        -	average time per completed delivery for each driver (from “depart” to “deliver”)
        -	total driving time on completed trips for each driver (from “depart” to “return”)
        -	total tips received by each driver
    Statistics should include drivers who have logged out.
     */
    /*
     * Pre:
     * Post:
     * This function returns an int value representing the total number of deliveries made.
     */
    Summary();
    int totalDeliveries();
    double avgDeliveryTime();
    int deliveryByDriver();
    double avgDepartToDeliverTime();
    double totalDrivingTime();
    double totalTips();

    void driversLoggedIn();
    void driversLoggedOut();

private:

};

void Summary:: totalDeliveries(int ){

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

void Summary:: driversLoggedIn(){

}

void Summary:: driversLoggedOut(){

}

#endif