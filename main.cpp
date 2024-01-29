#include <iostream>
#include "Bank.h"
int main() {
	shared_ptr<UserAccount> newAcc = make_shared<CheckingAccount>("John Smith", 9999, 1120, 154.67, "");
	shared_ptr<UserAccount> temp = make_shared<SavingsAccount>("Lily Zhaou", 786534, 1242, 001.98, "");
	shared_ptr<UserAccount> temp2 = make_shared<CheckingAccount>("Vai vu", 432657, 1240, 987.56, "");
	shared_ptr<UserAccount> temp3 = make_shared<SavingsAccount>("Fernando Diaz", 323468, 1234, 250.00, "");

	string filename;
	int action;
	cout << "What is the file name? ";
	cin >> filename;
	if (filename == "BankData" || filename == "BankData.txt") {
		Bank WellsFargo(filename);//test action 1 : incorrect file name
		WellsFargo.sortAccounts();
		WellsFargo.displayAccounts();
		for (int i = 0; i < 9; i++) {
			cout << "Which action would you like to test ? ";
			if (cin >> action) {
				cout << "\n";
				if (action == 2) { // add a new account 
					WellsFargo.displayAccounts();
					cout << "****** Added New Checking Account ******\n";
					WellsFargo.addAccount(newAcc);
					cout << newAcc->toString() << "\n";
					cout << "Displaying Resulting Sorted Database\n";
					WellsFargo.displayAccounts();
					WellsFargo.removeAccount(newAcc);
				}
				else if (action == 3) { //remove and display
					WellsFargo.displayAccounts();
					//cout << "****** Removing Account ******\n";
					//WellsFargo.removeAccount(temp);
					//cout << temp->toString() << "\n";
					//WellsFargo.displayAccounts();
					if (WellsFargo.removeAccount(temp)) {
						cout << "****** Removing Account ******\n";
						cout << temp->toString() << "\n";
					}
					else {
						cout << "****** Account Does not Exist ******\n\n";
					}
					cout << "Displaying Resulting Sorted Database\n";
					WellsFargo.displayAccounts();
					if (WellsFargo.removeAccount(temp)) {
						cout << "****** Removing Account ******\n";
						cout << temp->toString() << "\n";
					}
					else {
						cout << "****** Account Does not Exist ******\n\n";
					}
					WellsFargo.addAccount(temp);
				}
				else if (action == 4) { // backing up accounts
					Bank Backup(WellsFargo);
					WellsFargo.displayAccounts();
					if (Backup.checkSame(WellsFargo))
						cout << "Verified Backup" << endl; // verifying that they are same;
					else cout << "Backup Error " << endl;
				}
				else if (action == 5) { // back up and remove account from original
					Bank Backup(WellsFargo);
					WellsFargo.displayAccounts();
					WellsFargo.removeAccount(temp);
					if (Backup.checkDiff(WellsFargo))
						cout << "Verified Backup" << endl; // verifying that they are same;
					else cout << "Backup Error Databases do not match" << endl;
				}
				else if (action == 6) { // withdraw money from CheckingAccount
					WellsFargo.displayAccounts();
					if (WellsFargo.accountWithdraw(temp2, 20)) { // withdraw $20 from CheckingAccount
						cout << "Withdraw Successful for this amount $20" << endl;
						cout << temp2->toString() << "\n";
					}
					else {
						cout << "Withdraw Unsuccessful for this amount $20" << endl;
						cout << temp2->toString() << "\n";
					}

					if (WellsFargo.accountWithdraw(temp2, -20)) { // withdraw -$20 from CheckingAccount
						cout << "Withdraw Successful for this amount -$20" << endl;
						cout << temp2->toString() << "\n";
					}
					else {
						cout << "Withdraw Unsuccessful for this amount -$20" << endl;
						cout << temp2->toString() << "\n";
					}
				}
				else if (action == 7) { // withdraw money from CheckingAccount
					WellsFargo.displayAccounts();
					WellsFargo.accountDeposit(temp2, 20);
					if (WellsFargo.accountWithdraw(temp2, 900)) {
						cout << "Withdraw Successful for this amount $900" << endl;
						cout << temp2->toString() << "\n";
					}
					else {
						cout << "Withdraw Unsuccessful for this amount - Minimum funds $99.99" << endl;
						cout << temp2->toString() << "\n";
					}
					if (WellsFargo.accountWithdraw(temp2, 5000)) {
						cout << "Withdraw Successful for this amount $5000" << endl;
						cout << temp2->toString() << "\n";
					}
					else {
						cout << "Withdraw Unsuccessful - Insufficient funds for this amount $5000" << endl;
						cout << temp2->toString() << "\n";
					}
				}
				else if (action == 8) { // withdraw money from SavingsAccount
					WellsFargo.sortAccounts();
					WellsFargo.displayAccounts();
					if (WellsFargo.accountWithdraw(temp3, 20)) {
						cout << "Withdraw Successful" << endl;
						cout << temp3->toString() << "\n";
					}
					else {
						cout << "Cannot Withdraw from Savings" << endl;
						cout << temp3->toString() << "\n";
					}
				}
				else if (action == 9) { // deposit money into SavingsAccount
					WellsFargo.displayAccounts();
					if (WellsFargo.accountDeposit(temp, 1001)) {
						cout << "Deposit Successful for $1001" << endl;
						cout << temp->toString() << "\n";
					}
					else {
						cout << "Deposit Unsuccessful for $1001\n";
					}
					if (WellsFargo.accountDeposit(temp, 20)) {
						cout << "Deposit Successful for $20" << endl;
						cout << temp->toString() << "\n";
					}
					else {
						cout << "Deposit Unsuccessful for $20\n";
						cout << temp->toString() << "\n";
					}
				}
				else if (action == 10) { // deposit money into CheckingAccount
					WellsFargo.displayAccounts();
					if (WellsFargo.accountDeposit(temp2, -20)) {
						cout << "Checking Account Deposit Successful for -$20" << endl;
						cout << temp2->toString() << "\n";
					}
					else {
						cout << "Checking Account Deposit Unsuccessful - Negative Amount" << endl;
						cout << temp2->toString() << "\n";
					}
					if (WellsFargo.accountDeposit(temp2, 20)) {
						cout << "Checking Account Deposit Successful for $20" << endl;
						cout << temp2->toString() << "\n";
					}
					else {
						cout << "Checking Account Deposit Unsuccessful - Negative Amount" << endl;
						cout << temp2->toString() << "\n";
					}
				}
				else cout << "Testing Ends" << endl;
			}
		}
	}
	else {
	cout << "File Open Error -99";
		exit(-99);
	}
}