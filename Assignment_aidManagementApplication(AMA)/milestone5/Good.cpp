// Final Project Milestone 5
// Good.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/8/6

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

	void Good::message(const char* Msg)
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
		m_error.message();
	}

	Good::Good(const char* Sku, const char* Name, const char* Unit, int Onhand, bool Taxable, double Price, int Needed)
	{
		if (Sku != nullptr && Name != nullptr && Unit != nullptr) {
			strncpy(m_sku, Sku, max_sku_length);
			m_sku[max_sku_length] = '\0';

			name(Name);

			strncpy(m_unit, Unit, max_unit_length);
			m_unit[max_unit_length] = '\0';

		}
		m_onhand = Onhand;
		m_taxable = Taxable;
		m_price = Price;
		m_needed = Needed;
	}

	Good::Good(const Good& good)
	{
		m_name = nullptr;
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
			message(good.m_error.message());
		}
		return *this;
	}

	Good::~Good()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	std::fstream& Good::store(std::fstream& File, bool Newline) const
	{
		File << m_type << "," << m_sku << "," << m_name << "," << m_unit << "," << m_taxable << "," << m_price << "," << m_onhand << "," << m_needed;
		if (Newline) File << endl;

		return File;
	}

	std::fstream& Good::load(std::fstream& File)
	{
		Good temp;
		temp.m_name = new char[max_name_length + 1];

		if (File.is_open())
		{
			File.getline(temp.m_sku, max_sku_length + 1, ',');
			File.getline(temp.m_name, max_name_length + 1, ',');
			File.getline(temp.m_unit, max_unit_length + 1, ',');
			File >> temp.m_taxable;
			File.ignore();
			File >> temp.m_price;
			File.ignore();
			File >> temp.m_onhand;
			File.ignore();
			File >> temp.m_needed;
			File.ignore();

			char Ptype = this->m_type;
			*this = temp;
			this->m_type = Ptype;
		}

		delete[] temp.m_name;
		temp.m_name = nullptr;

		return File;
	}

	std::ostream& Good::write(std::ostream& os, bool Linear) const
	{
		if (!isEmpty()) 
		{
			if (!m_error.isClear()) os << m_error.message();
			else 
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
					os << " Sku: " << m_sku << endl;
					os << " Name (no spaces): " << m_name << endl;
					os << " Price: " << m_price << endl;

					m_taxable ? (os << " Price after tax: " << itemCost() << endl) : (os << " Price after tax:  N/A" << endl);

					os << " Quantity on Hand: " << m_onhand << " " << m_unit << endl;
					os << " Quantity needed: " << m_needed;
				}
			}
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
		name(Name);

		cout << " Unit: ";
		is >> temp.m_unit;

		cout << " Taxed? (y/n): ";
		is >> Taxable;
		if (Taxable == 'Y' || Taxable == 'y') temp.m_taxable = true;
		else if (Taxable == 'N' || Taxable == 'n') temp.m_taxable = false;
		else
		{
			is.setstate(ios::failbit);
			message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail())
		{
			cout << " Price: ";
			is >> temp.m_price;

			if (is.fail()) message("Invalid Price Entry");
		}

		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> temp.m_onhand;

			if (is.fail()) message("Invalid Quantity Entry");
		}

		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> temp.m_needed;

			if (is.fail()) message("Invalid Quantity Needed Entry");
		}

		if (!is.fail())
		{
			char Ptype = m_type;
			temp.name(Name);
			*this = temp;
			m_type = Ptype;
		}
		is.ignore();
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

	bool Good::operator>(const iGood& good) const //???????
	{
		return strcmp(m_name, good.name()) > 0;
	}

	int Good::operator+=(int Add)
	{
		return Add > 0 ? m_onhand += Add : m_onhand;
	}

	std::ostream& operator<<(std::ostream& os, const iGood& good)
	{

		return good.write(os, true);
	}

	std::istream& operator>>(std::istream& is, iGood& good)
	{
		return good.read(is);
	}

	double operator+=(double& Cost, const iGood& good)
	{
		return good.total_cost() + Cost;
	}

}