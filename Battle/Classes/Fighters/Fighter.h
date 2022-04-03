#pragma once

// Permet de créer un combattant

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

		// Combattant avec liberté de valeur sur ses caractéristiques
		Fighter(Type type, int life, std::unique_ptr<OffensiveWeapon> offensiveWeapon = std::make_unique<OffensiveWeapon>(), std::unique_ptr<DefensiveWeapon> defensiveWeapon = nullptr, std::unique_ptr<Skill> skill = nullptr);
		
		virtual ~Fighter();

		// Le combattant utilise une capacité avec en paramètre l'ennemi et moi
		void useSkill(std::shared_ptr<Fighter> me, std::shared_ptr<Fighter> enemy);

		// Le combattant a un effet appliqué sur lui
		void applyEffect(std::shared_ptr<Effect> effect) { _effect = effect; };

		// Le combattant attaque un ennemi passé en paramètre
		void attack(std::shared_ptr<Fighter> enemy);

		// Le combattant encaisse les dommages
		void takeDamage(int damage);

		// Actualisation du statut de la capacité possédée et de l'effet appliqué
		void updateSkillAndEffectStatus();

		// Affiche la description d'un combattant
		virtual operator std::string() const;
		
		// Accesseurs sur les variables de la classe
		Type getType() { return _type; };
		int getLife() { return _life; };

	protected:
		Type _type; 
		int _life; // Points de vie
		std::unique_ptr<DefensiveWeapon> _defensiveWeapon; // Arme défensive ("Bouclier")
		std::unique_ptr<OffensiveWeapon> _offensiveWeapon; // Arme offensive ("Hache", "Épée")
		std::unique_ptr<Skill> _skill; // Capacité ("Stun", "Charge")
		std::shared_ptr<Effect> _effect; // Effet appliqué par une capacité

	protected:
		// Retourne le type du combattant en chaîne de caractères
		virtual std::string getStringType() const { return "Soldat"; };

		// Actualisation du temps de recharge de la capacité
		void _updateSkillStatus(); 

		// Actualisation du temps actif de l'effet et suppression si fin du temps
		void _updateEffectStatus();
};

