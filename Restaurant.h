//
//  restaurant.h
//  Pizza_Delivery_CS120

#ifndef restaurant_h
#define restaurant_h

#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <string>
#include "Order.h"
#include "Driver.h"
#include "Time.h"


class Restaurant

{
public:
    Restaurant();

    void status() const;

    void summary() const;

    void addOrder(Order* order);

    void serveNextOrder() throw (logic_error);

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

void Restaurant::status() const
//pre-condition:
//post-condition:
{

}

void Restaurant::summary() const
//pre-condition:
//post-condition
{

}

void Restaurant::addOrder(Order* order)
//pre-condition: none
//post-condition: enqueues order for cooking.
{
    order_queue.push_back(order); //adds order to cooking queue
}

void Restaurant::serveNextOrder() throw (logic_error)
//pre-condition: the cooking queue is not empty.
//post-condition: dequeues oldest order from the cooking queue and enqueues it for departure.

{
    if (order_queue.size() == 0)
        throw logic_error("No uncooked order");

    delivery_queue.push_back(order_queue.front()); //adds next order to delivery queue
    order_queue.pop_front();
}

Order* Restaurant::departNextOrder() throw (logic_error)
//pre-condition: the departure queue is not empty.
//post-condition: removes the oldest order from the departure queue and returns it
{
    if (delivery_queue.size() == 0)
        throw logic_error("No order to be delivered");

    Order* departing_order = delivery_queue.front();
    delivery_queue.pop_front();

    return departing_order;
}

void Restaurant::deliver(Driver* driver, const Time time, const float tip)
//pre-condition: none
//post-condition: the order carried by the driver is delivered at the given time. The driver receives the given tip.
{

    (*driver).deliver(time, tip);
    totalOrders++;
    Time tempTime(0, 0);
    totalOrderTime += tempTime.elapsedTime(tempTime, (*driver).getOrder().getDeliverTime());

}

float Restaurant::averageOrderTime() const
// pre-condition: none
// post-condition: return average time per order. return N/A if there is no delivered order.
{
    float average_time = (totalOrders != 0) ? (totalOrderTime / totalOrders) : 0; //calculates the average time per order, 0 if there is no order

    return average_time;
}

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

void Restaurant::addDriver(Driver* driver) throw (logic_error)
{
    if (getDriver((*driver).getName()) != nullptr)
        throw logic_error("Driver with this name already exists");

    driver_list.push_back(driver); //adds driver to driver list
}

#endif /* restaurant_h */