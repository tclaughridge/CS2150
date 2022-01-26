/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/14/21
 */

#include <iostream>
#include <string>
#include "stack.h"
#include "stackNode.h"
using namespace std;

stack::stack() {
    topNode = NULL;
}

stack::~stack() {
    delete topNode;
}

void stack::push(int e) {
    stackNode *newNode = new stackNode();
    newNode->value = e;

    newNode->next = topNode;
    topNode = newNode;
}

void stack::pop() {
    if (!empty()) {
        topNode = topNode->next;
    }
}

int stack::top() const {
    return topNode->value;
}

bool stack::empty() const {
    if (topNode == NULL) {
        return true;
    } else {
        return false;
    }
}
