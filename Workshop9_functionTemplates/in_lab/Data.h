// Workshop 9 - Function Templates
// Data.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/2

#ifndef SAFE_DATA_H
#define SAFE_DATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

namespace sict
{

	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field
	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	// max returns the largest item in data
	//
	template<typename T>
	T max(const T* data, int n)
	{
		T max = data[0];
		for (int i = 1; i < n; ++i)
		{
			if (max < data[i]) max = data[i];
		}
		return max;
	}

	// min returns the smallest item in data
	//
	template<typename T>
	T min(const T* data, int n)
	{
		T min = data[0];
		for (int i = 1; i < n; ++i)
		{
			if (min > data[i]) min = data[i];
		}
		return min;
	}

	// sum returns the sum of n items in data
	//    
	template<typename T>
	T sum(const T* data, int n)
	{
		T sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += data[i];
		}
		return sum;
	}

	// average returns the average of n items in data
	//
	template<typename T>
	double average(const T* data, int n)
	{
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	//
	template<typename T>
	bool read(std::istream & input, T * data, int n)
	{
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			input.ignore();
			input >> data[i];

			if (input.fail()) flag = false;
		}
		return flag;
	}

	// display inserts n items of data into std::cout
	//
	template<typename T>
	void display(const char * name, const T * data, int n)
	{
		std::cout.width(20);
		std::cout << std::right << name;

		for (int i = 0; i < n; ++i)
		{
			std::cout.width(15);
			std::cout << data[i];
		}
		std::cout << "\n";
	}

	// bool readRow(std::istream& input, const char* name, int* data, int n);
	// bool readRow(std::istream& input, const char* name, double* data, int n);
	//
	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n)
	{
		char rowname[2000];
		bool ok = !input.bad();

		if (ok)
		{
			input.get(rowname, 2000, ',');

			if (std::strcmp(rowname, name) != 0)
			{
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok) ok = read(input, data, n);

		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

#endif