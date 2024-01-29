#ifndef UserAccount_h
#define UserAccount_h
//#include "UserAccount.h"
//#include "Helper.h"
//#include "Bank.h"
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include<memory>
class UserAccount {
public:
	const static  double  MIN_BALANCE;
	const static double REWARD_RATE;
	const static double MIN_REWARD_AMOUNT;
	const static double REWARDS_AMOUNT;

private:
	int accountNumber, id;
	std::string accountName, accountType;
	double accountBalance;

public:
	UserAccount();
	UserAccount(std::string accountName, int id, int accountNumber, double accountBalance, std::string accountType);

	//getters
public:
	std::string getAccountName();
	int getAccountNumber();
	double getAccountBalance();
	int getId();
	std::string getAccountType();
	
	// setters : cannot change number and accountName
	//setting balance may be needed by admin
	void setAccountName(string accountName);
	void setAccountNumber(int number);
	void setId(int id);
	void setAccountBalance(double accountBalance);
	void setAccountType(string accountType);

	//bool operator==(<shared_ptr<UserAccount> a, shared_ptr<UserAccount> b);
	//bool equals(shared_ptr<UserAccount> a);
	virtual std::string toString();
	virtual bool withdraw(double amount);

	std::string fixPoint(std::string number);
	//virtual
	//void calculateBalance();
	virtual bool deposit(double amount);
	bool equalTo(shared_ptr<UserAccount> a);
	void addReward(double amount);
	




};

#endif