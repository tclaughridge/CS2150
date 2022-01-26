/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/9/21
 */

#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "stack.h"
#include "stackNode.h"
using namespace std;

int main() {

    postfixCalculator calc;
    string input;

    while (cin >> input) {
        calc.readElements(input);
    }

    cout << calc.result() << endl;

    return 0;
}