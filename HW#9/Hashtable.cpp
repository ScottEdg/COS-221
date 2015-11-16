#include <algorithm>			// STL generic algorithms, including find
#include "hashtable.h"
#include <iostream>
using namespace std;

HashTable::HashTable( )			
// POST: an empty table is created
{   		}							

HashTable::~HashTable( )			
// POST: table is destructed
{   		}	

bool HashTable::isPresent(string target) 		// PRE: target is not empty	
{												// POST: return true if target is in table        
	int i = hash(target);					
	if (find (h[i].begin( ), h[i].end( ), target) == h[i].end( ) )
		return false;
	else
		return true;
}

void HashTable::insert(string word)		// POST:	add word to table if not found
{	int i  = hash(word);
	if (find (h[i].begin( ), h[i].end( ), word) == h[i].end( ) )
				h[i].push_front(word);
}

void HashTable::display (ostream & out)// POST: display strings to out
{	
	list<string>::iterator iter;			
	for (int i = 0; i<SIZE; i++)			
	{	if (!h[i].empty())
		{	
			out << "Hash Table index: " << i << "\t";
			iter = h[i].begin();
			while (iter != h[i].end())		
			{	out << *iter << " ";		
				iter++;				
			}
			out << endl;
		}
	}	out << endl;
}

int HashTable::clusterLength (int i)
// POST: return the length of cluster i
{
	return h[i].size();
}

int HashTable::getSize () const		// POST: return the size of the table
{
	return SIZE;
}

int HashTable::hash (string word)	
// POST: the index of entry is returned
{		int sum = 0;
		for (int k = 0; k < word.length(); k++)
			sum = sum + int(word[k]);
		return  sum % SIZE; 
}


/*
int HashTable::hash (string word)
// POST: the index of entry is returned 
{
   int seed = 131; 
   unsigned long hash1 = 0;
   for(int i = 0; i < word.length(); i++)
         hash1 = (hash1 * seed) + word[i];
   return hash1 % SIZE;
}

*/
