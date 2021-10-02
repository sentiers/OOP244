// Workshop 8 - Virtual Functions and Abstract Base Classes
// SavingsAccount.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/29

#ifndef SAFE_SAVINGSACCOUNT_H
#define SAFE_SAVINGSACCOUNT_H
#include "Account.h"

namespace sict
{
	class SavingsAccount : public Account 
	{
		double m_interest;

	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif