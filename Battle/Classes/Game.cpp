#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include "Fighters/Knight.h"
#include "Fighters/Orc.h"

Game::Game() : _knight(std::make_shared<Knight>()), _orc(std::make_shared<Orc>()) {}

void Game::run()
{
	srand((unsigned int)time(NULL)); // Pour le tirage au sort du combattant qui commencera

	_chooseModeState();
}

void Game::_chooseModeState()
{
	std::cout << "###** BATAILLE ***### \n\n";

	// Choix du mode de jeu
	int inputGameMode;
	do {
		std::cout << "Modes de jeu : \n";
		std::cout << "1 - Joueur contre IA \n";
		std::cout << "2 - Joueur contre Joueur \n";
		std::cout << "3 - IA contre IA \n";
		std::cout << "Veuillez taper un chiffre pour choisir le mode de jeu : ";
		std::cin >> inputGameMode;
		std::cout << "\n\n";
	} while (!std::cin.fail() && (inputGameMode < 1 || inputGameMode > 3));
	

	GameMode chosenGameMode = static_cast<GameMode>(inputGameMode);
	
	// Si le mode de jeu est IA contre IA -> pas besoin d'attendre un choix de combattant
	if (chosenGameMode == GameMode::AI_V_AI) {
		_controller1 = std::make_unique<AIController>(_knight);
		_controller2 = std::make_unique<AIController>(_orc);
	} else { // Choix de combattant pour le/les joueur/joueurs
		_chooseFighterState(chosenGameMode);
	}

	std::cout << "Présentation des combattants : \n\n";
	std::cout << _controller1->getFighterStatus() << "\n";
	std::cout << _controller2->getFighterStatus() << "\n";

	int input;
	do {
		std::cin.ignore();
		std::cout << "Appuyez sur entrée pour débuter le combat";		
		input = std::cin.get();
		std::cout << "\n\n";
	} while (!std::cin.fail() && input != 10);

	// Passage en phase de combat
	_fightState();
}

void Game::_chooseFighterState(GameMode currentGameMode)
{
	// Choix d'un combattant pour le joueur 1
	int inputChooseFighter;
	do {
		std::cout << "Combattants : \n";
		std::cout << "1 - Chevalier \n";
		std::cout << "2 - Orc \n";
		std::cout << "Joueur 1" << " - Veuillez taper un chiffre pour choisir votre combattant : ";
		std::cin >> inputChooseFighter;
		std::cout << "\n\n";
	} while (!std::cin.fail() && (inputChooseFighter < 1 || inputChooseFighter > 2));

	// En fonction du choix du joueur 1 -> il déterminera le combattant de l'autre joueur ou IA
	if (static_cast<Fighter::Type>(inputChooseFighter) == Fighter::Type::KNIGHT) {
		_controller1 = std::make_unique<PlayerController>(_knight);
		if (currentGameMode == GameMode::P_VS_P) {
			_controller2 = std::make_unique<PlayerController>(_orc);
		} else {
			_controller2 = std::make_unique<AIController>(_orc);
		}
	} else {
		_controller1 = std::make_unique<PlayerController>(_orc);
		if (currentGameMode == GameMode::P_VS_P) {
			_controller2 = std::make_unique<PlayerController>(_knight);
		}
		else {
			_controller2 = std::make_unique<AIController>(_knight);
		}
	}
}


void Game::_fightState()
{
	if (!_knight || !_orc || !_controller1 || !_controller2) return;

	// Compteur des tours de jeu
	int turnCount = 1;

	// Gestion de l'ordre des combattants en action grâce à une file
	std::queue<std::shared_ptr<Fighter>> currentTurnFightersQueue;

	// Détermination du combattant qui commencera
	_initFightersQueue(currentTurnFightersQueue);

	// Boucle de combat tant que l'orc et le chevalier sont vivants
	while (_knight->getLife() > 0 && _orc->getLife() > 0) {

		if (turnCount > 1) {
			int input;
			do {
				std::cout << "Appuyez sur entrée pour passer au tour suivant";
				input = std::cin.get();
				std::cout << "\n\n";
			} while (!std::cin.fail() && input != 10);
		}

		// Affichage du nombre de tours
		std::cout << "**** Tour " << turnCount << " **** \n\n";

		// Maj cooldown compétences/effets
		_knight->updateSkillAndEffectStatus();
		_orc->updateSkillAndEffectStatus();

		// Phase d'utilisation de capacité
		_fightSkillPhase(currentTurnFightersQueue);

		// Phase de combat
		_fightAttackPhase(currentTurnFightersQueue);

		// Affichage de la description des combattants après les actions du combattant courant
		std::cout << "Statut des combattants : " << "\n";
		std::cout << _controller1->getFighterStatus() << "\n";
		std::cout << _controller2->getFighterStatus() << "\n";

		// Tour suivant
		turnCount++;
	}

	// Un des deux combattants est mort -> Fin de la bataille
	_endState();
}

