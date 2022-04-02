#pragma once

// Permet de cr�er une arme offensive

#include <string>

class FighterOffensiveWeapon
{
	public:
		// Arme offensive avec d�g�ts de base
		FighterOffensiveWeapon();

		// Arme offensive dont les d�g�ts sont d�finis librement
		FighterOffensiveWeapon(int damage);

		virtual ~FighterOffensiveWeapon();

		// Retourne le nom de l'arme en cha�ne de caract�res
		virtual std::string getStringName() const { return "Poings"; };

		// Accesseurs sur les d�g�ts
		int getDamage() { return _damage; };

	protected:
		int _damage;	
};

