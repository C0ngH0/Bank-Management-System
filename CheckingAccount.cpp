#include "CheckingAccount.h"
#include "UserAccount.h"
//#include "Helper.h"
#include<iostream>
CheckingAccount::CheckingAccount() {
	
}

CheckingAccount::CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance, std::string accountType) :
	UserAccount(accountName, id, accountNumber, accountBalance, accountType) {
	
}
string CheckingAccount::toString() {
	return  "Account Name: " + getAccountName() + "\n" +
		"Account Number: " + std::to_string(getAccountNumber()) + "\n" +
		"Account Balance: " + fixPoint(std::to_string(getAccountBalance())) + "\n"
		+
		"Account Type: Checking \n";
}
bool CheckingAccount::withdraw(double amount) {
	//overrides useraccount method to permit any number of withdrawals, 
	//keeping the miminum balance.
	if (amount > 0) {
		amount = getAccountBalance() - amount;
		if (amount > MIN_BALANCE_CHECKING) {
			setAccountBalance(amount);
			return true;
		}
		else if (amount = MIN_BALANCE_CHECKING || amount < MIN_BALANCE_CHECKING) {
			return false;
		}
	}
	else {
		return false;
	}
}

bool CheckingAccount::deposit(double amount) {
	//overrides useraccount method to prohibit negative withdrawal amount
	if (amount > 0) {
		amount += getAccountBalance();
		setAccountBalance(amount);
		return true;
	}
	else {
		return false;
	}
}
const double CheckingAccount::MIN_BALANCE_CHECKING = 99.99;

