#pragma once

// Permet de cr�er une arme d�fensive

class FighterDefensiveWeapon
{
	public:
		// Arme d�fensive avec quantit� d'armure de base
		FighterDefensiveWeapon();

		// Arme d�fensive dont la quantit� d'armure est d�finie librement
		FighterDefensiveWeapon(int armor);

		virtual ~FighterDefensiveWeapon();

		// Accesseurs sur la quantit� d'armure
		int getArmor() { return _armor; };
		void setArmor(int armor) { _armor = armor; };

	protected:
		int _armor;	
};

