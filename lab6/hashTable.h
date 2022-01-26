/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 10/13/21
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <math.h>
#include <iterator>

using namespace std;

class hashTable {
public:
	hashTable(int i);

	unsigned int hash(string s);

	void insert(string s);

	bool find(string s);

	vector<list<string> > table;

private:
	int SIZE;
};

#endif