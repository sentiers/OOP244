// Workshop 9 - Function Templates
// Data.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/2

#include <iostream>
#include "Data.h"

namespace sict {

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		std::cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		std::cout.precision(2);
		std::cout.setf(std::ios::fixed);
		std::cout << static_cast<double>(population[n - 1] - population[0]) / 1000000 << " million" << std::endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		std::cout << "Violent Crime trend is ";
		(violentCrimeRate[1] - violentCrimeRate[0] > 0)?(std::cout << "up"): std::cout << "down";
		std::cout << std::endl;

		// Q3 print the GTA number accurate to 0 decimal places
		std::cout << "There are " << average(grandTheftAuto, n) / 1000000 << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
		std::cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << std::endl;
		std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << std::endl;
	}
}