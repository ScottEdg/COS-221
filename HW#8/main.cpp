/*
Scott Edgerly
Assg #8
This code uses lists to send out trucks with orders to the correct destination.
*/

//This File: Main.cpp
#include "Order.h"
#include "Truck.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <ostream>
void displayContents(list<Truck>::iterator it);//POST: display contents of a Truck
using namespace std;
int main()
{
	ifstream fin; //read from the txt file
	list<Truck> Trucks; //list of Truck class
	list<Order> Orders; //list of Order class
	int id, num; //for fin
	string city; // ditto
	list<Order>::iterator it_orders; //iterator to traverse orders list
	list<Truck>::iterator it_trucks; // likewise for the truck list
	int truck_id = 1; //keeps track of truck id# 
	bool truck_not_found = true; //used to check if a truck was found

	fin.open("refrigerators.txt");
	
	fin >> id >> city >> num; //get data from txt file
	while (!fin.fail()) {
		try {
			Orders.emplace_back(id, city, num); // add data to the orders list
		}
		catch (int e) { // whoops, this catches somebody else's screw up!
			cout << "OrderID: " << id << " contains invalid number of refridgerators." << endl << endl;
		}
		fin >> id >> city >> num; //get the next line of data

	}
	fin.close();

	for(it_orders = Orders.begin(); it_orders != Orders.end(); it_orders++) {//go through orders one at a time
		for (it_trucks = Trucks.begin(); it_trucks != Trucks.end(); ++it_trucks) {//try to find an existing truck
			if (it_trucks->getDestination() == it_orders->getDestination()) { //if a truck exists
				try{
					it_trucks->addOrder(*it_orders);//add order to truck
					truck_not_found = false;
					if (it_trucks->getNumRefrigerators() == it_trucks->getMaxRefrigerators()) {
					 //print out all the details of the truck thats leaving.
						displayContents(it_trucks); //see function at end of main()
						Trucks.erase(it_trucks--); //remove the truck that just left from the list
					}
					break; //found what we needed so look at next order
				}
				catch (Order o) //else make a new truck and add the order to it
				{
					continue; //keep looking for a truck
				}
			}
		}
		if (truck_not_found) { //if no trucks were found in truck list
			Trucks.emplace_back(truck_id, it_orders->getDestination()); //create new truck
			truck_id++; //increment id
			it_trucks = Trucks.end(); //point to the last truck in the list
			it_trucks--; //now we're actully pointing the last truck
			it_trucks->addOrder(*it_orders); //add the order to the new truck
			if (it_trucks->getNumRefrigerators() == it_trucks->getMaxRefrigerators())
			{ //this prints if an order fills a truck in one go!
				displayContents(it_trucks);//see function at end of main()
				Trucks.erase(it_trucks--); //remove the truck that just left from the list
			}
		}
		truck_not_found = true; //reset for next iteration
	}
	
	//all trucks have orders, now to send them out
	it_trucks = Trucks.begin();
	while (it_trucks != Trucks.end())
	{
		displayContents(it_trucks);//see function at end of main()
		Trucks.erase(it_trucks++); //remove the truck that just left from the list
	}
	cout << endl << endl << "Code written by Scott Edgerly" << endl << endl;
	return 0;
}


void displayContents(list<Truck>::iterator it)
//POST: display contents of a Truck
{
	cout << endl << "Truck # " << it->getTruckID() << " left for " << it->getDestination();
	cout << " with " << it->getNumRefrigerators() << " refrigerator(s)" << endl;
	for (int i = 0; i < it->getContents().size(); i++) {
		cout << "Order: " << it->getContents()[i].getOrderID();
		cout << "  # of Refrigerators: " << it->getContents()[i].getRefrigerators() << endl;
	}
	return;
}