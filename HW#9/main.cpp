/*
Scott Edgerly
Assg #9
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
	for (int i = 0; i < Table.getSize(); i++) {
		if (Table.clusterLength(i) > 1) {
			cout << "index " << i << "  " << Table.clusterLength(i) << endl;
		}
	}
	cout << Table.getSize();
	return 0;
}