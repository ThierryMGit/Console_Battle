#pragma once

// Permet de cr�er une arme offensive

#include <string>

class OffensiveWeapon
{
	public:
		// Arme offensive avec d�g�ts de base
		OffensiveWeapon();

		// Arme offensive dont le nom et les d�g�ts sont d�finis librement
		OffensiveWeapon(std::string name, int damage);

		virtual ~OffensiveWeapon();

		// Accesseurs sur les d�g�ts
		int getDamage() { return _damage; };
		std::string getName() { return _name; };

	protected:
		std::string _name;
		int _damage;	
};

