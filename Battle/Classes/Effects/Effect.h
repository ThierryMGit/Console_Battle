#pragma once

// Permet de cr�er un effet inflig� par une capacit�

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

		// D�cr�mentation de la dur�e pendant lequel l'effet est actif et renvoi la dur�e restante actualis�e
		int updateActiveDuration();

		ID getID() { return _id; };
		std::string getDescription() const { return _description; };
		int getInitialActiveDuration() { return _initialActiveDuration; };
		int getRemainingActiveDuration() { return _remainingActiveDuration; };

	private:
		ID _id;
		std::string _description;
		int _initialActiveDuration; // Dur�e pendant lequel l'effet est actif (en nombre de tours)
		int _remainingActiveDuration; // Dur�e restante pendant lequel l'effet est actif (en nombre de tours)
};

