// Workshop 5: operator overloading
// File: Fraction.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date: 2019/06/16

#ifndef SAFEFRACTION_H
#define SAFEFRACTION_H

namespace sict
{
	class Fraction {
		int numerator;
		int denominator;
	public:
		Fraction();
		Fraction(int n, int d);
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
	};
}
#endif