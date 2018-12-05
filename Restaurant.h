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
#include "driver.h"
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
    totalOrderTime += (*driver).getOrder().Order::deliveryTime();
    
}

float Restaurant::averageOrderTime() const
// pre-condition: none
// post-condition: return average time per order. return N/A if there is no delivered order.
{
    float average_time = (totalOrders != 0) ? (totalOrderTime / totalOrders) : 0; //calculates the average time per order, 0 if there is no order
    
    return average_time;
}

#endif /* restaurant_h */
