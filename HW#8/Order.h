#pragma once
#include <string>
using namespace std;

class Order
{
public:
	Order( );								// POST: empty order
	Order (int id, string city, int num);	// PRE: 0 < num <= 10, throws Order exception
											// POST: order with id, city, num set
	~Order( );								// POST: destructor

	// accessors
	int getOrderID ( ) const;			
	string getDestination ( ) const;
	int getRefrigerators ( ) const;

	// modifiers
	void setOrderID (int id);
	void setDestination (string city);
	void setRefrigerators (int num);		// PRE: 0 < num <= 10, throws Order exception

private:
	int orderID;			// order identification
	string destination;		// destination city
	int refrigerators;		// number of refrigerators in order
};

