// Final Project - Milestone 5
// Perishable.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// 2019/8/6

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Perishable.h"

using namespace std;
namespace aid
{
	Perishable::Perishable() :Good('P')
	{
		m_expire = Date();
	}

	std::fstream& Perishable::store(std::fstream& File, bool NewLine) const
	{
		Good::store(File, false);
		File << ",";
		m_expire.write(File);

		if (NewLine) File << std::endl;

		return File;
	}

	std::fstream& Perishable::load(std::fstream& File)
	{
		Good::load(File);
		m_expire.read(File);
		return File;
	}

	std::ostream& Perishable::write(std::ostream& os, bool Linear) const
	{
		Good::write(os, Linear);
		if (isClear() && !isEmpty())
		{
			if (!Linear) os << '\n' << " Expiry date: ";

			m_expire.write(os);
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) 
	{
		Good::read(is);

		Date temp = Date();

		if (!is.fail())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp;

			if (temp.bad())
			{
				switch (temp.errCode())
				{
				case CIN_FAILED:
					message("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					message("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					message("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					message("Invalid Day in Date Entry");
					break;
				case PAST_ERROR:
					message("Invalid Expiry in Date Entry");
				}

				is.setstate(std::ios::failbit);
			}
			else m_expire = temp;
		}
		return is;
	}

	const Date& Perishable::expiry() const
	{
		return m_expire;
	}

	iGood* CreateProduct(char tag) 
	{
		iGood *igood = nullptr;

		if (tag == 'N' || tag == 'n') igood = new Good();
		else if (tag == 'P' || tag == 'p') igood = new Perishable();

		return igood;
	}
}