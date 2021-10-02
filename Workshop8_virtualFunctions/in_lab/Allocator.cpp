// Workshop 8 - Virtual Functions and Abstract Base Classes
// Allocator.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/26

#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"

namespace sict
{
	const double rate = 0.05;

	iAccount* CreateAccount(const char* type, double balance)
	{
		iAccount * newAccount = nullptr;

		if (type[0] == 'S')
			newAccount = new SavingsAccount(balance, rate);

		return newAccount;
	}
}