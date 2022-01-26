/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/1/21
 */

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int main() {
	int a, b;

	cout << "Enter integer 1: ";
	cin >> a;

	cout << "Enter integer 2: ";
	cin >> b;

	cout << "Product: " << product(a, b) << endl;
	cout << "Power: " << power(a, b) << endl;

	return 0;
}