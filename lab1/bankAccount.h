/*
Thomas Laughridge
tcl5tu@virginia.edu
8/31/21
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {

public:
	bankAccount();
	bankAccount(double amount);
	~bankAccount();

	double withdraw(double amount);
	double deposit(double amount);

	double getBalance() const;

private:
	double balance;

};

#endif