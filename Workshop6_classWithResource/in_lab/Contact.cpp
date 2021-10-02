// Workshop 6 - Class with a Resource
// Contact.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// 2019/7/12

#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sict
{
	Contact::Contact()
	{
		m_name[0] = '\0';
	}

	Contact::Contact(const char *name, const long long *phone, int numbers)
	{
		int oneTwoCountryCode = 0;
		int threeDigitAreaCode = 0;
		int sevenDigitNumber = 0;

		int *newNumbers = nullptr;
		newNumbers = new int[numbers];

		if (name == nullptr)
		{
			m_name[0] = '\0';
		}
		else
		{
			strncpy(m_name, name, MAX_CHAR);
			m_name[MAX_CHAR] = '\0';
		}

		if (phone == nullptr)
		{
			m_phone = nullptr;
		}
		else
		{
			for (int i = 0; i < numbers; i++)
			{
				if ((phone[i] >= 11001000000 && phone[i] <= 99999999999) || (phone[i] >= 111001000000 && phone[i] <= 999999999999))
				{
					oneTwoCountryCode = (phone[i] / 10000000000);
					threeDigitAreaCode = ((phone[i] % 10000000000) / 10000000);
					sevenDigitNumber = (phone[i] % 10000000);

					if (oneTwoCountryCode >= 1 && threeDigitAreaCode >= 100 && sevenDigitNumber >= 1000000)
					{
						newNumbers[m_numbers] = i;
						m_numbers++;
					}
				}

			}

			m_phone = new long long[m_numbers];

			int count = 0;
			for (int i = 0; i < numbers; i++)
			{
				if (newNumbers[count] == i)
				{
					m_phone[count] = phone[i];
					count++;
				}
			}
		}
	}

	Contact::~Contact()
	{
		delete[] m_phone;
		m_phone = nullptr;
	}

	bool Contact::isEmpty() const
	{
		bool empty = false;
		if (m_name[0] == '\0') empty = true;
		return empty;
	}

	void Contact::display() const
	{
		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << m_name << endl;

			if (m_phone != nullptr)
			{
				for (int i = 0; i < m_numbers; i++)
				{
					cout << "(+" << (m_phone[i] / 10000000000) << ") "
						<< ((m_phone[i] % 10000000000) / 10000000) << " "
						<< (m_phone[i] % 10000000) / 10000 << "-"
						<< setfill('0') << setw(4) << (m_phone[i] % 10000000) % 10000 << endl;
				}
			}
		}
	}
}