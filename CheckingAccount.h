#ifndef CheckingAccount_h
#define CheckingAccount_h

#include "UserAccount.h"
class CheckingAccount : public UserAccount {
public:
	const static  double  MIN_BALANCE_CHECKING;
public:
	CheckingAccount();
	CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance, std::string accountType);
	virtual string toString();
	virtual bool withdraw(double amount);
	virtual bool deposit(double amount);
	//virtual bool operator==(shared_ptr<CheckingAccount> a );
};

#endif