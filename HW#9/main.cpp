/*
Scott Edgerly
Assg #9
This code uses lists to send out trucks with orders to the correct destination.
*/

//This File: Main.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include "Hashtable.h"
using namespace std;
int main()
{
	ifstream fin;
	string word;
	HashTable Table;
	fin.open("jumbledwords.txt");
	fin >> word;
	while(!fin.fail()){
		Table.insert(word);
		fin >> word;
	}
	fin.close();
	return 0;
}