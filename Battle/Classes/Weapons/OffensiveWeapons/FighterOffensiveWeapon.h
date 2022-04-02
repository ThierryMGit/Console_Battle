#pragma once

// Permet de créer une arme offensive

#include <string>

class FighterOffensiveWeapon
{
	public:
		// Arme offensive avec dégâts de base
		FighterOffensiveWeapon();

		// Arme offensive dont les dégâts sont définis librement
		FighterOffensiveWeapon(int damage);

		virtual ~FighterOffensiveWeapon();

		// Retourne le nom de l'arme en chaîne de caractères
		virtual std::string getStringName() const { return "Poings"; };

		// Accesseurs sur les dégâts
		int getDamage() { return _damage; };

	protected:
		int _damage;	
};

