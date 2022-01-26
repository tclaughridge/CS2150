/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/18/21
 */

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
#include <string>

using namespace std;

class huffNode {
public:
    huffNode();

    string value;
    unsigned int frequency;
    huffNode* left;
    huffNode* right;
};

#endif