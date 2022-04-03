#pragma once

// Créer une interface permettant d'intéragir avec le combattant

#include <memory>
#include <string>

class Controller
{
	public:
		// Constructeur avec le modèle utilisé
		Controller(std::shared_ptr<class Fighter> fighter);

		virtual ~Controller();

		// Actions réalisables par un combattant durant un tour de jeu
		virtual void useSkill(std::shared_ptr<Fighter> enemy) = 0;
		virtual void attack(std::shared_ptr<Fighter> enemy) = 0;

		virtual std::string getFighterStatus() = 0;
		virtual std::string getControllerName() = 0;

		std::shared_ptr<class Fighter> getFighter() { return _fighter; };

	protected:
		int _id;
		std::shared_ptr<class Fighter> _fighter;
};

