// Workshop 7 - Derived Classes
// SuperHero.h
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/22

#ifndef SAFE_SUPERHERO_H
#define SAFE_SUPERHERO_H
#include "Hero.h"

namespace sict
{
	class SuperHero : public Hero 
	{
		int m_bonusAttack;
		int m_defense;

		void safeSuperHero();

	public:

		SuperHero();
		SuperHero(const char *name, int health, int attack, int bonusAttack, int defense );
		int attackStrength() const;
		int defend() const;	 	  	 
	};

	const SuperHero& operator*(const SuperHero& left, const SuperHero& right);
}
#endif