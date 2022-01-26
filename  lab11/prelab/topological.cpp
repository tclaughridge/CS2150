/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/29/21
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "Graph.h"

using namespace std;

int main(int argc, char** argv) {

	if (argc != 2) {
		cout << "Must supply the input file name as the only parameter" << endl;
		return 1;
	}

	ifstream file(argv[1], ifstream::binary);
	if (!file.is_open()) {
		cout << "Unable to open file " << argv[1] << endl;
		return 1;
	}

	string s1, s2;
	string line;
	int count;

	while (!file.eof()) {
		getline(file, line);
		if (line[0] == '0') {
			break;
		}
		count++;
	}
    file.seekg (0, file.beg);

	Graph g(count);

	while (file >> s1 >> s2) {
		if (s1 == "0" && s2 == "0") {
			break;
		}
		g.addEdge(s1, s2);
	}
	file.close();

	g.print();

	return 0;
}