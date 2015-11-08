/*
Scott Edgerly
Assignment #7
This code practices the use of using Class inheritance.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Room.h"
#include "LabRoom.h"
#include <typeinfo>
using namespace std;


int main()
{
	ifstream fin;
	vector<Room *> rooms;
	string name, type, computer; //variables for grabbing input from fin
	int capacity, size, i;		//likewise
	
	fin.open("neville.txt");
	do{
		
		fin >> name >> capacity >> type; //get a line from fin

		if(type == "Lec"){
			rooms.push_back(new Room(name,capacity));
		}
		if(type == "Lab"){
			fin >> computer; //one extra read needs to be made
			rooms.push_back(new LabRoom(name,capacity, computer));
		}
		if(fin.eof()){ //break if nothing more to read
			break;
		}
	}while(!fin.fail());
	
	fin.close();
	cout << "Room Scheduler Program by Scott Edgerly" << endl << endl;
	cout << "Rooms in Neville:" << endl;
	for(i = 0; i < rooms.size();i++){
		cout << "Room: " << rooms[i]->toString() << endl;
	}
	
	cout << endl << endl;
	
	fin.open("nevilleSchedule.txt");
	int last_extra = 200;
	int extra; //variables to store the extra amount of seats in a room
	int room = -1; //if variable room is -1 than a room could not be scheduled
	do{
		fin >> name >> size >> type;
		
		if(type == "Lec"){ //assign a room if its big enough and hasn't be assigned already
			for(i = 0; i < rooms.size();i++){ //check 1 at a time from top to botton
				if(size <= rooms[i]->getCapacity() && rooms[i]->getCourseName() == ""){
					extra = rooms[i]->getCapacity() - size;
					if(extra < last_extra){
						room = i; //stores the best fit room
					}
				}
				last_extra = extra; //compare for future iterations
			}
		}
		
		if(type == "Lab"){ //assign a room if its big enough, hasn't be assigned already and is the correct computer lab
	
			fin >> computer;

			for(i = 0; i < rooms.size();i++){
				if(typeid(* rooms[i]).name() == typeid(Room).name()){
					continue;
				}
				if(dynamic_cast<LabRoom *>(rooms[i])->getComputer() == computer){
				if(size <= rooms[i]->getCapacity() && rooms[i]->getCourseName() == ""){
					extra = rooms[i]->getCapacity() - size;
					if(extra < last_extra){
						room = i; //stores the best fit room
					}
				}
				last_extra = extra; //compare for future iterations
			}
			}
		}
		
		if(room == -1){ //if a room couldn't be found
			cout << name << " with enrollemnt " << size << " could not be scheduled!";
			cout <<"  *** No room is available! ***" << endl;
		}
		else{
			rooms[room]->setCourseName(name);
		}
		
		room = -1; //reset variables for the next room to be checked
		last_extra = 200;
		if(fin.eof()){
			break;
		}	
	}while(!fin.fail());

	fin.close();
	
	cout << "Schedule in Neville:" << endl; //print the results
	for(i = 0; i < rooms.size();i++){
		cout << "Room: " << rooms[i]->toString() << endl;
	}
}
