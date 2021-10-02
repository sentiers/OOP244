// Workshop 7 - Derived Classes
// SuperHero.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/22

#include <iostream>
#include "SuperHero.h"

using namespace std;

namespace sict
{
	void SuperHero::safeSuperHero()
	{
		m_bonusAttack = 0;
		m_defense = 0;
	}

	SuperHero::SuperHero()
	{
		safeSuperHero();
	}

	SuperHero::SuperHero(const char *name, int health, int attack, int bonusAttack, int defense) :Hero(name, health, attack)
	{
		if (bonusAttack > 0 && defense > 0)
		{
			m_bonusAttack = bonusAttack;
			m_defense = defense;
		}
		else safeSuperHero();
	}

	int SuperHero::attackStrength() const
	{
		int attack = 0;
		if (m_bonusAttack > 0)
		{
			attack = Hero::attackStrength() + m_bonusAttack;
		}
		return attack;
	}

	int SuperHero::defend() const
	{
		int defense = 0;
		if (m_defense > 0)
		{
			defense = m_defense;
		}
		return defense;
	}

	const SuperHero& operator*(const SuperHero& left, const SuperHero& right)
	{
		int round = 0;

		SuperHero leftHero = left;
		SuperHero rightHero = right;

		const SuperHero* winner = &leftHero;

		bool isDead = false;

		for (int i = 0; i < MAX_ROUNDS && !isDead; i++)
		{
			round = i + 1;
			leftHero -= (rightHero.attackStrength() - leftHero.defend());
			rightHero -= (leftHero.attackStrength() - rightHero.defend());

			if (!leftHero.isAlive())
			{
				winner = &right;
				isDead = true;
			}
			else if (!rightHero.isAlive())
			{
				winner = &left;
				isDead = true;
			}
		}

		cout << "Super Fight! "
			<< left << " vs " << right
			<< " : Winner is " << *winner
			<< " in " << round << " rounds." << endl;

		return *winner;
	}
}