#pragma once

// Permet de cr�er une capacit�

#include <memory> 
#include <string>
#include "../Effects/Effect.h"

class Skill
{
	public:
		enum class Type {
			ACTIVE, // Effet sur un autre combattant
			PASSIVE // Effet sur soi-m�me
		};

		// Construction d'une capacit� avec id, nom, temps de recharge, taux de r�ussite et son effet appliqu�
		Skill(Type type, std::string name, int cooldown, float successRate, std::shared_ptr<Effect> effect);

		virtual ~Skill();

		/* D�finit les condition et cons�quence de l'utilisation de la capacit� sur le combattant pass� en param�tre
		* et renvoi true si elle est utilis�e avec succ�s
		*/
		bool use(std::shared_ptr<class Fighter> fighter);

		// Mise � jour du temps de recharge
		void updateCooldown();

		Type getType() { return _type; };
		std::string getName() const { return _name; };
		int getRemainingCooldown() { return _remainingCooldown; };
		std::shared_ptr<Effect> getEffect() { return _effect; };

	protected:
		Type _type;
		std::string _name; // Nom de la comp�tence
		int _initialCooldown;// Temps de recharge total avant prochaine utilisation
		int _remainingCooldown;// Temps de recharge restant (en nombre de tours) avant utilisation
		float _successRate; // Taux de r�ussite
		std::shared_ptr<Effect> _effect; // Effet appliqu� par la capacit�
		bool _used; // Permet de marquer son utilisation durant le tour n et d'activer son temps de recharge au d�but du tour n + 1
};

