// Workshop 8 - Virtual Functions and Abstract Base Classes
// SavingsAccount.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/26

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;
namespace sict
{
	SavingsAccount::SavingsAccount(double balance, double interest) :Account(balance)
	{
		if (interest > 0)
		{
			m_interest = interest;
		}
		else m_interest = 0.0;
	}

	void SavingsAccount::monthEnd()
	{
		credit(balance()* m_interest);
	}

	void SavingsAccount::display(std::ostream& os) const
	{
		os << "Account type: Savings" << std::endl;
		os << "Balance: $" << std::setprecision(2) << std::fixed << balance() << std::endl;
		os << "Interest Rate (%): " << std::setprecision(2) << m_interest*100 << std::endl;
	}
}