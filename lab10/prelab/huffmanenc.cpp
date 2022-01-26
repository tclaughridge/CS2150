/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/18/21
 */

#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <algorithm>

#include "huffNode.h"
#include "heap.h"

using namespace std;

// FORWARD DECLARATIONS
void printTree(huffNode* node);
void generatePrefixes(map<string, string>& inMap, huffNode* node, string str);
string encode(map<string, string>& inMap, string str);

int main(int argc, char** argv) {

    int total_count = 0, distinct_count;

    map<char, int> charMap;
    map<string, string> prefixMap;
    string charStream;
    heap huffTree;

    // READ IN FILE AND STORE CHARACTER FREQUENCY
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Error reading in file!" << endl;
        return 1;
    }
    char g;
    while (file.get(g)) {
        if (isprint(g)) {
            map<char, int>::iterator itr = charMap.find(g);
            if (itr != charMap.end()) {
                charMap[g]++;
            }
            charMap.insert(pair<char, int>(g, 1));
            charStream += g;
            total_count++;
        }
    }
    file.close();

    // STORE CHARACTERS AND FREQUENCIES IN HEAP
    map<char, int>::iterator itr;
    for (itr = charMap.begin(); itr != charMap.end(); itr++) {
        huffNode* node = new huffNode();

        node->value = itr->first;
        node->frequency = itr->second;

        // push HuffNode onto heap here...
        huffTree.insert(node);
    }

    // BUILD TREE FROM HEAP
    huffTree.buildTree();

    // GENERATE PREFIX CODES
    string str = "";
    generatePrefixes(prefixMap, huffTree.findMin(), str);

    // ENCODE FILE
    string encoded = encode(prefixMap, charStream);

    // PRINTING

    // Print section 1
    distinct_count = prefixMap.size();
    map<string, string>::iterator itr2;
    for (itr2 = prefixMap.begin(); itr2 != prefixMap.end(); itr2++) {
        if (itr2->first == " ") {
            cout << "space " << itr2->second << endl;
        } else {
            cout << itr2->first << " " << itr2->second << endl;
        }
    }
    cout << "----------------------------------------" << endl;

    // Print section 2
    cout << encoded << endl;
    cout << "----------------------------------------" << endl;

    // Print section 3
    cout << "There are a total of " << total_count << " symbols that are encoded." << endl;
    cout << "There are " << distinct_count << " distinct symbols used." << endl;
    cout << "There were " << total_count * 8 << " bits in the original file." << endl;
    encoded.erase(remove(encoded.begin(), encoded.end(), ' '), encoded.end());
    cout << "There were " << encoded.length() << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << 
        ((double)total_count*8) / encoded.length() << "." << endl;
    cout << "The cost of the Huffman Tree is " << 
        ((double)encoded.length() / (total_count)) << " bits per character." << endl;

    return 0;
}

void generatePrefixes(map<string, string>& inMap, huffNode* node, string str) {
    if (node == NULL) {
        return;
    }
    if (node->value != "") {
        inMap[node->value] = str;
    }
    generatePrefixes(inMap, node->left, str + "0");
    generatePrefixes(inMap, node->right, str + "1");
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

string encode(map<string, string>& inMap, string str) {
    string outputStr;
    map<string, string>::iterator itr;
    for (int i = 0; i < str.length(); i++) {
        for (itr = inMap.begin(); itr != inMap.end(); itr++) {
            string s(1, str[i]);
            if (itr->first == s) {
                outputStr += (itr->second + " ");
            }
        }
    }
    return outputStr;
}