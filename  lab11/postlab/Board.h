/**
 * \brief   Header for Board class
 * \author 	Thomas Laughridge
 * 			tcl5tu @virginia.edu
 * \date 	12/1/21
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <array>
#include <vector>

using namespace std;

class Board {
public:
    int dist;

    string arr;
    string goal = "123456780";

    Board(vector<string> vec);
    void swap(int a, int b);
    int findHole();
    string toString();
    void print();
    bool compare();
};

#endif