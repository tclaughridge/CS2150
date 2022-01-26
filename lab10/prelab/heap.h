// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// Modified by Thomas Laughridge to hold HuffNode pointers 11/21/21

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffNode.h"

using namespace std;

class heap {
public:
    heap();
    heap(vector<huffNode*> vec);
    ~heap();

    void insert(huffNode* h);
    huffNode* findMin();
    huffNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

    void buildTree();

private:
    vector<huffNode*> huffHeap;
    unsigned int huffHeap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif