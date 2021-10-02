// Final Project Milestone 3
// Good.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// 2019/7/31

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Good.h"
#include "Error.h"

using namespace std;
namespace aid
{
	void Good::name(const char* Name)
	{
		if (Name == nullptr) m_name = nullptr;
		else
		{
			m_name = new char[strlen(Name) + 1];
			strcpy(m_name, Name);
		}
	}

	const char* Good::name()const
	{
		return m_name;
	}

	const char* Good::sku() const
	{
		return m_sku;
	}

	const char* Good::unit() const
	{
		return m_unit;
	}

	bool Good::taxed() const
	{
		return m_taxable;
	}

	double Good::itemPrice() const
	{
		return m_price;
	}

	double Good::itemCost() const
	{
		return taxed() ? m_price * (1 + tax_rate) : m_price;
	}

	void Good::messages(const char* Msg)
	{
		m_error.message(Msg);
	}

	bool Good::isClear() const
	{
		return m_error.isClear();
	}

	Good::Good(char Type)
	{
		m_type = Type;
		m_sku[0] = '\0';
		m_unit[0] = '\0';
		m_name = nullptr;
		m_onhand = 0;
		m_needed = 0;
		m_price = 0;
		m_taxable = true;
	}

	Good::Good(const char* Sku, const char* Name, const char* Unit, int Onhand, bool Taxable, double Price, int Needed)
	{
		strncpy(m_sku, Sku, max_sku_length);
		m_sku[max_sku_length] = '\0';

		name(Name);

		strncpy(m_unit, Unit, max_unit_length);
		m_unit[max_unit_length] = '\0';

		m_onhand = Onhand;
		m_taxable = Taxable;
		m_price = Price;
		m_needed = Needed;
	}

	Good::Good(const Good& good)
	{
		*this = good;
	}

	Good& Good::operator=(const Good& good)
	{
		if (this != &good)
		{
			m_type = good.m_type;
			strcpy(m_sku, good.sku());
			strcpy(m_unit, good.unit());
			name(good.m_name);
			m_onhand = good.m_onhand;
			m_needed = good.m_needed;
			m_price = good.itemPrice();
			m_taxable = good.taxed();
			messages(good.m_error.message());
		}
		return *this;
	}

	Good::~Good()
	{
		delete[] m_name;
	}

	std::fstream& Good::store(std::fstream& File, bool Newline) const
	{
		File << m_type << "," << m_sku << "," << m_unit << "," << m_name << "," << m_onhand << "," << m_needed << "," << m_price << "," << m_taxable << "," << m_error;

		if (Newline) File << endl;

		return File;
	}

	std::fstream& Good::load(std::fstream& File) 
	{
		Good temp;
		temp.m_name = new char[max_name_length + 1];

		if (File.is_open())
		{
			File >> temp.m_type >> temp.m_sku >> temp.m_unit >> temp.m_name >> temp.m_onhand;
			*this = temp;
		}

		delete[] temp.m_name;
		temp.m_name = nullptr;

		return File;
	}

	std::ostream& Good::write(std::ostream& os, bool Linear) const 
	{
		if (Linear) 
		{
			os << setw(max_sku_length) << left << m_sku << "|"
				<< setw(20) << left << m_name << "|"
				<< setw(7) << right << fixed << setprecision(2) << itemCost() << "|"
				<< setw(4) << right << m_onhand << "|"
				<< setw(10) << left << m_unit << "|"
				<< setw(4) << right << m_needed << "|";
		}
		else 
		{
			os << "Sku: " << m_sku << endl;
			os << "Name(no spaces): " << m_name << endl;
			os << "Price: " << m_price << endl;

			m_taxable ? (os << "Price after tax: " << itemCost() << endl) : (os << "N/A" << endl);

			os << "Quantity on hand: " << m_onhand << endl;
			os << "Quantity needed: " << m_needed << endl;
		}
		return os;
	}

	std::istream& Good::read(std::istream& is) 
	{
		char Taxable;
		char Name[max_name_length + 1];

		Good temp;

		cout << " Sku: ";
		is >> temp.m_sku;

		cout << " Name (no spaces): ";
		is >> Name;

		cout << " Unit: ";
		is >> temp.m_unit;

		cout << " Taxed? (y/n): ";
		is >> Taxable;

		if (Taxable == 'Y' || Taxable == 'y') temp.m_taxable = true;
		else if (Taxable == 'N' || Taxable == 'n') temp.m_taxable = false;
		else
		{
			is.setstate(ios::failbit);
			temp.messages("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail()) 
		{
			cout << " Price: ";
			is >> temp.m_price;

			if (is.fail()) temp.messages("Invalid Price Entry");
		}

		if (!is.fail()) 
		{
			cout << " Quantity on hand: ";
			is >> temp.m_onhand;

			if (is.fail()) temp.messages("Invalid Quantity Entry");
		}

		if (!is.fail()) 
		{
			cout << " Quantity needed: ";
			is >> temp.m_needed;

			if (is.fail()) temp.messages("Invalid Quantity Needed Entry");
		}

		if (!is.fail()) 
		{
			temp.name(Name);
			*this = temp;
		}

		return is;
	}

	bool Good::operator==(const char* Sku) const 
	{
		return strcmp(m_sku, Sku) == 0;
	}

	double Good::total_cost() const
	{
		return itemCost() * m_onhand;
	}

	void Good::quantity(int Onhand) 
	{
		if (Onhand > 0) m_onhand = Onhand;
	}

	bool Good::isEmpty() const 
	{
		return m_sku[0] == '\0' && m_unit[0] == '\0' && m_name == nullptr;
	}

	int Good::qtyNeeded() const 
	{
		return m_needed;
	}

	int Good::quantity() const 
	{
		return m_onhand;
	}

	bool Good::operator>(const char* Sku) const 
	{
		return strcmp(m_sku, Sku) > 0;
	}

	bool Good::operator>(const Good& good) const 
	{
		return strcmp(m_name, good.m_name);
	}

	int Good::operator+=(int Add) 
	{
		return Add > 0 ? m_onhand += Add : m_onhand;
	}

	std::ostream& operator<<(std::ostream& os, const Good& good) 
	{
		good.write(os, true);
		return os;
	}

	std::istream& operator>>(std::istream& is, Good& good) 
	{
		good.read(is);
		return is;
	}

	double operator+=(double& Cost, const Good& good) 
	{
		Cost += good.total_cost();
		return Cost;
	}

}