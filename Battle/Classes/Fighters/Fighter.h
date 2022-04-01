#pragma once

// Permet de cr�er un combattant avec plusieurs niveaux de libert� sur ses caract�ristiques

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

		// Combattant dont le type d�finit ses caract�ristiques
		Fighter(Type type);

		// Combattant avec libert� de valeur sur ses caract�ristiques et celles de son arme
		Fighter(Type type, int life, int armor = 0, std::unique_ptr<FighterOffensiveWeapon> weapon = std::make_unique<FighterOffensiveWeapon>(FighterOffensiveWeapon::Type::NONE));

		// Combattant avec libert� de valeur sur ses caract�ristiques et avec une arme dont les caract�ristiques sont d�finies par son type
		Fighter(Type type, int life, int armor = 0, FighterOffensiveWeapon::Type weaponType = FighterOffensiveWeapon::Type::NONE);
		
		virtual ~Fighter();

		// Le combattant attaque un ennemi pass� en param�tre
		void attack(std::shared_ptr<Fighter> enemy);

		// Le combattant encaisse les dommages
		void takeDamage(int damage);

		// Affiche la description d'un Combattant
		operator std::string() const;

		// Retourne le type du combattant en cha�ne de caract�res
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

