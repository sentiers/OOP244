// Workshop 3: Classes and Privacy
// File: CRA_Account.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/05/31



#ifndef SAFEGUARD_CRA_ACCOUNT_H
#define SAFEGUARD_CRA_ACCOUNT_H

namespace sict
{
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {
		char familyName[max_name_length + 1];
		char givenName[max_name_length + 1];
		int  sin;
	public:
		void set(const char* FN, const char* GN, int SIN);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
