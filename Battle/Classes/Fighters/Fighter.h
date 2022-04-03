#pragma once

// Permet de cr�er un combattant

#include <memory> 
#include <string>
#include "../Weapons/OffensiveWeapons/OffensiveWeapon.h"
#include "../Weapons/DefensiveWeapons/DefensiveWeapon.h"
#include "../Skills/Skill.h"

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
		Fighter(Type type, int life, std::unique_ptr<OffensiveWeapon> offensiveWeapon = std::make_unique<OffensiveWeapon>(), std::unique_ptr<DefensiveWeapon> defensiveWeapon = nullptr, std::unique_ptr<Skill> skill = nullptr);
		
		virtual ~Fighter();

		// Le combattant utilise une capacit� avec en param�tre l'ennemi et moi
		void useSkill(std::shared_ptr<Fighter> me, std::shared_ptr<Fighter> enemy);

		// Le combattant a un effet appliqu� sur lui
		void applyEffect(std::shared_ptr<Effect> effect) { _effect = effect; };

		// Le combattant attaque un ennemi pass� en param�tre
		void attack(std::shared_ptr<Fighter> enemy);

		// Le combattant encaisse les dommages
		void takeDamage(int damage);

		// Actualisation du statut de la capacit� poss�d�e et de l'effet appliqu�
		void updateSkillAndEffectStatus();

		// Affiche la description d'un combattant
		virtual operator std::string() const;
		
		// Accesseurs sur les variables de la classe
		Type getType() { return _type; };
		int getLife() { return _life; };

	protected:
		Type _type; 
		int _life; // Points de vie
		std::unique_ptr<DefensiveWeapon> _defensiveWeapon; // Arme d�fensive ("Bouclier")
		std::unique_ptr<OffensiveWeapon> _offensiveWeapon; // Arme offensive ("Hache", "�p�e")
		std::unique_ptr<Skill> _skill; // Capacit� ("Stun", "Charge")
		std::shared_ptr<Effect> _effect; // Effet appliqu� par une capacit�

	protected:
		// Retourne le type du combattant en cha�ne de caract�res
		virtual std::string getStringType() const { return "Soldat"; };

		// Actualisation du temps de recharge de la capacit�
		void _updateSkillStatus(); 

		// Actualisation du temps actif de l'effet et suppression si fin du temps
		void _updateEffectStatus();
};

