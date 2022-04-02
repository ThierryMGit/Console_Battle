#pragma once

// Permet de créer une arme défensive

class FighterDefensiveWeapon
{
	public:
		// Arme défensive avec quantité d'armure de base
		FighterDefensiveWeapon();

		// Arme défensive dont la quantité d'armure est définie librement
		FighterDefensiveWeapon(int armor);

		virtual ~FighterDefensiveWeapon();

		// Accesseurs sur la quantité d'armure
		int getArmor() { return _armor; };
		void setArmor(int armor) { _armor = armor; };

	protected:
		int _armor;	
};

