/*
Scott Edgerly
Assignment #5
This code uses stacks and queues in order to place cars in an alley able to hold up to 5 cars
The code also tells the user when cars arrived and departed and sums up the charges for the day
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Room.h"
#include "LabRoom.h"
using namespace std;


int main()
{
	ifstream fin;
	vector<Room *> rooms;
	string name, type, computer;
	int capacity, size, i;
	
	fin.open("neville.txt");
	do{
		
		fin >> name >> capacity >> type;

		if(type == "Lec"){
			rooms.push_back(new Room(name,capacity));
		}
		if(type == "Lab"){
			fin >> computer;
			rooms.push_back(new LabRoom(name,capacity, computer));
		}
		if(fin.eof()){
			break;
		}
	}while(!fin.fail());
	fin.close();
	cout << "Room Scheduler Program by Scott Edgerly" << endl << endl;
	cout << "Rooms in Neville:" << endl;
	for(i = 0; i < rooms.size();i++){
		cout << rooms[i]->toString() << endl;
	}
	
	cout << endl << endl;
	
	fin.open("nevilleSchedule.txt");
	int last_extra = 200;
	int extra;
	int room = -1;
	do{
		fin >> name >> size >> type;
		
		if(type == "Lec"){
			for(i = 0; i < rooms.size();i++){
				if(size < rooms[i]->getCapacity() && rooms[i]->getCourseName() == ""){
					extra = rooms[i]->getCapacity() - size;
					if(extra < last_extra){
						room = i;
					}
				}
				last_extra = extra;
			}
		}
		
		if(type == "Lab"){
			fin >> computer;
			for(i = 0; i < rooms.size();i++){
				if(size < rooms[i]->getCapacity() /*&& dynamic_cast<LabRoom *>(rooms[i])->getComputer() == computer*/ && rooms[i]->getCourseName() == ""){
					extra = rooms[i]->getCapacity() - size;
					if(extra < last_extra){
						room = i;
					}
				}
				last_extra = extra;
			}
		}
			
		if(room == -1){
			cout << name << " with enrollemnt " << size << " could not be scheduled!";
			cout <<"  *** No room is available! ***" << endl;
		}
		if(room != -1){
			rooms[room]->setCourseName(name);
		}
		room = -1;
		last_extra = 200;
		if(fin.eof()){
			break;
		}	
	}while(!fin.fail());

	fin.close();
	
	cout << "Schedule in Neville:" << endl;
	for(i = 0; i < rooms.size();i++){
		cout << rooms[i]->toString() << endl;
	}
}
