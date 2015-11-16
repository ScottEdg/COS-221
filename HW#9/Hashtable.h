#pragma once
#include <ostream>
#include <string>	
#include <list>				// STL list container
using namespace std;	

const int SIZE = 5001;

class HashTable
{
 public:
	HashTable( );				// POST: empty table is created
	~HashTable ( );				// POST: table is destructed
	bool isPresent(string target);	// PRE: table is not empty 
								// POST: return true if target is in table; else false
	bool empty ( ) const;		// POST: return true if table is empty
	void insert(string word);	// POST: if not found, add word to hash table
	void display (ostream & out);// POST: display words on out
	int clusterLength (int i);	// POST: return the length of cluster i
	int getSize () const;		// POST: return the size of the table

private:
	list<string> h[SIZE];       // array of pointers to STL lists
	int hash (string word);		// POST: return hash index of word
};

