/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/14/21
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"
using namespace std;

class stack {
public:
    stack();

    ~stack();

    void push(int e);

    void pop();

    int top() const;

    bool empty() const;

private:
    friend class stackNode;

    stackNode *topNode;
};

#endif