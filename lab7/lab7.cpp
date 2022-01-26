#include <iostream>

using namespace std;

void addition() {
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;

	int sum = a + b + c;
	cout << sum << endl;

	if (sum == 0) {
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
	else {
		addition();
	}
}

void arrays() {
	int size;
	cin >> size;
	int arr[size];

	for (int i = 0; i < size; i++) {
		int input;
		cin >> input;
		arr[i] = input;
	}

	for (int j = 0; j < size; j++) {
		cout << arr[j] << endl;
	}

	for (int k = size-1; k >= 0; k--) {
		cout << arr[k] << endl;
	}
}

int main() {
	arrays();
	return 0;
}