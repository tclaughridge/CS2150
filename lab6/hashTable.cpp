/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 10/13/21
 */

#include "hashTable.h"

using namespace std;

hashTable::hashTable(int i) {
    SIZE = i;

    list<string> l;
    for (int i = 0; i < SIZE; i++) {
        table.push_back(l);
    }
}

unsigned int hashTable::hash(string s) {
    // Hash function found online
    char* charArray = &(s[0]);
    unsigned long hash = 5381;
    int c;
    while ((c = *charArray++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return (unsigned int)(hash % SIZE);
}

void hashTable::insert(string s) {
    if (s.size() >= 3) 
        table[hash(s)].push_back(s);
}

bool hashTable::find(string s) {
    list<string>::iterator itr = table[hash(s)].begin();
    while (itr != table[hash(s)].end() && *itr != s) {
        itr++;
    }
    if(*itr == s) {
        return true;
    }
    return false;
}
