/*
Scott Edgerly
Assignment #5
This code uses stacks and queues in order to place cars in an alley able to hold up to 5 cars
The code also tells the user when cars arrived and departed and sums up the charges for the day
*/
#include "tqueue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stack>
using namespace std;
struct vehicle_data{
	string license; //license of car
	int time; //time the car arrived
};
int main()
{
	stringstream ss;
	vehicle_data vehicle;
	string dir; //direction
	string time; //used to print formated time
	stack <vehicle_data> alley;
	Queue <vehicle_data> street;
	ifstream fin; //used to get data for lot.txt
	ofstream fout; //sends out to log.txt
	float charge; //how much each car was charged
	int duration; //how long the car stayed in the lost
	float sum_of_charge = 0;
	float sum_of_meter = 0;
	int i; //used in for loops
	int max; //used as a temporary value for the count of a queue
	fout.open("log.txt");
	fin.open("lot.txt");
	do{
		fin>>dir>>vehicle.license>>vehicle.time; //grab all the data from one line

		if(dir == "A" && alley.size() < 5){  //put car in alley if there is space
			street.enqueue(vehicle); //place car in queue for the street
			alley.push(street.getFront()); //place car in alley
			ss<<alley.top().time; //take time car entered alley
			ss>>time; //cast it as a string
			fout<<"Car with license "<< alley.top().license;
			fout<<" parked at " <<time.insert(time.size()-2, ":")<<endl; //place a ":" for formated time
			street.dequeue(); //remove the "extra copy" of the car from the street
		}
	
		else if(dir == "A" && alley.size() == 5){ //if the alley is full
			street.enqueue(vehicle); //same as before
			ss<<street.getFront().time; //take in time car attempted to enter alley
			ss>>time; //cast it as a string
			fout<<"Car with license "<< street.getFront().license;
			fout<<" turned away at " <<time.insert(time.size()-2, ":"); //place a ":" for formated time
			fout<<" - LOT IS FULL"<<endl;
			street.dequeue(); //remove from queue
		}
	
		else if(dir == "D"){ //if a car in the alley is leaving
			max = alley.size(); //alley.count() changes when we pop, thus a temp val is used
			for(i=0; i<max;i++){
	
				if(vehicle.license == alley.top().license){ //the car that is leaving
					duration = vehicle.time - alley.top().time; //calcuate how long its been in alley
					charge = 8.00 * ((duration + 99)/100); //rounds up to the nearest hour
					ss<<vehicle.time; //take int depart time
					ss>>time; //cast it as a string
					fout<<"Car with license "<< alley.top().license;
					fout<<" left at "<<time.insert(time.size()-2, ":"); //place a ":" for formated time
					fout<<" paying $"<<setprecision(2)<<fixed<<charge<<endl;
					sum_of_charge += charge; //update the sum
					alley.pop(); //remove from alley
					break; //we're done here, so leave the for loop
				}

				else{ //keep looking for the car that is leaving
					street.enqueue(alley.top()); //place in the street
					alley.pop(); //remove from alley
					sum_of_meter = sum_of_meter + 0.25;
				}
			}
			
			while(!street.empty())	//put cars back in alley
			{
				alley.push(street.getFront()); //place in alley
				street.dequeue(); //remove from street
			}
		}
		ss.clear(); //clear the sstream to avoid duplicate ":"
	}while(!fin.fail()); //keep going until we reach an error or EoF

	fout<<"Cars remaining in the lot include: ";
	max = alley.size(); //again a temp value
	for(int i=0; i<max;i++){
		fout<<alley.top().license <<" ";
		street.enqueue(alley.top()); //place in street to get the next car
		alley.pop(); //remove from alley
	}
	
	while(!street.empty()){ //put cars back in alley
		alley.push(street.getFront()); //place in alley
		street.dequeue(); //remove from street
	}
	
	fout<<endl;
	fout<<"The sum of charges is $"<<sum_of_charge<<endl;
	fout<<"The sum of meter charges is $"<<sum_of_meter<<endl;
	fin.close();	
	fout<<endl<<"Code written by Scott Edgerly"<<endl;
	fout.close();
	return 0;
}
