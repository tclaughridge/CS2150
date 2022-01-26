/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/9/21
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
#include "stackNode.h"
using namespace std;

class postfixCalculator {
public:
    postfixCalculator();

    void readElements(string input);

    int result();

    stack stack;

private:
    // empty
};

#endif
