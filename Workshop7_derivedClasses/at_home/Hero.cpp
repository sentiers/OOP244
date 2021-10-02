// Workshop 7 - Derived Classes
// Hero.cpp
// Hyunji Cho #128065182 hcho51@myseneca.ca
// Date 2019/7/22

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"

using namespace std;
namespace sict
{
	void Hero::safeHero()
	{
		m_name[0] = '\0';
		m_health = 0;
		m_attack = 0;
	}

	Hero::Hero()
	{
		safeHero();
	}

	Hero::Hero(const char * name, int health, int attack)
	{
		if (name[0] != '\0' && health > 0 && attack > 0)
		{
			strcpy(m_name, name);
			m_health = health;
			m_attack = attack;
		}
		else safeHero();
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0)
		{
			m_health -= attack;
		}
		if (m_health < 0)
		{
			m_health = 0;
		}
	}

	bool Hero::isAlive() const
	{
		int healthy = 0;
		if (m_health > 0)
		{
			healthy = 1;
		}
		return healthy;
	}

	int Hero::attackStrength() const
	{
		int attack = 0;

		if (m_name[0] != '\0' && m_health > 0 && m_attack > 0)
		{
			attack = m_attack;
		}

		return attack;
	}

	const Hero& operator*(const Hero& left, const Hero& right)
	{
		int round = 0;
		
		Hero leftHero = left;
		Hero rightHero = right;

		const Hero* winner = &leftHero;

		bool isDead = false;

		for (int i = 0; i < MAX_ROUNDS && !isDead; i++)
		{
			round = i + 1;
			leftHero-=(rightHero.attackStrength());
			rightHero-=(leftHero.attackStrength());

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

		cout << "Ancient Battle! "
			<< left << " vs " << right
			<< " : Winner is " << *winner
			<< " in " << round << " rounds." << endl;

		return *winner;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero)
	{
		return hero.display(os);
	}

	std::ostream& Hero::display(std::ostream& os) const
	{
		if (m_name[0] != '\0')
			os << m_name;
		else
			os << "No hero";

		return os;
	}
}