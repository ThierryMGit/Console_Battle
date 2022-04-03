#pragma once

// Permet de créer une arme offensive

#include <string>

class OffensiveWeapon
{
	public:
		// Arme offensive avec dégâts de base
		OffensiveWeapon();

		// Arme offensive dont le nom et les dégâts sont définis librement
		OffensiveWeapon(std::string name, int damage);

		virtual ~OffensiveWeapon();

		// Accesseurs sur les dégâts
		int getDamage() { return _damage; };
		std::string getName() { return _name; };

	protected:
		std::string _name;
		int _damage;	
};

