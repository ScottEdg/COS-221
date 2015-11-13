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

	int truck_id = 1; // starting from zero would be kinda weird (truck zero would be interesting)
	bool truck_not_found = true; //hmmmm wonder what this could be?
	for(it_orders = Orders.begin(); it_orders != Orders.end(); it_orders++) {//go through orders one at a time
		for (it_trucks = Trucks.begin(); it_trucks != Trucks.end(); ++it_trucks)//try to find an existing truck
		{
			if (it_trucks->getDestination() == it_orders->getDestination()) { //if a truck exists
				try
				{
					it_trucks->addOrder(*it_orders);//add order to truck
					truck_not_found = false; //oh I got it now!
					if (it_trucks->getNumRefrigerators() == it_trucks->getMaxRefrigerators())
					{ //print out all the details of the truck thats leaving.
						cout << endl << "Truck # " << it_trucks->getTruckID() << " left for " << it_trucks->getDestination();
						cout << " with " << it_trucks->getNumRefrigerators() << " refrigerator(s)" << endl;
						for (int i = 0; i < it_trucks->getContents().size(); i++) {
							cout << "Order: " << it_trucks->getContents()[i].getOrderID();
							cout << "  # of Refrigerators: " << it_trucks->getContents()[i].getRefrigerators() << endl;
						}
						Trucks.erase(it_trucks--); //remove the truck that just left from the list

					}
					break;
				}
				catch (Order o) //else make a new truck and add the order to it
				{
					continue;
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
				cout << endl << "Truck # " << it_trucks->getTruckID() << " left for " << it_trucks->getDestination();
				cout << " with " << it_trucks->getNumRefrigerators() << " refrigerator(s)" << endl;
				for (int i = 0; i < it_trucks->getContents().size(); i++) {//print all the orders in the truck
					cout << "Order: " << it_trucks->getContents()[i].getOrderID();
					cout << "  # of Refrigerators: " << it_trucks->getContents()[i].getRefrigerators() << endl;
				}
				Trucks.erase(it_trucks--); //remove the truck that just left from the list
			}
		}
		truck_not_found = true; //reset for next iteration
	}
	//all trucks have orders, now to send them out
	it_trucks = Trucks.begin();
	while (it_trucks != Trucks.end())
	{
		cout << endl << "Truck # " << it_trucks->getTruckID() << " left for " << it_trucks->getDestination();
		cout << " with " << it_trucks->getNumRefrigerators() << " refrigerator(s)" << endl << endl;
		for (int i = 0; i < it_trucks->getContents().size(); i++) {
			cout << "Order: " << it_trucks->getContents()[i].getOrderID();
			cout << "  # of Refrigerators: " << it_trucks->getContents()[i].getRefrigerators() << endl;
		}
		Trucks.erase(it_trucks++); //remove the truck that just left from the list
	}// hurray I'm done! I deserve a raise don't you think?
	return 0;
}