void Game::_endState()
{
	std::cout << "#### Fin de la partie ####" << "\n\n";
	std::cout << "Victoire  : " << ((_controller1->getFighter()->getLife() > 0) ?
		_controller1->getControllerName() :
		_controller2->getControllerName()) <<
		" !" << std::endl;
}

void Game::_fightSkillPhase(std::queue<std::shared_ptr<Fighter>> fightersQueue)
{
	std::cout << "#### Phase d'utilisation des capacités ####" << "\n\n";

	// Phase d'utilisation des capacités tant que les deux sont vivants et qu'il y a au moins un combattant restant à effectuer des actions
	while (_knight->getLife() > 0 && _orc->getLife() > 0 && !fightersQueue.empty()) {

		// Récupération du combattant dont c'est le tour de jouer
		std::shared_ptr<Fighter> currentTurnFighter = fightersQueue.front();

		// Suppression du combattant de la file pour qu'il ne joue qu'une fois dans cette phase
		fightersQueue.pop();

		if (_controller1->getFighter()->getId() == currentTurnFighter->getId()) {
			std::cout << "Au tour de -> " << _controller1->getControllerName() << "\n";
		} else {
			std::cout << "Au tour de -> " << _controller2->getControllerName() << "\n";
		}

		// Identification du bon controller et ennemi du combattant courant puis gestion
		// de l'utilisation de sa capacité par le controller
		if (currentTurnFighter->getType() == Fighter::Type::KNIGHT) {
			if (_controller1->getFighter()->getId() == currentTurnFighter->getId()) {
				_controller1->useSkill(_orc);
			} else {
				_controller2->useSkill(_orc);
			}
		} else {
			if (_controller1->getFighter()->getId() == currentTurnFighter->getId()) {
				_controller1->useSkill(_knight);
			} else {
				_controller2->useSkill(_knight);
			}
		}
	}
}

void Game::_fightAttackPhase(std::queue<std::shared_ptr<Fighter>> fightersQueue)
{
	std::cout << "#### Phase d'attaque ####" << "\n\n";

	// Phase d'attaque tant que les deux sont vivants et qu'il y a au moins un combattant restant à effectuer des actions
	while (_knight->getLife() > 0 && _orc->getLife() > 0 && !fightersQueue.empty()) {

		// Récupération du combattant dont c'est le tour de jouer
		std::shared_ptr<Fighter> currentTurnFighter = fightersQueue.front();

		// Suppression du combattant de la file pour qu'il ne joue qu'une fois dans cette phase
		fightersQueue.pop();

		if (_controller1->getFighter()->getId() == currentTurnFighter->getId()) {
			std::cout << "Au tour de -> " << _controller1->getControllerName() << "\n";
		} else {
			std::cout << "Au tour de -> " << _controller2->getControllerName() << "\n";
		}

		// Identification du bon controller et ennemi du combattant courant puis gestion
		// de l'attaque par le controller
		if (currentTurnFighter->getType() == Fighter::Type::KNIGHT) {
			if (_controller1->getFighter()->getId() == currentTurnFighter->getId()) {
				_controller1->attack(_orc);
			} else {
				_controller2->attack(_orc);
			}
		} else {
			if (_controller1->getFighter()->getId() == currentTurnFighter->getId()) {
				_controller1->attack(_knight);
			} else {
				_controller2->attack(_knight);
			}
		}
	}
}



void Game::_initFightersQueue(std::queue<std::shared_ptr<Fighter>>& fightersQueue)
{
	std::cout << "Qui commencera le combat ? ";
	int toss = (rand() % 101) >= 50; // 0-49 controller 1 commence | 50-100 controller 2 commence
	if (toss < 50) {
		fightersQueue.push(_controller1->getFighter());
		fightersQueue.push(_controller2->getFighter());

		std::cout << _controller1->getControllerName() << " !\n\n";
	} else {
		fightersQueue.push(_controller2->getFighter());
		fightersQueue.push(_controller1->getFighter());

		std::cout << _controller2->getControllerName() << " !\n\n";
	}
}


