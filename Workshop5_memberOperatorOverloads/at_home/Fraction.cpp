// Workshop 5: operator overloading
// File: Fraction.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/17

#include <iostream>
#include "Fraction.h"

namespace sict
{
	Fraction::Fraction() {
		numerator = -1;
		denominator = 0;
	}

	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d > 0) {
			numerator = n;
			denominator = d;
			reduce();
		}
		else *this = Fraction();
	}

	int Fraction::max() const {
		int max;
		if (numerator > denominator) max = numerator;
		else max = denominator;
		return max;
	}

	int Fraction::min() const {
		int min;
		if (numerator < denominator) min = numerator;
		else min = denominator;
		return min;
	}

	int Fraction::gcd() const {
		int mn = min();
		int mx = max();
		int g_c_d = 1;
		bool found = false;
		for (int x = mn; !found && x > 0; --x) {
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int divide = gcd();
		numerator = numerator / divide;
		denominator = denominator / divide;
	}

	void Fraction::display() const {
		if (!isEmpty()) {
			if (denominator == 1) std::cout << numerator;
			else std::cout << numerator << "/" << denominator;
		}
		else std::cout << "no fraction stored";
	}

	bool Fraction::isEmpty() const {
		bool empty = false;
		if (numerator == -1 && denominator == 0) empty = true;
		return empty;
	}

	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction result;
		if (!isEmpty() && !rhs.isEmpty()) {
			result.numerator = ((numerator*rhs.denominator) + (rhs.numerator*denominator));
			result.denominator = denominator * rhs.denominator;
		}
		else result = Fraction();
		return result;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction result;
		if (!isEmpty() && !rhs.isEmpty()) {
			result.numerator = numerator * rhs.numerator;
			result.denominator = denominator * rhs.denominator;
		}
		else result = Fraction();
		return result;
	}

	bool Fraction::operator==(const Fraction& rhs) const {
		bool same = false;
		if (!isEmpty() && !rhs.isEmpty())
			if (numerator == rhs.numerator && denominator == rhs.denominator)
				same = true;
		return same;
	}

	bool Fraction::operator!=(const Fraction& rhs) const {
		bool notsame = false;
		if (!isEmpty() && !rhs.isEmpty())
			if (numerator != rhs.numerator || denominator != rhs.denominator)
				notsame = true;
		return notsame;
	}

	Fraction& Fraction::operator+=(const Fraction& rhs) {
		if (!isEmpty() && !rhs.isEmpty()) {
			*this = *this + rhs;
		}
		else *this = Fraction();
		return *this;
	}
}