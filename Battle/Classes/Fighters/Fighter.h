#pragma once

// Permet de créer un combattant avec plusieurs niveaux de liberté sur ses caractéristiques

#include <memory> 
#include <string>
#include "../Weapons/OffensiveWeapons/FighterOffensiveWeapon.h"

class Fighter
{
	public:
		enum class Type {
			KNIGHT,
			ORC
		};

		// Combattant dont le type définit ses caractéristiques
		Fighter(Type type);

		// Combattant avec liberté de valeur sur ses caractéristiques et celles de son arme
		Fighter(Type type, int life, int armor = 0, std::unique_ptr<FighterOffensiveWeapon> weapon = std::make_unique<FighterOffensiveWeapon>(FighterOffensiveWeapon::Type::NONE));

		// Combattant avec liberté de valeur sur ses caractéristiques et avec une arme dont les caractéristiques sont définies par son type
		Fighter(Type type, int life, int armor = 0, FighterOffensiveWeapon::Type weaponType = FighterOffensiveWeapon::Type::NONE);
		
		virtual ~Fighter();

		// Le combattant attaque un ennemi passé en paramètre
		void attack(std::shared_ptr<Fighter> enemy);

		// Le combattant encaisse les dommages
		void takeDamage(int damage);

		// Affiche la description d'un Combattant
		operator std::string() const;

		// Retourne le type du combattant en chaîne de caractères
		std::string getStringType() const;
		
		// Accesseurs sur les variables de la classe
		Type getType() { return _type; };
		int getLife() { return _life; };

	protected:
		Type _type;
		int _life;
		int _armor;
		std::unique_ptr<FighterOffensiveWeapon> _offensiveWeapon;
};

