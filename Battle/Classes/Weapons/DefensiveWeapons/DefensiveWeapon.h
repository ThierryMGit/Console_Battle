#pragma once

// Permet de créer une arme défensive

#include <string>

class DefensiveWeapon
{
	public:
		// Arme défensive avec un nom libre et une quantité d'armure de base
		DefensiveWeapon(std::string name);

		// Arme défensive dont le nom et la quantité d'armure est définie librement
		DefensiveWeapon(std::string name, int armor);

		virtual ~DefensiveWeapon();

		// Accesseurs sur la quantité d'armure
		int getArmor() { return _armor; };
		std::string getName() { return _name; };

		void setArmor(int armor) { _armor = armor; };

	protected:
		std::string _name;
		int _armor;	
};

