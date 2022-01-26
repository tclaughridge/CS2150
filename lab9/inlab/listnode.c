/** 
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/15/21
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
}