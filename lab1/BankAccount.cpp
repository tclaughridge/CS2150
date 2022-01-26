/*
Thomas Laughridge
tcl5tu@virginia.edu
8/31/21
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount() {
	balance = 0.0;
}

bankAccount::bankAccount(double amount) {
	balance = amount;
}

bankAccount::~bankAccount() {}

double bankAccount::withdraw(double amount) {
	balance -= amount;
	return getBalance();
}

double bankAccount::deposit(double amount) {
	balance += amount;
	return getBalance();
}

double bankAccount::getBalance() const {
	return balance;
}
