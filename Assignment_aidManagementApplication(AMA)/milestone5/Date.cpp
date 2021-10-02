// Final Project Milestone 5
// Date.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/6

#include <iostream>
#include <iomanip>
#include "Date.h"

namespace aid
{
	Date::Date()
	{
		safeEmpty();
	}

	void Date::safeEmpty() 
	{
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_comparator = 0;
		m_error = NO_ERROR;
	}

	Date::Date(int year, int month, int day)
	{
		if (year >= min_year && year <= max_year)
		{
			if (month >= 1 && month <= 12)
			{
				int temp_days = mdays(month, year);

				if (day >= 1 && day <= temp_days)
				{
					m_comparator = year * 372 + month * 31 + day;

					if (m_comparator >= min_date)
					{
						m_year = year;
						m_month = month;
						m_day = day;
						m_error = NO_ERROR;
					}
					else
					{
						safeEmpty();
						m_error = PAST_ERROR;
					}
				}
				else
				{
					safeEmpty();
					m_error = DAY_ERROR;
				}
			}
			else
			{
				safeEmpty();
				m_error = MON_ERROR;
			}
		}
		else
		{
			safeEmpty();
			m_error = YEAR_ERROR;
		}
	}

	int Date::mdays(int mon, int year)const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode)
	{
		m_error = errorCode;
	}

	int Date::errCode() const
	{
		return m_error;
	}

	bool Date::bad() const
	{
		return m_error != NO_ERROR;
	}

	bool Date::operator==(const Date& rhs) const
	{
		return (!bad() && !rhs.bad()) ? m_comparator == rhs.m_comparator : false;
	}

	bool Date::operator!=(const Date& rhs) const
	{
		return (!bad() && !rhs.bad()) ? m_comparator != rhs.m_comparator : false;
	}

	bool Date::operator<(const Date& rhs) const
	{
		return (!bad() && !rhs.bad()) ? m_comparator < rhs.m_comparator : false;
	}

	bool Date::operator>(const Date& rhs) const
	{
		return (!bad() && !rhs.bad()) ? m_comparator > rhs.m_comparator : false;
	}

	bool Date::operator<=(const Date& rhs) const
	{
		return (!bad() && !rhs.bad()) ? m_comparator <= rhs.m_comparator : false;
	}

	bool Date::operator>=(const Date& rhs) const
	{
		return (!bad() && !rhs.bad()) ? m_comparator >= rhs.m_comparator : false;
	}

	std::istream& Date::read(std::istream& istr)
	{
		char c;
		istr.clear();

		istr >> m_year >> c >> m_month >> c >> m_day;

		if (istr.fail())
		{
			safeEmpty();
			m_error = CIN_FAILED;
		}
		else if (m_year < min_year || m_year > max_year)
		{
			safeEmpty();
			m_error = YEAR_ERROR;
		}
		else if (m_month < 1 || m_month > 12)
		{
			safeEmpty();
			m_error = MON_ERROR;
		}
		else if (m_day > mdays(m_month, m_year))
		{
			safeEmpty();
			m_error = DAY_ERROR;
		}
		else if ((m_year * 372 + m_month * 31 + m_day) < min_date)
		{
			safeEmpty();
			m_error = PAST_ERROR;
		}

		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		ostr << m_year << "/";

		if (m_month < 10) ostr << 0;

		ostr << m_month << "/";

		if (m_day < 10)	ostr << 0;

		ostr << m_day;

		return ostr;
	}

	std::ostream& operator<<(std::ostream& ostr, Date& d)
	{
		d.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& d)
	{
		d.read(istr);
		return istr;
	}
}