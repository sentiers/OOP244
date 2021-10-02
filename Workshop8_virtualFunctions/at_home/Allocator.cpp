// Workshop 8 - Virtual Functions and Abstract Base Classes
// Allocator.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/29

#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"

using namespace std;
namespace sict
{
	const double rate = 0.05;
	const double transFee = 0.50;
	const double monthFee = 2.00;

	iAccount* CreateAccount(const char* type, double balance)
	{
		iAccount * newAccount = nullptr;

		if (type[0] == 'S')
			newAccount = new SavingsAccount(balance, rate);
		else if (type[0] == 'C')
			newAccount = new ChequingAccount(balance, transFee, monthFee);

		return newAccount;
	}
}