// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// Modified by Thomas Laughridge to hold HuffNode pointers 11/21/21

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor
heap::heap() : huffHeap_size(0) {
    huffHeap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffNode*> vec) : huffHeap_size(vec.size()) {
    huffHeap = vec;
    huffHeap.push_back(huffHeap[0]);
    huffHeap[0] = NULL;
    for (int i = huffHeap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
    makeEmpty(); // <- necessary?
}

void heap::insert(huffNode* h) {
    // a vector push_back will resize as necessary
    huffHeap.push_back(h);
    // move it up into the right position
    percolateUp(++huffHeap_size);
}

void heap::percolateUp(int hole) {
    huffNode* node = huffHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for (int x = node->frequency; (hole > 1) && (x < huffHeap[hole/2]->frequency); hole /= 2) {
        huffHeap[hole] = huffHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = node;
}

huffNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (huffHeap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffNode* ret = huffHeap[1];
    // move the last inserted position into the root
    huffHeap[1] = huffHeap[huffHeap_size--];
    // make sure the vector knows that there is one less element
    huffHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffNode* node = huffHeap[hole];
    // while there is a left child...
    while (hole*2 <= huffHeap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= huffHeap_size) && (huffHeap[child+1]->frequency < huffHeap[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (node->frequency > huffHeap[child]->frequency) {
            huffHeap[hole] = huffHeap[child]; // move child up
            hole = child; // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    huffHeap[hole] = node;
}

huffNode* heap::findMin() {
    if (huffHeap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return huffHeap[1];
}

unsigned int heap::size() {
    return huffHeap_size;
}

void heap::makeEmpty() {
    huffHeap_size = 0;
    huffHeap.resize(1);
}

bool heap::isEmpty() {
    return huffHeap_size == 0;
}
 
void heap::print() {
    cout << "(" << huffHeap[0] << ") ";
    for (int i = 1; i <= huffHeap_size; i++) {
        cout << huffHeap[i]->value << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

void heap::buildTree() {
    while (size() > 1) {
        huffNode* leftChild = deleteMin();
        huffNode* rightChild = deleteMin();

        huffNode* node = new huffNode();
        node->value = "";
        node->frequency = leftChild->frequency + rightChild->frequency;

        node->left = leftChild;
        node->right = rightChild;

        insert(node);
    }
}