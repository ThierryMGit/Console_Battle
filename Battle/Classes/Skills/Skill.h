#pragma once

// Permet de créer une capacité

#include <memory> 
#include <string>
#include "../Effects/Effect.h"

class Skill
{
	public:
		enum class Type {
			ACTIVE, // Effet sur un autre combattant
			PASSIVE // Effet sur soi-même
		};

		// Construction d'une capacité avec id, nom, temps de recharge, taux de réussite et son effet appliqué
		Skill(Type type, std::string name, int cooldown, float successRate, std::shared_ptr<Effect> effect);

		virtual ~Skill();

		/* Définit les condition et conséquence de l'utilisation de la capacité sur le combattant passé en paramètre
		* et renvoi true si elle est utilisée avec succès
		*/
		bool use(std::shared_ptr<class Fighter> fighter);

		// Mise à jour du temps de recharge
		void updateCooldown();

		Type getType() { return _type; };
		std::string getName() const { return _name; };
		int getRemainingCooldown() { return _remainingCooldown; };
		std::shared_ptr<Effect> getEffect() { return _effect; };

	protected:
		Type _type;
		std::string _name; // Nom de la compétence
		int _initialCooldown;// Temps de recharge total avant prochaine utilisation
		int _remainingCooldown;// Temps de recharge restant (en nombre de tours) avant utilisation
		float _successRate; // Taux de réussite
		std::shared_ptr<Effect> _effect; // Effet appliqué par la capacité
		bool _used; // Permet de marquer son utilisation durant le tour n et d'activer son temps de recharge au début du tour n + 1
};

