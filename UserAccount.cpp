#pragma once
#include "UserAccount.h"
//#include "Helper.h"
#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>

UserAccount::UserAccount() {
	this->id = 0;
	this->accountBalance = 0;
	this->accountNumber = 0;
	this->accountName = "";
	this->accountType = "";
}

UserAccount::UserAccount(std::string accountName, int id, int accountNumber, double accountBalance, std::string accountType) {
	// regular constructor
	this->id = id;
	this->accountBalance = accountBalance;
	this->accountNumber = accountNumber;
	this->accountName = accountName;
	this->accountType = accountType;
}

//getters
std::string UserAccount::getAccountName() {
	return accountName;
}
int UserAccount::getAccountNumber() {
	return accountNumber;
}
double UserAccount::getAccountBalance() {
	return accountBalance;
}
int UserAccount::getId() {
	return id;
}
std::string UserAccount::getAccountType() {
	return accountType;
}

// setters : cannot change number and accountName
//setting balance may be needed by admin
void UserAccount::setAccountBalance(double accountBalance) {
	this->accountBalance = accountBalance;
}
void UserAccount::setAccountName(string accountName) {
	this->accountName = accountName;
}
void UserAccount::setAccountNumber(int number) {
	this->accountNumber = accountNumber;
}
void UserAccount::setId(int id) {
	this->id = id;
}
void UserAccount::setAccountType(string accountType) {
	this->accountType = accountType;
}

//helper method
std::string UserAccount::fixPoint(std::string number) {
	int i = number.find('.');
	return number.substr(0, i + 3);
}

bool UserAccount::equalTo(shared_ptr<UserAccount> a) {
	if (this->getAccountName() == a->getAccountName() && this->getAccountNumber() == a->getAccountNumber() &&
		this->getAccountBalance() == a->getAccountBalance() && this->getId() == a->getId()) {
		return true;
	}
	else {
		return false;
	}
}
std::string UserAccount::toString() {
	//std::cout<<fixPoint(std::to_string(accountBalance));
	return "Account Name: " + accountName + "\n" +
		"Account Number: " + std::to_string(accountNumber) + "\n" +
		"Account Balance: " + fixPoint(std::to_string(accountBalance)) + "\n" +
		"Account Type: " + accountType + "\n";

}
bool UserAccount::withdraw(double amount) {
	if (withdraw(amount)) {
		return true;
	}
	else {
		return false;
	}
}

bool UserAccount::deposit(double amount) {
	// deposit and
	//check if eligible for reward
	if (deposit(amount)) {
		return true;
	}
	else {
		return false;
	}
}

void  UserAccount::addReward(double amount) {
	accountBalance += REWARD_RATE * amount;
}


const double UserAccount::MIN_BALANCE = 9.99;
const double UserAccount::MIN_REWARD_AMOUNT = 1000.0;
const double UserAccount::REWARD_RATE = 0.04;
const double UserAccount::REWARDS_AMOUNT = 1000.00;
