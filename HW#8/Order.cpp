#include "Order.h"
#include <iostream>

Order::Order( )								// POST: empty order
{
	orderID = 0;
	refrigerators = 0;
}


Order::Order (int id, string city, int num)	// PRE: 0 < num <= 10, throws string exception
{											// POST: order with id, city, num set
		if (num <= 0 || num > 10) throw num;
		orderID = id;
		destination = city;
		refrigerators = num;		
}

Order::~Order( )							// POST: destructor
{  }

// accessors
int Order::getOrderID ( ) const	
{	return orderID; 
}

string Order::getDestination ( ) const
{	return destination; 
}

int Order::getRefrigerators ( ) const
{	return refrigerators; 
}

// modifiers
void Order::setOrderID (int id)
{	orderID = id;
}

void Order::setDestination (string city)
{	destination = city;
}

void Order::setRefrigerators (int num)		// PRE: 0 < num <= 10, throws num exception
{	
	if (num <= 0 || num > 10) throw num;
	refrigerators = num;
}


