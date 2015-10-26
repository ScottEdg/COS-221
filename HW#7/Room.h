#pragma once
#include <string>
#include <sstream>
using namespace std;

class Room
{
public:
	Room();								// POST: empty room with no name, capacity 0, no designated courses
	Room(string s, int c);				// PRE: c > 0
										// POST: room with name s and capacity c, no designated courses
	virtual ~Room();					// POST: destructor

	// accessors
	string getName ( ) const;			// POST: return room name
	int getCapacity ( ) const;			// POST: return room capacity
										// POST: return course scheduled at period
	string getCourseName ( ) const;

	// modifiers
	void setName (string s);			// POST: set room name
	void setCapacity (int c);			// PRE: c > 0
										// POST: set room capacity
	void setCourseName (string course);	// POST: set course name

	virtual string toString ( ) const;	// POST: return name, capacity, course as blank separated string

private:
	string name;						// room name (ex. 106NV)
	int capacity;						// number of seats in room
	string courseName;					// name of course scheduled in this room
};

