/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/29/21
 */

#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(int size) {
    this->size = size;
    matrix = new int[size][size];
}

stack<string> Graph::topSort() {
    stack<string> output;

    return output;
}

void Graph::addEdge(string v, string w) {

}

void Graph::print() {

}