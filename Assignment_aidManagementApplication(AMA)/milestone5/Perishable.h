// Final Project - Milestone 5
// Perishable.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// 2019/8/6

#ifndef SAFE_PERISHABLE_H
#define SAFE_PERISHABLE_H

#include "Good.h"
#include "Date.h"

namespace aid
{
	class Perishable :public Good 
	{
		Date m_expire;

	public:
		Perishable();
		std::fstream& store(std::fstream& File, bool NewLine = true) const;
		std::fstream& load(std::fstream& File);
		std::ostream& write(std::ostream& os, bool Linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
	};
}

#endif
