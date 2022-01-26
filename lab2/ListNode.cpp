/* 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 1/3/21
 */

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

ListNode::ListNode() {
    value = 0;
    next = NULL;
    previous = NULL;
}


