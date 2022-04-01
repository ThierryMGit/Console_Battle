#pragma once

// Permet de cr�er une arme avec plusieurs niveaux de libert� sur ses caract�ristiques

class FighterOffensiveWeapon
{
	public:
		enum class Type {
			SWORD,
			AXE,
			NONE
		};

		// Arme dont les caract�ristiques sont d�finies par son type
		FighterOffensiveWeapon(Type type);

		// Arme dont les caract�ristiques sont d�finies librement
		FighterOffensiveWeapon(Type type, int damage);

		// Accesseurs sur les variables de la classe
		Type getType() { return _type; };
		int getDamage() { return _damage; };

	private:
		Type _type;
		int _damage;
};

