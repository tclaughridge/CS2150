/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 10/13/21
 */

// INITIALIZATION
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <iterator>
#include <vector>

#include "timer.h"
#include "hashTable.h"

using namespace std;

// DECLARATIONS
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

float loadFactor = 0.75;

int rows, cols;
int wordCount = 0;
string direction[8] = {"N ", "NE", "E ", "SE", "S ", "SW", "W ", "NW"};

// FORWARD DECLARATIONS
int size(string filename);

bool read(string filename, hashTable& table);

bool readInGrid(string filename, int& rows, int& cols);

string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);

bool checkprime(unsigned int p);

int getNextPrime (unsigned int n);

// MAIN
int main(int argc, char **argv) {

    // GET SIZE AND DEFINE HASH TABLE

    // size(argv[1]) / SIZE = load factor
    // load factor * ARRAY SIZE = dict size
    // ARRAY SIZE = dict size / load factor
    int s = getNextPrime(size(argv[1]) / loadFactor);
    hashTable table(s);


    // READ IN DICTIONARY
    bool r1 = read(argv[1], table);
    if (!r1) {
        cout << "Error reading in Dictionary!" << endl;
        return 1;
    }

    // READ IN GRID
    bool r2 = readInGrid(argv[2], rows, cols);
    if (!r2) {
        cout << "Error reading in Grid!" << endl;
        return 1;
    }

    // FIND WORDS IN GRID
    timer t;

    t.start();
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            for (int d = 0; d < 8; d++) {
                for (int l = 3; l < 22; l++) {
                    string word = getWordInGrid(x, y, d, l, rows, cols);
                    if (table.find(word)) {
                        wordCount += 1;
                        cout << direction[d] << "(" << x << ", " << y << "):        " << word << endl;
                    }
                    if (getWordInGrid(x, y, d, l+1, rows, cols) == word) {
                        break;
                    }
                }
            }
        }
    }
    t.stop();

    cout << wordCount << " words found" << endl;
    cout << "Process completed in " << t.getTime() << " seconds" << endl;

    return 0;
}

//FUNCTIONS

int size(string filename) {
    fstream file1;
    string word;
    int count = 0;

    file1.open(filename.c_str());
    while (file1 >> word)
        count++;
    file1.close();
    return count;
}

bool read(string filename, hashTable& table) {
    fstream file;
    string word;

    file.open(filename.c_str());
    if (!file.is_open())
        return false;
    while (file >> word) {
        table.insert(word);
    }
    file.close();
    return true;
}

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            // cout << grid[r][c];
        }
        // cout << endl;
    }
    return true;
}

string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
