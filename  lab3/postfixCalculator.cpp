/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/9/21
 */

#include <iostream>
#include <string>
#include "stack.h"
#include "stackNode.h"
#include "postfixCalculator.h"
using namespace std;

postfixCalculator::postfixCalculator() {
    // empty
}

void postfixCalculator::readElements(string input) {
    if (input == "+" || input == "-" || input == "*" || input == "/" || input == "~") {

        if (input == "+") {
            int num1 = stack.top();
            if (!stack.empty())
                stack.pop();
            int num2 = stack.top();
            if (!stack.empty())
                stack.pop();
            stack.push(num1 + num2);
        }

        if (input == "-") {
            int num1 = stack.top();
            if (!stack.empty())
                stack.pop();
            int num2 = stack.top();
            if (!stack.empty())
                stack.pop();
            stack.push(num2 - num1);
        }

        if (input == "*") {
            int num1 = stack.top();
            if (!stack.empty())
                stack.pop();
            int num2 = stack.top();
            if (!stack.empty())
                stack.pop();
            stack.push(num1 * num2);
        }

        if (input == "/") {
            int num1 = stack.top();
            if (!stack.empty())
                stack.pop();
            int num2 = stack.top();
            if (!stack.empty())
                stack.pop();
            stack.push(num2 / num1);
        }

        if (input == "~") {
            int num = stack.top();
            if (!stack.empty())
                stack.pop();
            stack.push(-num);
        }
    }
    else {
        stack.push(stoi(input));
    }
}

int postfixCalculator::result() {
    return stack.top();
}
