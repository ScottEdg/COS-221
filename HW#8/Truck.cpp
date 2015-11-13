#include "Truck.h"

Truck::Truck( )					// POST: empty truck
{	truckID = 0;
	numRefrigerators = 0;
}

Truck::Truck (int id, string city)		// POST: empty truck set with id and city
{	truckID = id;
	destination = city;
	numRefrigerators = 0;
}

Truck::~Truck(void)				// POST: destructor
{ }

// accessors
int Truck::getTruckID ( ) const		
{	return truckID;
}

string Truck::getDestination ( ) const
{	return destination;
}

vector<Order> Truck::getContents ( ) const
{	return contents;
}

int Truck::getNumRefrigerators ( ) const
{	return numRefrigerators;
}

int Truck::getMaxRefrigerators ( ) const
{	return MAXNUMBER;
}

// modifiers
void Truck::setTruckID (int id)
{	truckID = id;
}

void Truck::setDestination (string city)
{	destination = city;
}
	
void Truck::addOrder (Order o)			// PRE: order fits on truck, else throw Order exception
{		// POST: add order to truck contents
	int total = numRefrigerators + o.getRefrigerators();
	if (total > 10) throw(o);
	numRefrigerators = total;
	contents.push_back(o);
}

bool Truck::empty ( ) const			// POST: return true if truck is empty
{	return numRefrigerators == 0;
}

bool Truck::full ( ) const			// POST: return true if truck is full
{	return numRefrigerators == MAXNUMBER;
}



