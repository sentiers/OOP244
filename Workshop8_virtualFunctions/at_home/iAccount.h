// Workshop 8 - Virtual Functions and Abstract Base Classes
// iAccount.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/29

#ifndef SAFE_IACCOUNT_H
#define SAFE_IACCOUNT_H

namespace sict
{
	class iAccount 
	{
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;

		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char*, double);
}
#endif