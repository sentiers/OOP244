// Workshop 4 - Constructors
// File: Passenger.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/07

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;

namespace sict
{
	Passenger::Passenger()
	{
		*name = '\0';
		*destination = '\0';
	}

	Passenger::Passenger(const char* pName, const char* pDestination)
	{
		if (pName == nullptr || pDestination == nullptr)
		{
			*this = Passenger();
		}
		else
		{
			strncpy(name, pName, size - 1);
			name[size - 1] = '\0';
			strncpy(destination, pDestination, size - 1);
			destination[size - 1] = '\0';
		}
	}

	bool Passenger::isEmpty() const
	{
		bool empty = false;

		if (*name == '\0' || *destination == '\0')
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
			cout << name << " - " << destination << endl;
		}
	}
}



