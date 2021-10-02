// Workshop 2: Dynamic Memory 
// File: Kindgom.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/05/24

#include <iostream>
#include "Kingdom.h"


using namespace std;
namespace sict
{
//display kingdom name and population
	void display(Kingdom& kingdom) {

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}
}