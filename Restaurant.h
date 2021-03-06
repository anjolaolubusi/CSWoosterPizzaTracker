//
//  restaurant.h
//  Pizza_Delivery_CS120

#ifndef restaurant_h
#define restaurant_h
#include <cmath>
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <string>
#include "Order.h"
#include "Driver.h"
#include "Time.h"


class Restaurant
//Group Project: Anjolaoluwa, Chantell, Jack
{
public:
    Restaurant();

    void status();

    void summary() const;

    void addOrder(Order* order);

    void serveNextOrder(Time timeman) throw (logic_error);

    Order* departNextOrder() throw (logic_error);

    void deliver(Driver* driver, const Time time, const float tip);

    Driver* getDriver(const string name) const;

    void addDriver(Driver* driver) throw (logic_error);


private:
    vector<Driver*> driver_list; //vector containing all of the drivers.

    deque<Order*> order_queue;//cooking queue;

    deque<Order*> delivery_queue; //delivery queue;

    int totalOrders; //total orders

    int totalOrderTime; //total time of all orders

     float averageOrderTime() const;//returns the average time for each order

};

Restaurant::Restaurant(): totalOrders(0), totalOrderTime(0)
//pre-condition: none.
//post-condition: creates a restaurant in an initial state, with no drivers or orders
{

}

void Restaurant::status()
//pre-condition:None
//post-condition: Prints out the orders and curhent drivers
// The code by going through the queue and print the orders that statisfy each conditon
{
cout << "Orders waiting to be cooked: " << endl;
for (deque<Order*> CopyOfOrderQueue = order_queue; !CopyOfOrderQueue.empty(); CopyOfOrderQueue.pop_front()){
    cout << "\t";
    CopyOfOrderQueue.front()->PrintOrder(*CopyOfOrderQueue.front());
}

cout << "\n";

cout << "Orders waiting to be delivered: " << endl;
for (deque<Order*> CopyOfOrderQueue = delivery_queue; !CopyOfOrderQueue.empty(); CopyOfOrderQueue.pop_front()){
    cout << "\t";
    CopyOfOrderQueue.front()->PrintOrder(*CopyOfOrderQueue.front());
}

cout << "\n";

cout << "Orders that has been delivered: " << endl;
for (deque<Order*> CopyOfOrderQueue = delivery_queue; !CopyOfOrderQueue.empty(); CopyOfOrderQueue.pop_front()){
    if(CopyOfOrderQueue.front()->getDepartedTime().getHour() != -1 && CopyOfOrderQueue.front()->getDepartedTime().getMinute() != -1){
    cout << "\t";
    CopyOfOrderQueue.front()->PrintOrder(*CopyOfOrderQueue.front());
    }
}

cout << "\n";

cout << "Drivers in the resturant: " << endl;
for (vector<Driver*> CopyOfDriverQueue = driver_list; !CopyOfDriverQueue.empty(); CopyOfDriverQueue.pop_back()){
    if(!CopyOfDriverQueue.back()->isDelivering() && !CopyOfDriverQueue.back()->isDelivering() && CopyOfDriverQueue.back()->loggedIn()){
    cout << "\t";
    cout << CopyOfDriverQueue.back()->getName();
        if(CopyOfDriverQueue.back()-> arrival().getHour() != -1 && CopyOfDriverQueue.back()-> arrival().getMinute() != -1){
            cout << " Time arrived: " << CopyOfDriverQueue.back()-> arrival().getHour() << ":" << CopyOfDriverQueue.back()-> arrival().getMinute();
        }
    }
}


cout << "\n";

cout << "Drivers out for delivery: " << endl;
for (vector<Driver*> CopyOfDriverQueue = driver_list; !CopyOfDriverQueue.empty(); CopyOfDriverQueue.pop_back()){
    if(CopyOfDriverQueue.back()->isDelivering()){
    cout << "\t";
    cout << "Driver: " << CopyOfDriverQueue.back()->getName() << " ";
    Order temp = CopyOfDriverQueue.back()->getOrder();
    temp.PrintOrder(temp);
    }
}

cout << "\n";

}

