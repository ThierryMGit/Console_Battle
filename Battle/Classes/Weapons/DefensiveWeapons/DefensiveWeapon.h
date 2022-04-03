#pragma once

// Permet de cr�er une arme d�fensive

#include <string>

class DefensiveWeapon
{
	public:
		// Arme d�fensive avec un nom libre et une quantit� d'armure de base
		DefensiveWeapon(std::string name);

		// Arme d�fensive dont le nom et la quantit� d'armure est d�finie librement
		DefensiveWeapon(std::string name, int armor);

		virtual ~DefensiveWeapon();

		// Accesseurs sur la quantit� d'armure
		int getArmor() { return _armor; };
		std::string getName() { return _name; };

		void setArmor(int armor) { _armor = armor; };

	protected:
		std::string _name;
		int _armor;	
};

