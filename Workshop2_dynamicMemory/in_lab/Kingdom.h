// Workshop 2: Dynamic Memory 
// File: Kindgom.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/05/24


#ifndef HEADERSAFEGUARDS_KINGDOM_H
#define HEADERSAFEGUARDS_KINGDOM_H

namespace sict
{


	struct Kingdom {
		char m_name[32];
		int m_population;
	};


	void display(Kingdom& kingdom);


}
#endif
