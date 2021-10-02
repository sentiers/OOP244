// Workshop 4 - Constructors
// File: Passenger.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/07

#ifndef GUARDPASSENGER_H
#define GUARDPASSENGER_H

namespace sict
{
	const int size = 19;

	class Passenger
	{
	private:
		char name[size];
		char destination[size];
	public:
		Passenger();
		Passenger(const char *pName, const char *pDestination);
		bool isEmpty() const;
		void display() const;
	};
}

#endif