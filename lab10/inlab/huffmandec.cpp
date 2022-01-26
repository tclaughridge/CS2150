// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.
// Modified by Thomas Laughridge for Huffman decoding 11/22/21

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <iterator>

#include "huffNode.h"

using namespace std;

// FORWARD DECLARATIONS
void insert(huffNode* node, string character, string prefix);
void printTree(huffNode* node);


// main(): we want to use parameters
int main (int argc, char** argv) {

    huffNode* node = new huffNode();
    node->value = "";
    node->frequency = 0;
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    map<string, string> prefixCodes;

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        prefixCodes.insert(pair<string, string>(character, prefix));
        // cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();



    // MAKE TREE
    map<string, string>::iterator itr;
    for (itr = prefixCodes.begin(); itr != prefixCodes.end(); itr++) {
        insert(node, itr->first, itr->second);
    }

    // READ AND PRINT TREE
    huffNode* temp = node;
    for (int i = 0; i <= allbits.length(); i++) {
        if (!temp->left && !temp->right) {
            cout << temp->value;
            temp = node;
        }
        if (allbits[i] == '0') {
            temp = temp->left;
        }
        else if (allbits[i] == '1') {
            temp = temp->right;
        }
    }
    cout << endl;

    return 0;
}

void insert(huffNode* node, string character, string prefix) {
    if (prefix.length() > 1) {
        if (prefix[0] == '0') {
            if (!node->left) {
                huffNode* newNode = new huffNode();
                node->left = newNode;
            }
            insert(node->left, character, prefix.substr(1));
        }
        if (prefix[0] == '1') {
            if (!node->right) {
                huffNode* newNode = new huffNode();
                node->right = newNode;
            }
            insert(node->right, character, prefix.substr(1));
        }
    }
    else if (prefix.length() == 1) {
        huffNode* newNode = new huffNode();
        newNode->value = character;

        if (prefix[0] == '0') {
            node->left = newNode;
        }
        if (prefix[0] == '1') {
            node->right = newNode;
        }
        return;
    }
}

void printTree(huffNode* node) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "{" << node->value << ", " << node->frequency << "}" << " ";
        return;
    }
    if (node->right != NULL) {
        printTree(node->right);
    }
    if(node->left != NULL) {
        printTree(node->left);
    }
}