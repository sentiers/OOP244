// Workshop 8 - Virtual Functions and Abstract Base Classes
// ChequingAccount.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/29

#ifndef SAFE_CHEQUINGACCOUNT_H
#define SAFE_CHEQUINGACCOUNT_H
#include "Account.h"

namespace sict
{
	class ChequingAccount : public Account
	{
		double m_transactionFee;
		double m_monthlyFee;

	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif