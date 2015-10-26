#include "Room.h"

Room::Room()										// POST: room with no name, capacity 0, no designated course
{	capacity = 0;									// Note: string default constructor automatically called here
}

Room::Room(string s, int c)							// PRE: c > 0
{	name = s;										// POST: room with name s and capacity c, no designated course
	capacity = c;	
}

Room::~Room()										// POST: destructor
{                                                   
}
		
// accessors
string Room::getName ( ) const						
{	return name;
}

int Room::getCapacity ( ) const						
{	return capacity;
}

string Room::getCourseName ( ) const			
{	return courseName;
}

// modifiers
void Room::setName (string s)						
{	name = s;
}

void Room::setCapacity (int c)						// PRE: c > 0
{	capacity = c;
}

void Room::setCourseName (string s)					
{	courseName = s;
}

string Room::toString ( ) const						// POST: return name, capacity, course as blank separated string
{	stringstream ss;
	if (capacity < 100)
		ss << name << "  " << capacity << "  " << courseName << "  ";
	else
		ss << name << "  " << capacity << " " << courseName << "  ";
	return ss.str( );								
}
