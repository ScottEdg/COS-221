/*
Scott Edgerly
Assg #3
This code calculates how many shipping boxes are needed (given predetermined box sizes)
and then calculates the cost of packing material if any is needed.
*/

//This File: Main.cpp
#include "Box.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	int l,w,h,boxes,temp;
	Box b1(16,12,4); //initalize Box 1
	Box b2(24,16,8); //intialize Box 2
	int shipboxes,fit1, fit2, empty;
	double cost;
	bool full;
	Box sgb; //Snow Globe Box
//	ofstream cout;

	//cout.open("orders.txt");
	do{ //initial read
	cout<<"Enter number of snow globes to ship (0 to quit):  ";
	cin>>boxes;
	if(boxes<0){ //ensure user is entering valid data
		cout<<"Error: Please enter a non negative integer value"<<endl;
	}
	}while(boxes<0); //keep getting user from data until valid data is entered
	
	while(boxes != 0){ //keep the program running until user enters 0
		do{	
		cout<<"Enter length, width and height of snow globe container:  ";
		cin>>l>>w>>h;
		cout<<endl;
		if(l<1 || w<1 || h<1){
			cout<<"Error: Please enter a value greater than 0!";
		}
		}while(l<1 || w<1 || h<1);

		sgb.setDim(l,h,w); //store the valid values in the snow globe object
		
		cout<<"Number of snow globes:  "<<boxes<<endl;
		cout<<"Dimensions of snow globe box (L x W x H):  "<<l<<" x "<<w<<" x "<<h<<endl;
		
		//code to determine how many snow globe boxes that fit in either shipping boxes
		fit1 = (b1.getL() / sgb.getL()) * (b1.getW() / sgb.getW()) * (b1.getH() / sgb.getH());
		fit2 = (b2.getL() / sgb.getL()) * (b2.getW() / sgb.getW()) * (b2.getH() / sgb.getH());
		cout<<"Number that fit in Ship Box 1:  "<<fit1<<endl;
		cout<<"Number that fit in Ship Box 2:  "<<fit2<<endl;
		cout<<endl;
		
		if(fit1 > 0){ //print box 1's info
			cout<<"Ship Box 1:"<<endl;
			shipboxes = (boxes+fit1-1)/fit1;
			cout<<"Number of Ship Boxes Needed: "<<shipboxes<<endl; 
			full = boxes%fit1;
			cout<<"Partial Box Used: "<<boolalpha<<full<<endl;
			empty = (shipboxes * b1.getVolume()) - (boxes * sgb.getVolume());
			if(empty != 0){ //calculate the remaining volume that needs packing material
				cost = empty * 0.0023;
				cout<<"Packing cost for Partial box: $"<<setprecision(2)<<fixed<<cost<<endl;
			}
			cout<<endl;
		}
		
		if(fit2 > 0){ //print box 2's info
			cout<<"Ship Box 2:"<<endl;
			shipboxes = (boxes+fit2-1)/fit2;
			cout<<"Number of Ship Boxes Needed: "<<shipboxes<<endl;
			full = boxes%fit2;
			cout<<"Partial Box Used: "<<boolalpha<<full<<endl;
			empty = (shipboxes * b2.getVolume()) - (boxes * sgb.getVolume());
			if(empty != 0){ //calculate the remaining volume that needs packing material
				cost = empty * 0.0023;
				cout<<"Packing cost for Partial box: $"<<setprecision(2)<<fixed<<cost<<endl;
			}
		}
		if(fit1 == 0 && fit2 == 0){ //both Box 1 and Box 2 won't work
			cout<<"No shipping box is available!"<<endl;
		}

		cout<<string(75,'-')<<endl<<endl; //print '-' to show the end of the order

	do{ //get the next order
	cout<<"Enter number of snow globes to ship (0 to quit):  ";
	cin>>boxes;
	if(boxes<0){
		cout<<"Error: Please enter a non negative integer value"<<endl;
	}
	}while(boxes<0);
	
	}
	//cout.close();
	return 0;
}
