#include "SavingsAccount.h"
#include "UserAccount.h"
#include<iostream>
//#include "Helper.h"
SavingsAccount::SavingsAccount() {
	//UserAccount();
}

SavingsAccount::SavingsAccount(std::string accountName, int id, int accountNumber, double accountBalance, std::string accountType) :
	UserAccount(accountName, id, accountNumber, accountBalance, accountType) {
	//regular constructor
}
string SavingsAccount::toString() {
	return "Account Name: " + getAccountName() + "\n" +
		   "Account Number: " + std::to_string(getAccountNumber()) + "\n" +
		   "Account Balance: " + fixPoint(std::to_string(getAccountBalance())) + "\n" +
		   "Account Type: Savings \n";

}
bool SavingsAccount::withdraw(double amount) {
	//overrides useraccount method to prohibit withdrawals.
	cout << "Withdraw Unsuccessful - ";
	return false;
}
bool SavingsAccount::deposit(double amount) {
	//overrides useraccount method to add rewards for deposit amount
	if (amount > REWARDS_AMOUNT) {
		amount += getAccountBalance();
		cout << "Rewards added\n";
		setAccountBalance(amount);
		addReward(amount);
		return true;
	}
	else {
		amount += getAccountBalance();
		cout << "No rewards added\n";
		setAccountBalance(amount);
	}
}
