// Workshop 8 - Virtual Functions and Abstract Base Classes
// Account.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/29

#include <iostream>
#include "Account.h"

using namespace std;
namespace sict
{
	Account::Account(double balance)
	{
		(balance > 0) ? m_currentBalance = balance : m_currentBalance = 0.0;
	}

	bool Account::credit(double amount)
	{
		return (amount > 0) ? m_currentBalance += amount : false;
	}

	bool Account::debit(double amount)
	{
		return (amount > 0) ? m_currentBalance -= amount : false;
	}

	double Account::balance()const 
	{
		return m_currentBalance;
	}
}