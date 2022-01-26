/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/29/21
 */

#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <iterator>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Graph { 
    int* matrix[][];
    int size;
public:
    Graph(int size);
    stack<string> topSort();
    void addEdge(string v, string w);
    void print();
};