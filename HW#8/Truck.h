#pragma once
#include <string>
#include <vector>
#include "Order.h"
using namespace std;

const int MAXNUMBER = 10;			// maximum number of refrigerators that fit on a truck
class Truck
{
public:
	Truck( );						// POST: empty truck
	Truck (int id, string city);	// POST: truck set with id and city
	~Truck(void);					// POST: destructor

	// accessors
	int getTruckID ( ) const;
	string getDestination ( ) const;
	vector<Order> getContents ( ) const;
	int getNumRefrigerators ( ) const;
	int getMaxRefrigerators ( ) const;
	
	// modifiers
	void setTruckID (int id);
	void setDestination (string city);
	
	void addOrder (Order o);		// PRE: order fits on truck, throws Order Exception if order does not fit
									// POST: add order to truck contents

	bool empty ( ) const;			// POST: return true if truck is empty
	bool full ( ) const;			// POST: return true if truck is full


private: 
	 int truckID;					// truck identification number
	 string destination;			// destination city
	 vector <Order> contents;		// refrigerator orders stored on truck
	 int numRefrigerators;			// number of refrigerators currently on truck
};


