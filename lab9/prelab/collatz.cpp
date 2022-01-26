/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 11/11/21
 */

#include <iostream>

using namespace std;

int collatz(int x) {
	if (x != 1) {
		if (x % 2 != 0) {
            return 1 + collatz((3*x)+1);			
		}
        return 1 + collatz(x/2);
	}
	return 0;
}

int main() {
	int x, res;

    cout << "Enter a number: ";
    cin >> x;

    cout << "Steps: " << collatz(x) << endl;

    return 0;
}