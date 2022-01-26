/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/18/21
 */

#include <iostream>
#include "huffNode.h"

using namespace std;

huffNode::huffNode() {
    value = "?";
    frequency = 0;
    left = NULL;
    right = NULL;
}