// Final Project Milestone 5
// Date.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/6

#ifndef GUARD_DATE_H
#define GUARD_DATE_H

namespace aid
{
	const int 	min_year = 2018;
	const int	max_year = 2038;
	const int	min_date = 751098;

	const int 	NO_ERROR = 0;
	const int	CIN_FAILED = 1;
	const int	DAY_ERROR = 2;
	const int	MON_ERROR = 3;
	const int	YEAR_ERROR = 4;
	const int	PAST_ERROR = 5;

	class Date
	{
		int m_year;
		int	m_month;
		int	m_day;
		int	m_comparator;
		int	m_error;

		int mdays(int, int)const;
		void errCode(int errorCode);
		void safeEmpty();

	public:

		Date();
		Date(int year, int month, int day);

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode() const;
		bool bad() const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::ostream& operator<<(std::ostream& ostr, Date&);
	std::istream& operator>>(std::istream& istr, Date&);
}

#endif
