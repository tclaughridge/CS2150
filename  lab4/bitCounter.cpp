/**
 * Thomas Laughridge
 * tcl5tu@virginia.edu
 * 9/21/21
 **/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

int binaryBitCounter(int n) {
	if (n == 0) {
    	return 0;
	} if (n == 1) {
        return 1;
    } else {
    	return binaryBitCounter(floor(n / 2)) + binaryBitCounter(n % 2);
    }
}

int unEncode(char c) {
    if (c >= '0' && c <= '9')
        return (int)(c - '0');
    else
        return (int)(c - 'A' + 10);
}

int reEncode(int n) {
    if (n >= 0 && n <= 9)
        return (char)(n + '0');
    else
        return (char)(n + 'A' - 10);
}

string baseConverter(string n, int start, int end) {
	string result;
	int baseTen = 0;
	int len = n.length();

	for (int i = 0; i < len; i++) {
		baseTen += (unEncode(n[i]) * pow(start, len-i-1));
	}

    while (baseTen > 0) {
        result += reEncode(baseTen % end);
        baseTen /= end;
    }

	for (int k = 0; k < result.length() / 2; k++) {
	    swap(result[k], result[result.length() - k - 1]);
	}

	return result;
}

int main (int argc, char **argv) {
	string n(argv[1]);
	cout << n << " has " << binaryBitCounter(stoi(n)) << " bit(s)" << endl;

	string n1(argv[2]);
	string start(argv[3]);
	string end(argv[4]);
	cout << n1 << " (base " << start << ") = " << baseConverter(n1, stoi(start), stoi(end)) << " (base " << end << ")" << endl;

	return 0;
}