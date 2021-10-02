// Workshop 8 - Virtual Functions and Abstract Base Classes
// ChequingAccount.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/29

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"

using namespace std;
namespace sict
{
	ChequingAccount::ChequingAccount(double balance, double transactionFee, double monthlyFee):Account(balance)
	{
		(transactionFee > 0) ? m_transactionFee = transactionFee : m_transactionFee = 0.0;
		(monthlyFee > 0) ? m_monthlyFee = monthlyFee : m_monthlyFee = 0.0;		   
	}

	bool ChequingAccount::credit(double amount) 
	{
		return Account::credit(amount) && Account::debit(m_transactionFee);
	}

	bool ChequingAccount::debit(double amount) 
	{
		return Account::debit(amount) && Account::debit(m_transactionFee);
	}

	void ChequingAccount::monthEnd() 
	{
		Account::debit(m_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& os) const 
	{
		os << "Account type: Chequing" << std::setprecision(2) << std::fixed << std::endl;
		os << "Balance: $"  << balance() << std::endl;
		os << "Per Transaction Fee: " << m_transactionFee << std::endl;
		os << "Monthly Fee: " << m_monthlyFee << std::endl;
	}
}