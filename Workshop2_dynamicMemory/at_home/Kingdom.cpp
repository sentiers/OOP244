// Workshop 2: Dynamic Memory 
// File: Kingdom.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/05/27

#include <iostream>
#include "Kingdom.h"

using namespace std;
namespace sict
{
	//display kingdom name and population
	void display(Kingdom& kingdom) {

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}

	void display(const Kingdom kingdomArray[], int size) {

		int totalpopulation = 0;

		for (int i = 0; i < size; i++)
		{
			totalpopulation += kingdomArray[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 2; i >= 0; i--)
		{
			cout << i + 1 << ". " << kingdomArray[i].m_name << ", population " << kingdomArray[i].m_population << endl;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalpopulation << endl;
		cout << "------------------------------" << endl;

	}
}