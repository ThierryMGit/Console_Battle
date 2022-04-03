#pragma once

// Classe gérant le déroulement de la bataille

#include <memory>
#include <queue>
#include "Controllers/AIController.h"
#include "Controllers/PlayerController.h"

class Game
{
	public:
		enum class GameMode {
			P_VS_AI = 1, // Joueur contre IA
			P_VS_P, // Joueur contre Joueur
			AI_V_AI // IA contre IA
		};

		Game();

		// Lancement de la bataille
		void run();

	private:
		// Models Combattants prédéfinis pour se battre (Un chevalier et un orc)
		std::shared_ptr<class Knight> _knight;
		std::shared_ptr<class Orc> _orc;

		// IA/Joueur prévus pour contrôler chacun un combattant
		std::unique_ptr<class Controller> _controller1;
		std::unique_ptr<class Controller> _controller2;

	private:
		// Différents états de jeu
		void _chooseModeState(); // Choix du mode de jeu (Joueur vs IA, Joueur vs Joueur, IA vs IA)
		void _chooseFighterState(GameMode currentGameMode); // Choix du type de combattant à contrôler (si mode Joueur vs IA ou Joueur vs Joueur) 
		void _fightState(); // Détermination du combattant commençant en premier et gestion du combat
		void _endState(); // Annonce du combattant victorieux

		// Phases de combat
		void _fightSkillPhase(std::queue<std::shared_ptr<class Fighter>> fightersQueue); // Utilisation de capacité
		void _fightAttackPhase(std::queue<std::shared_ptr<class Fighter>> fightersQueue); // Attaque

		// Détermination de l'ordre de passage des combattants pendant un tour de jeu et construction de la file de combattants initiale 
		void _initFightersQueue(std::queue<std::shared_ptr<class Fighter>>& fightersQueue);
};

