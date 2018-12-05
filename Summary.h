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
    A manager uses this command to view summary statistics on orders and drivers, specifically:
    1	total number of deliveries completed
    1	average time per order (from “order” to “deliver”)
    2	number of deliveries completed by each driver
    3	average time per completed delivery for each driver (from “depart” to “deliver”)
    1	total driving time on completed trips for each driver (from “depart” to “return”)
    4	total tips received by each driver
    5   Statistics should include drivers who have logged out.
    */

    Summary();
    /*
     * This is the constructor for this class. It has no pre or post conditions
     * It only sets the values of all data members to their default values
     */

    void Summary:: deliveryInformation(int deliveries, double tip, string driver,
                                       Time departTime, Time dropOffTime, Time returnTime);
    /*
    * Pre:Requires that a delivery time and arrive time be provided.
     * If the delivery time is 0 or <1, a logic error is thrown
    * Post:Returns the average delivery time for all deliveries made

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageDeliveryTime
    */

    void driverLoginInfo(int delivery, Time );
    /*
    * Pre:
    * Post:

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageDeliveryTime
    */

    void Summary:: overView();//this should go in driver class
    /*
    * Pre:
    * Post:

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageDeliveryTime
    */
    /*
    * Pre:
    * Post:

    * This function returns an double value representing the average delivery time.
    * It does this by manipulating the private variable @averageDeliveryTime
    */


    /*
    * Pre: A given tip amount must be provided. If tip is less than 0 a logic error is thrown
    * Post: Returns a the total value of tips received

    * This function returns an double value representing the total number of tips received.
    * It does this by manipulating the private variable @totalTips
    */

    /**-----------------------------------------------------------------------*/
    void totalAmountMade();
    /*
    * Pre:
    * Post: prints out the total amount of money earned through tips and orders and an average amount earned per delivery

    * This function returns an double value representing the total number of tips received.
    * It does this by manipulating the private variable @totalTips
    */

    void overView();
private:
    int totalDeliveries;
    double totalTips;
    Time avgDeliveryTime;
    Time totalDrivingTime;
    queue loggedIn<string>;//list of drivers and their deliveries
    queue loggedOff<string>;
    vector <list<string>> HashTable;
};

Summary:: summary(){
    totalDeliveries = 0;
    totalTips = 0.0;
    avgDeliveryTime = 0.0;
    totalDrivingTime = 0.0;
    loggedIn<string>;//list of drivers and their deliveries
    loggedOff<string>;
    vector<list<string>> HashTable
    driver = 0;
}



//departTime is then driver left the store, dropOffTime is when they delivered the order,
// and returnTime is when they return to the store
void Summary:: deliveryInformation(int deliveries, double tip, string driver,
                                Time departTime, Time dropOffTime, Time returnTime){

//    1	total number of deliveries completed
//    1	average time per order (from “order” to “deliver”)
//    1	total driving time on completed trips for each driver (from “depart” to “return”)

    //possible structure
    // -------
    // Name | total deliveries | average time per delivery | total driving time | total tips |
    int index;
    int sum = 0;
    int i = 0;
    string :: iterator it = driver.begin();
    if(driver.length() >= 3) {
        while(i < 3) {
            sum = sum + int(*it);
            it++;
            i++;
        }
    }
    else {
        while(i < driver.length()) {
            sum = sum + int(*it);
            it++;
            i++;
        }
    }
    index = sum % tableSize;
    if (){
        add orders to their count
        update average delivery time
        update total time time += (returnTime - arriveTime)
        tips += tips
    }
    else{
        add them to the list
        add to their count
        add orders to their count
        update average delivery time
        update total time time += (returnTime - arriveTime)
        tips += tips
    }

    totalTips += tip;
    totalDrivingTime += (arriveTime - departTime);
    totalDeliveries += deliveries;
    avgDeliveryTime = (dropOffTime - dapartTime) / totalDeliveries;
}

void Summary:: driverLoginInfo(int delivery, Time ){

    if(driver is logged in){
        add to logged in queue
    }
    else{
        add them to looged out queue
    }

}

void Summary:: overView(){
    /*
A manager uses this command to view summary statistics on orders and drivers, specifically:
1	total number of deliveries completed
1	average time per order (from “order” to “deliver”)

    2	number of deliveries completed by each driver
    2	average time per completed delivery for each driver (from “depart” to “deliver”)
    2	total driving time on completed trips for each driver (from “depart” to “return”)
    2	total tips received by each driver
3   Statistics should include drivers who have logged out.
*/

    //this should have a segment that goes through the list of drivers and prints out their order count
    cout << "Over view of restaurant statistics"
            "\nTotal number of deliveries: " << totalDeliveries <<
            "\nAverage delivery time (from departure to drop off): " << avgDeliveryTime <<
            "\n"
            deliveryInformation() <<
}

#endif