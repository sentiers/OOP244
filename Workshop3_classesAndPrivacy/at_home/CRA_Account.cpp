// Workshop 3: Classes and Privacy
// File: CRA_Account.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/02

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;

namespace sict
{
	void CRA_Account::set(const char* FN, const char* GN, int SIN)
	{
		int valid = 0;
		int sum = 0;
		int x = 100000000;
		int sinArray[9];

		for (int i = 0; i < 9; i++)
		{
			sinArray[i] = (SIN / x) % 10;
			x /= 10;

			if (i == 0 || i == 2 || i == 4 || i == 6)
			{
				sum += sinArray[i];
			}
			else if (i == 1 || i == 3 || i == 5 || i == 7)
			{
				sum += (sinArray[i] * 2 / 10) + (sinArray[i] * 2 % 10);
			}
		}

		if (sum % 10 == (10 - sinArray[8]))
		{
			valid = 1;
		}

		if (FN[0] != '\0' && GN[0] != '\0' && SIN <= max_sin && SIN >= min_sin && valid == 1)
		{
			strncpy(familyName, FN, max_name_length);
			strncpy(givenName, GN, max_name_length);
			sin = SIN;
		}
		else
		{
			strncpy(familyName, "empty", max_name_length);
			strncpy(givenName, "empty", max_name_length);
			sin = 1;
		}

		for (int i = 0; i < max_yrs; i++)
		{
			balance[i] = 0;
		}

		years = 0;

		return;
	}

	void CRA_Account::set(int YEAR, double BALANCE)
	{
		if (!isEmpty() && years < max_yrs)
		{
			year[years] = YEAR;
			balance[years] = BALANCE;
			years++;
		}
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
		if (isEmpty())
		{
			cout << "Account object is empty!" << endl;
		}
		else
		{
			cout << "Family Name: " << familyName << endl;
			cout << "Given Name : " << givenName << endl;
			cout << "CRA Account: " << sin << endl;
			cout << fixed << setprecision(2);

			for (int i = 0; i < years; i++)
			{
				cout << "Year (" << year[i] << ") ";

				if (balance[i] > 2.00)
				{
					cout << "balance owing: " << balance[i] << endl;
				}
				else if (balance[i] < -2.00)
				{
					cout << "refund due: " << -balance[i] << endl;
				}
				else
				{
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
	}
}
