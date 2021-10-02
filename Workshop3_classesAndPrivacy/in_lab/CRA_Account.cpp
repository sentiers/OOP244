// Workshop 3: Classes and Privacy
// File: CRA_Account.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/05/31


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
	
	void CRA_Account::set(const char* FN, const char* GN, int SIN)
	{
		if (FN[0] != '\0' || GN[0] != '\0')
		{
			if (SIN <= max_sin && SIN >= min_sin)
			{
				strncpy(familyName, FN, max_name_length);
				strncpy(givenName, GN, max_name_length);
				sin = SIN;
			}
		}
		else
		{
			strncpy(familyName, "empty", max_name_length);
			strncpy(givenName, "empty", max_name_length);
			sin = 1;
		}
		return;
	}

	bool CRA_Account::isEmpty() const
	{
		bool empty = true;

		if (sin <= max_sin && sin >= min_sin)
		{
			empty = false;
		}
		return empty;
	}

	void CRA_Account::display() const
	{
		if (isEmpty()) {
			cout << "Account object is empty!" << endl;
		}
		else {

			cout << "Family Name: " << familyName << endl;
			cout << "Given Name : " << givenName << endl;
			cout << "CRA Account: " << sin << endl;

		}
	}
}
