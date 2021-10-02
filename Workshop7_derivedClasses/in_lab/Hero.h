// Workshop 7 - Derived Classes
// Hero.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/19

#include <iostream>

#ifndef SAFE_HERO_H
#define SAFE_HERO_H

namespace sict
{
	const int MAX_ROUNDS= 100;

	class Hero {

		char m_name[40 + 1];
		int m_health;
		int m_attack;

		void safeHero();
		
	public:

		Hero();
		Hero(const char * name, int health, int attack);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;

		std::ostream& display(std::ostream& os = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& left, const Hero& right);
}

#endif
