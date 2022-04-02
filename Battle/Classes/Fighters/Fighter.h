#pragma once

// Permet de cr�er un combattant

#include <memory> 
#include <string>
#include "../Weapons/OffensiveWeapons/FighterOffensiveWeapon.h"
#include "../Weapons/DefensiveWeapons/FighterDefensiveWeapon.h"

class Fighter
{
	public:
		enum class Type {
			KNIGHT,
			ORC,
			SOLDIER
		};

		// Combattant de base -> Soldat avec 10 points de vie combattant avec ses poings
		Fighter();

		// Combattant avec libert� de valeur sur ses caract�ristiques
		Fighter(Type type, int life, std::unique_ptr<FighterOffensiveWeapon> offensiveWeapon = std::make_unique<FighterOffensiveWeapon>(), std::unique_ptr<FighterDefensiveWeapon> defensiveWeapon = nullptr);
		
		virtual ~Fighter();

		// Le combattant attaque un ennemi pass� en param�tre
		void attack(std::shared_ptr<Fighter> enemy);

		// Le combattant encaisse les dommages
		void takeDamage(int damage);

		// Affiche la description d'un combattant
		virtual operator std::string() const;
		
		// Accesseurs sur les variables de la classe
		Type getType() { return _type; };
		int getLife() { return _life; };

	protected:
		Type _type;
		int _life;
		std::unique_ptr<FighterDefensiveWeapon> _defensiveWeapon;
		std::unique_ptr<FighterOffensiveWeapon> _offensiveWeapon;

	protected:
		// Retourne le type du combattant en cha�ne de caract�res
		virtual std::string getStringType() const { return "Soldat"; };
};

