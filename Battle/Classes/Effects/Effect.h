#pragma once

// Permet de créer un effet infligé par une capacité

#include <string>

class Effect
{
	public:
		enum class ID {
			STUN,
			CHARGE
		};

		Effect(ID id, std::string description, int activeDuration);

		~Effect();

		// Décrémentation de la durée pendant lequel l'effet est actif et renvoi la durée restante actualisée
		int updateActiveDuration();

		ID getID() { return _id; };
		std::string getDescription() const { return _description; };
		int getInitialActiveDuration() { return _initialActiveDuration; };
		int getRemainingActiveDuration() { return _remainingActiveDuration; };

	private:
		ID _id;
		std::string _description;
		int _initialActiveDuration; // Durée pendant lequel l'effet est actif (en nombre de tours)
		int _remainingActiveDuration; // Durée restante pendant lequel l'effet est actif (en nombre de tours)
};

