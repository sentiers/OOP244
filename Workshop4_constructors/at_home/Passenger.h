// Workshop 4 - Constructors
// File: Passenger.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/08

#ifndef GUARDPASSENGER_H
#define GUARDPASSENGER_H

namespace sict
{
	const int size = 19;

	class Passenger
	{
	private:
		char fullName[size];
		char destination[size];
		int departYear;
		int departMonth;
		int departDay;

	public:
		Passenger();
		Passenger(const char *pName, const char *pDestination);
		Passenger(const char *pName, const char *pDestination, int Year, int Month, int Day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger& p) const;
	};
}

#endif