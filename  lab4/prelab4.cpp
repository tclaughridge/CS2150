/**
 * Thomas Laughridge
 * tcl5t@virginia.edu
 * 9/19/21
 **/

#include <iostream>
using namespace std;

void sizeOfTest() {
	int a = 1;
	unsigned int b = 1;
	float c = 1;
	double d = 1.0;
	char e = 'a';
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
}

void overflow() {
	unsigned int maxNumber = 4294967295;
	maxNumber += 1;
	cout << "4294967295 + 1 = " << maxNumber << endl;
}

void outputBinary(unsigned int x) {
	int output[32];
	for (int h = 0; h < 32; h++) {
		output[h] = 0;
	}

    int i = 0;
    while (x > 0) {
        output[i] = x % 2;
        x /= 2;
        i++;
    }

    for (int j = 31; j >= 0; j--) {
    	if ((j+1) % 4 == 0 && j != 31) {
    		cout << " " << output[j];
    	} else {
    		cout << output[j];
    	}
    }
    cout << endl;
}


int main() {

	sizeOfTest();
	overflow();

	int input;
	cin >> input;
	outputBinary(input);

	return 0;
}