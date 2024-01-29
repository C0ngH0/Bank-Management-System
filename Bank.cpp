
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"
void fillVector(ifstream& input, vector<shared_ptr<UserAccount>>& accountsVector) {
	string accountName; string lastName; string firstName, info, accountType;
	int id, accountNumber;
	double accountBalance;
	//while not eof getline from file
	// parse the line and create shared pointer to BankAccount
	//push the pointe onto the accounts vector
	while (!input.eof()) {
		getline(input, info);
		std::istringstream instream(info);
		instream >> firstName >> lastName >> id >> accountNumber >> accountBalance>>accountType; //getting data from file
		std::shared_ptr<UserAccount> temp = std::make_shared<UserAccount>(firstName + " " +
			lastName, id, accountNumber, accountBalance, accountType);
		accountsVector.push_back(temp); //storing data into the vector
	}
}

void Bank::displayAccounts() {

	for (int i = 0; i < accountsVector.size(); i++) {
		cout << accountsVector[i]->toString() << endl;
	}
}

Bank::Bank(const Bank& other) {
	//cout << " In copy constructor  " << endl;
	//accountsVector.resize(other.accountsVector.size());
	(this->accountsVector).assign(other.accountsVector.begin(), other.accountsVector.end());
	//cout<<accountsVector.size()<<endl;
	//create a cop constructor that copies the two vectors
}


Bank::Bank(string filename) {
	// throw File Open Error - File Exception -99 if file cannot be opened
    //use try catch statement
	std::ifstream input;

	try {
		input.open("C:\\Users\\minhh\\OneDrive\\Desktop\\SCC\\CISP 400\\Week 15\\FinalProject\\BankData.txt"); //open txt file
		if (input.fail()) {//if cannot open file
			throw FileException(99);
		}
		fillVector(input, accountsVector);
		input.close();
	}
	catch (FileException) {
		std::cout << "99";
		exit(1);
	}
}
void Bank::addAccount(shared_ptr<UserAccount> a)//should sort vector
{
	//add an account
	// be sure to keep vector sorted
	//use STL sort using Greater THan Function Object
	accountsVector.push_back(a);
	sortAccounts();
}
void Bank::sortAccounts() {
	// use the STL sort by passing the beginning, end and Greater Than Functormem
	sort(accountsVector.begin(), accountsVector.end(), myOperator);
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount) {
	// return false if amount is negative
	// return true after depositing into account
	return (a->deposit(amount));
}
bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount) {
	// if the withdraw amount is suitable then withdraw from account and return true
    //otherwise return false
	return (a->withdraw(amount));
}
bool Bank::checkSame(Bank& other) {
	// check if this bank has the exact same accounts as the other bank
	//use equalTo method created in the UserAccount class (that implments Comparable)
	// return true if same, false otherwise  
	// equalTo should check if each and every field matches
	for (int i = 0; i < accountsVector.size(); i++) {
		for (int j = 0; i < other.accountsVector.size(); j++) {
			if (accountsVector[i]->equalTo(other.accountsVector[j]) && accountsVector.size() == other.accountsVector.size()) {
				return true;
			}
		}
	}
	return false;
}
bool Bank::checkDiff(Bank& other) {
	// check if this bank has the exact same accounts as the other bank
	//use equalTo method created in the UserAccount class (that implments Comparable)
	// return true if same, false otherwise  
	// equalTo should check if each and every field matches
	for (int i = 0; i < accountsVector.size(); i++) {
		for (int j = 0; i < other.accountsVector.size(); j++) {
			if (accountsVector.size() != other.accountsVector.size()) {
				//cout << "inchecksame\n";
				return false;
			}
		}
	}
	return true;
}
bool Bank::removeAccount(shared_ptr<UserAccount> a) {
	//search for the the given account a, if found
	//use vector.erase method to remove it and return true
	//otherwise return false
	for (int i = 0; i < accountsVector.size(); i++) {
		if (accountsVector[i]->equalTo(a)) {
			accountsVector.erase(accountsVector.begin() + i);
			return true;
		}
	}
	return false;
}
/*bool Bank::withdrawExistedAccount(int a, double amount) {
	
	accountsVector[a]->withdraw(amount);
	
	return true;

}*/

