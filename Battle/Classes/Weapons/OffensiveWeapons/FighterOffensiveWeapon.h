#pragma once

// Permet de créer une arme avec plusieurs niveaux de liberté sur ses caractéristiques

class FighterOffensiveWeapon
{
	public:
		enum class Type {
			SWORD,
			AXE,
			NONE
		};

		// Arme dont les caractéristiques sont définies par son type
		FighterOffensiveWeapon(Type type);

		// Arme dont les caractéristiques sont définies librement
		FighterOffensiveWeapon(Type type, int damage);

		// Accesseurs sur les variables de la classe
		Type getType() { return _type; };
		int getDamage() { return _damage; };

	private:
		Type _type;
		int _damage;
};

