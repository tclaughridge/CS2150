/**
 * \brief   Board class
 * \author 	Thomas Laughridge
 * 			tcl5tu @virginia.edu
 * \date 	12/1/21
 */

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(vector<string> vec) {
    dist = 0;

    // Make arr
    for (string s : vec) {
        arr += (s[0]);
        arr += (s[2]);
        arr += (s[4]);
    }
}

void Board::swap(int a, int b) {
    std::swap(arr[a], arr[b]);
}

int Board::findHole() {
    for (int i = 0; i < arr.length(); i++) {
        if (arr[i] == '0') {
            return i;
        }
    }
    return 0;
}

string Board::toString() {
    return arr;
}

void Board::print() {
    for (int i = 0; i < arr.size(); i++) {
        if (i == 3 || i == 6) {
            cout << endl;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Board::compare() {
    if (arr == goal) {
        return true;
    }
    return false;
}