#pragma once

// Cr�er une interface permettant d'int�ragir avec le combattant

#include <memory>
#include <string>

class Controller
{
	public:
		// Constructeur avec le mod�le utilis�
		Controller(std::shared_ptr<class Fighter> fighter);

		virtual ~Controller();

		// Actions r�alisables par un combattant durant un tour de jeu
		virtual void useSkill(std::shared_ptr<Fighter> enemy) = 0;
		virtual void attack(std::shared_ptr<Fighter> enemy) = 0;

		virtual std::string getFighterStatus() = 0;
		virtual std::string getControllerName() = 0;

		std::shared_ptr<class Fighter> getFighter() { return _fighter; };

	protected:
		int _id;
		std::shared_ptr<class Fighter> _fighter;
};

