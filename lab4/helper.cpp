#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
	int a = 1;
	unsigned int b = 1;

	float c = 0; // 4

	double d = 0; // 8
	double z = 1;

	char e = 0;

	bool f = true;
	int* g = NULL;
	char* h = NULL;
	double* i = NULL;

	cout << "Size of int: " << sizeof(a) << endl;
	cout << "Size of unsigned int: " << sizeof(b) << endl;
	cout << "Size of float: " << sizeof(c) << endl;
	cout << "Size of double: " << sizeof(d) << endl;
	cout << "Size of char: " << sizeof(e) << endl;
	cout << "Size of bool: " << sizeof(f) << endl;
	cout << "Size of int*: " << sizeof(g) << endl;
	cout << "Size of char*: " << sizeof(h) << endl;
	cout << "Size of double*: " << sizeof(i) << endl;

	return 0;
}