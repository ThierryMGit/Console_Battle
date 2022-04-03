#pragma once

// Classe gérant le déroulement de la bataille

#include <memory>
#include <queue>

class Game
{
	public:
		Game();

		// Lancement de la bataille
		void run();

	private:
		// Combattants prédéfinis pour se battre (Un chevalier et un orc)
		std::shared_ptr<class Knight> _knight;
		std::shared_ptr<class Orc> _orc;

	private:
		// Différents états de jeu
		void _introState();
		void _fightState(); // Détermination du combattant commençant en premier et gestion du combat
		void _endState(); // Annonce du combattant victorieux

		// Phases de combat
		void _fightSkillPhase(std::queue<std::shared_ptr<class Fighter>> fightersQueue); // Utilisation de capacité
		void _fightAttackPhase(std::queue<std::shared_ptr<class Fighter>> fightersQueue); // Attaque

		// Détermination de l'ordre de passage des combattants pendant un tour de jeu et construction de la file de combattants initiale 
		void _initFightersQueue(std::queue<std::shared_ptr<class Fighter>>& fightersQueue);
};