void Restaurant::summary() const
//pre-condition: none
//post-condition: Prints out a summary of the orders
{
 cout << "This is format driver information is provided in:\n\n"
            "DRIVER NAME | NUMBR OF DELIVERIES | AVERGAE DELIVERY TIME |"
            " TOTAL DRIVING TIME | TOTAL TIPS\n" << endl;
    cout << "The total number of orders completed was " << totalOrders << " orders" << endl;
    int minute2 = averageOrderTime()/60;
        int hour2 = averageOrderTime()/60;
    cout << "Average time per order: " << fixed << setprecision(1) << hour2 << " Hours " << minute2 << " Minutes" << endl;

    //iterates through the driver list and prints out information of each driver
    for (vector<Driver*>::const_iterator driver = driver_list.begin(); driver != driver_list.end(); driver++)
    {
        cout << "Driver: " << (**driver).getName() << " | ";
        cout << "Number of deliveries completed: " << (**driver).getTotalDeliveries() << " | ";
        cout << "Average time per delivery: ";

        if ((**driver).averageDeliveryTime() == 0) // if driver did not make any delivery, print "N/A"
            cout << "N/A" << endl;
        else{
        int minute = remainder((**driver).averageDeliveryTime(), 60);
        int hour = (**driver).averageDeliveryTime()/60;
            cout << fixed << setprecision(1) << hour << " Hours " << minute << " Minutes" << " | ";
        }

        int minute3 = (**driver).getTotalMinDriving()/60;
        int hour3 = (**driver).getTotalMinDriving()/60;
        cout << "Total driving time: " << hour3 << " Hours " << minute3 << " Minutes" << " | ";
        cout << "Total tips: " << fixed << setprecision(2) << (**driver).getTotalTips() << endl;
    }

cout << endl;
}

void Restaurant::addOrder(Order* order)
//pre-condition: none
//post-condition: enqueues order for cooking.
{
    order_queue.push_back(order); //adds order to cooking queue
}

void Restaurant::serveNextOrder(Time timeman) throw (logic_error)
//pre-condition: the cooking queue is not empty.
//post-condition: dequeues oldest order from the cooking queue and enqueues it for departure.

{
    if (order_queue.size() == 0)
        cout << "No uncooked order";

    order_queue.front()->SetServeTime(timeman.getHour(), timeman.getMinute());
    delivery_queue.push_back(order_queue.front()); //adds next order to delivery queue
    order_queue.pop_front();
}

Order* Restaurant::departNextOrder() throw (logic_error)
//pre-condition: the departure queue is not empty.
//post-condition: removes the oldest order from the departure queue and returns it
{
    if (delivery_queue.size() == 0)
        cout << "No order to be delivered";

    Order* departing_order = delivery_queue.front();
    delivery_queue.pop_front();

    return departing_order;
}

void Restaurant::deliver(Driver* driver, const Time time, const float tip)
//pre-condition: none
//post-condition: the order carried by the driver is delivered at the given time. The driver receives the given tip.
{
    this->driver_list.back()->deliver(time, tip);
    totalOrders++;
    Time tempTime;
    tempTime.setTime(0, 0);
    totalOrderTime += tempTime.elapsedTime(tempTime, this->driver_list.back()->getOrder().getDeliverTime()); //Seg-fault here
}

float Restaurant::averageOrderTime() const
// pre-condition: none
// post-condition: return average time per order. return N/A if there is no delivered order.
{
    float average_time = (totalOrders != 0) ? (totalOrderTime / totalOrders) : 0; //calculates the average time per order, 0 if there is no order

    return average_time;
}

//pre-condition: a string has been inputted
//post-condition: returns the driverpointer
Driver* Restaurant::getDriver(const string name) const
{
    vector<Driver*>::const_iterator driver = driver_list.begin();

    Driver* driverPtr = nullptr;
    bool driverExists = false;

    while (!driverExists && driver != driver_list.end()) //iterates through the driver list
    {
        if ((**driver).getName() == name) //checks if a driver with that name already exists in the system
        {
            driverPtr = *driver;
            driverExists = true;
        }
        driver++;
    }

    return driverPtr;
}

//pre-conditon: we have a driver pointer
//post-conditon: the driver gets added to the driver list
void Restaurant::addDriver(Driver* driver) throw (logic_error)
{
    if (getDriver((*driver).getName()) != nullptr)
        cout << "Driver with this name already exists";

    driver_list.push_back(driver); //adds driver to driver list
}

#endif /* restaurant_h */
