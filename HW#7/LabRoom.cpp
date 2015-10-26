#include "LabRoom.h"

LabRoom::LabRoom()
// POST: empty lab room with capacity 0, no computer type, no schedule
{
	computer = "";
}

LabRoom::LabRoom(string s, int n, string c):Room(s, n)
// PRE: n > 0
{
	computer = c;
}

LabRoom::~LabRoom()
// POST: destructor
{
}

string LabRoom::getComputer() const
// return computer type
{
	return computer;
}

void LabRoom::setComputer(string c)
// PRE: c is PC or mac
{
	computer = c;
}

string LabRoom::toString()const
// POST: return name, capacity, schedule, computer type
//       as blank separated string
{
	return Room::toString()+" "+computer;
	
}
