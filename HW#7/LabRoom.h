#pragma once
#include "Room.h"

class LabRoom :	public Room
{
public:
	LabRoom();											// POST: empty lab room with capacity 0, no computer type, no schedule
	LabRoom (string s, int n, string c);				// PRE: n > 0
														// POST: lab room with name s, computer type c, and capacity n, no schedule
	~LabRoom();											// POST: destructor
	
	string getComputer() const;						// return computer type
	void setComputer (string c);						// PRE: c is PC or mac
														// POST: computer type set to c
	string toString () const;							// POST: return name, capacity, schedule, computer type
														//       as blank separated string
private:
	string computer;									// computer type: PC or Mac
};

