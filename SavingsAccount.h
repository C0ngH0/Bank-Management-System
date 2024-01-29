#ifndef SavingsAccount_h
#define SavingsAccount_h
#include "UserAccount.h" 
//#include "Helper.h"        
class SavingsAccount : public UserAccount {
	//const static  double  MIN_BALANCE;

public:
	SavingsAccount();
	SavingsAccount(std::string accountName, int id, int accountNumber, double accountBalance, std::string accountType);
	virtual string toString();
	virtual bool withdraw(double amount);
	virtual bool deposit(double amount);
	//virtual bool operator==(shared_ptr<SavingsAccount> a );
};

#endif