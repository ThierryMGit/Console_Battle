#pragma once

// Classe gérant le déroulement de la bataille

#include <memory>
#include <queue>
#include "Fighters/Knight.h"
#include "Fighters/Orc.h"

class Game
{
	public:
		Game();

		// Lancement de la bataille
		void run();

	private:
		// Combattants prédéfinis pour se battre (Un chevalier et un orc)
		std::shared_ptr<Knight> _knight;
		std::shared_ptr<Orc> _orc;

	private:
		// Différents états de jeu
		void _introState();
		void _fightState(); // Détermination du combattant commençant en premier et gestion du combat
		void _endState(); // Annonce du combattant victorieux

		// Détermination de l'ordre de passage des combattants pendant un tour de jeu et construction de la file de combattants initiale 
		void _initFightersQueue(std::queue<std::shared_ptr<Fighter>>& fightersQueue);
};

