// Final Project Milestone 5
// Good.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/6

#ifndef SAFE_GOOD_H
#define SAFE_GOOD_H

#include <iostream>
#include <fstream>
#include "Error.h"
#include "iGood.h"

namespace aid
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double tax_rate = 0.13;

	class Good : public iGood{
		char m_type;
		char m_sku[max_sku_length + 1];
		char m_unit[max_unit_length + 1];
		char * m_name;
		int m_onhand;
		int m_needed;
		double m_price;
		bool m_taxable;
		Error m_error;

	protected:
		void name(const char* Name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char* Msg);
		bool isClear() const;

	public:
		Good(char Type = 'N');
		Good(const char* Sku, const char* Name, const char* Unit, int Onhand = 0, bool Taxable = true, double Price = 0, int Needed = 0);
		Good(const Good& good);
		Good& operator=(const Good& good);
		virtual ~Good();
		std::fstream& store(std::fstream& File, bool NewLine = true) const;
		std::fstream& load(std::fstream& File);
		std::ostream& write(std::ostream& os, bool Linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char* Sku) const;
		double total_cost() const;
		void quantity(int Onhand);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* Sku) const;
		bool operator>(const iGood& good) const;
		int operator+=(int Add);
	};

	std::ostream& operator<<(std::ostream& os, const iGood& good);
	std::istream& operator>>(std::istream& is, iGood& good);
	double operator+=(double& Cost, const iGood& good);
}
#endif