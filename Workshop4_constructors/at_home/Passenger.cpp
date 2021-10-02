// Workshop 4 - Constructors
// File: Passenger.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/08

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict
{
	Passenger::Passenger()
	{
		*fullName = '\0';
		*destination = '\0';
		departYear = 0;
		departMonth = 0;
		departDay = 0;
	}

	Passenger::Passenger(const char* pName, const char* pDestination)
	{
		if (pName == nullptr || pDestination == nullptr)
		{
			*this = Passenger();
		}
		else
		{
			strncpy(fullName, pName, size - 1);
			fullName[size - 1] = '\0';
			strncpy(destination, pDestination, size - 1);
			destination[size - 1] = '\0';
			departYear = 2019;
			departMonth = 10;
			departDay = 1;
		}
	}

	Passenger::Passenger(const char *pName, const char *pDestination, int Year, int Month, int Day)
	{
		bool validYear = Year >= 2019 && Year <= 2021;
		bool validMonth = Month >= 1 && Month <= 12;
		bool validDay = Day >= 1 && Day <= 31;

		if (pName == nullptr || pDestination == nullptr || !validYear || !validMonth || !validDay)
		{
			*this = Passenger();
		}
		else
		{
			strncpy(fullName, pName, size - 1);
			fullName[size - 1] = '\0';
			strncpy(destination, pDestination, size - 1);
			destination[size - 1] = '\0';
			departYear = Year;
			departMonth = Month;
			departDay = Day;
		}
	}

	bool Passenger::isEmpty() const
	{
		bool empty = false;

		if (*fullName == '\0' || *destination == '\0')
		{
			empty = true;
		}
		return empty;
	}

	void Passenger::display() const
	{
		if (isEmpty())
		{
			cout << "No passenger!" << endl;
		}
		else
		{
			cout << fullName << " - " << destination;

			if (departDay > 9)
				cout << " on " << departYear << "/" << departMonth << "/" << departDay << endl;
			else
				cout << " on " << departYear << "/" << departMonth << "/0" << departDay << endl;
		}
	}

	const char* Passenger::name()const
	{
		return this->fullName;
	}

	bool Passenger::canTravelWith(const Passenger& p)const
	{
		int sameDestination = 0;
		if (strcmp(this->destination, p.destination) == 0) sameDestination = 1;

		bool sameYear = this->departYear == p.departYear;
		bool sameMonth = this->departMonth == p.departMonth;
		bool sameDay = this->departDay == p.departDay;

		bool canTravel = sameDestination == 1 && sameYear && sameMonth && sameDay;

		return canTravel;
	}
}





