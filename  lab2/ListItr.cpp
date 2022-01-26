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

ListItr::ListItr() {
    current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
    current = theNode; 
}

bool ListItr::isPastEnd() const {
    if (current->next == NULL) {
        return true;
    } else {
        return false;
    }
}

bool ListItr::isPastBeginning() const {
        if (current->previous == NULL) {
        return true;
    } else {
        return false;
    }
}

void ListItr::moveForward() {
    if (!isPastEnd()) {
        current = current->next;
    }
}

void ListItr::moveBackward() {
    if (!isPastBeginning()) {
        current = current->previous;
    }
}

int ListItr::retrieve() const {
    return current->value;
}
