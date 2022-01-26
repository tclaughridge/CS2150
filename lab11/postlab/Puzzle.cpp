/**
 * \brief   Sliding-8 Puzzle Solver
 * \author 	Thomas Laughridge
 * 			tcl5tu @virginia.edu
 * \date 	12/1/21
 */

#include <iostream>
#include <array>
#include <vector>
#include <string.h>
#include <queue>
#include <unordered_map>
#include <iterator>
#include "Board.h"

using namespace std;

// FORWARD DECLARATIONS
int bfs(Board b);
vector<Board> generateNeighbors(Board b);

int main() {
    // INPUT
    string in1, in2, in3;
    vector<string> vec;

    cout << "Enter puzzle" << endl;
    getline(cin, in1);
    vec.push_back(in1);
    getline(cin, in2);
    vec.push_back(in2);
    getline(cin, in3);
    vec.push_back(in3);

    // Make sure input is correct
    if (in1.length() != 5 || in2.length() != 5 || in3.length() != 5) {
        cout << "Error, incorrect input" << endl;
        return -1;
    }

    // Make the initial board
    Board b(vec);

    // Run breadth first search on board and print
    cout << "Solving Puzzle" << endl;
    int ret = bfs(b);
    if (ret != -1) {
        cout << ret << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

int bfs(Board b) {
    vector<string> vec;
    unordered_map<string, int> visited;
    queue<Board> q;

    Board curr(vec);
    q.push(b);

    while (!q.empty()) {
        curr = q.front();
        q.pop();
        if (curr.compare()) {
            return curr.dist;
        }
        vector<Board> next = generateNeighbors(curr);
        for (Board i : next) {
            if (visited[i.toString()] != 1) {
                visited[i.toString()] = 1;
                i.dist = curr.dist + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

vector<Board> generateNeighbors(Board b) {
    vector<Board> bVec;
    vector<string> sVec;

    Board n1(sVec);
    Board n2(sVec);
    Board n3(sVec);
    Board n4(sVec);

    n1 = b;
    n2 = b;
    n3 = b;
    n4 = b;

    // TOP LEFT
    if (b.findHole() == 0) {
        n1.swap(1, 0);
        bVec.push_back(n1);

        n2.swap(3, 0);
        bVec.push_back(n2);

        return bVec;
    }

    // TOP MIDDLE
    if (b.findHole() == 1) {
        n1.swap(0, 1);
        bVec.push_back(n1);

        n2.swap(2, 1);
        bVec.push_back(n2);

        n3.swap(4, 1);
        bVec.push_back(n3);

        return bVec;
    }

    // TOP RIGHT
    if (b.findHole() == 2) {
        n1.swap(1, 2);
        bVec.push_back(n1);

        n2.swap(5, 2);
        bVec.push_back(n2);

        return bVec;
    }

    // MIDDLE LEFT
    if (b.findHole() == 3) {
        n1.swap(0, 3);
        bVec.push_back(n1);

        n2.swap(4, 3);
        bVec.push_back(n2);

        n3.swap(6, 3);
        bVec.push_back(n3);

        return bVec;
    }

    // MIDDLE MIDDLE
    if (b.findHole() == 4) {
        n1.swap(1, 4);
        bVec.push_back(n1);

        n2.swap(3, 4);
        bVec.push_back(n2);

        n3.swap(5, 4);
        bVec.push_back(n3);

        n4.swap(7, 4);
        bVec.push_back(n4);

        return bVec;
    }

    // MIDDLE RIGHT
    if (b.findHole() == 5) {
        n1.swap(2, 5);
        bVec.push_back(n1);

        n2.swap(4, 5);
        bVec.push_back(n2);

        n3.swap(8, 5);
        bVec.push_back(n3);

        return bVec;
    }

    // BOTTOM LEFT
    if (b.findHole() == 6) {
        n1.swap(3, 6);
        bVec.push_back(n1);

        n2.swap(7, 6);
        bVec.push_back(n2);

        return bVec;
    }

    // BOTTOM MIDDLE
    if (b.findHole() == 7) {
        n1.swap(4, 7);
        bVec.push_back(n1);

        n2.swap(6, 7);
        bVec.push_back(n2);

        n3.swap(8, 7);
        bVec.push_back(n3);

        return bVec;
    }

    // BOTTOM RIGHT
    if (b.findHole() == 8) {
        n1.swap(5, 8);
        bVec.push_back(n1);

        n2.swap(7, 8);
        bVec.push_back(n2);

        return bVec;
    }

    return bVec;
}