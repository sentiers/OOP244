// Workshop 8 - Virtual Functions and Abstract Base Classes
// Account.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/26

#ifndef SAFE_ACCOUNT_H
#define SAFE_ACCOUNT_H
#include "iAccount.h"

namespace sict
{
	class Account : public iAccount
	{
		double m_currentBalance;

	public:
		Account(double);
		bool credit(double);
		bool debit(double);

	protected:
		double balance() const;
	};
}
#endif