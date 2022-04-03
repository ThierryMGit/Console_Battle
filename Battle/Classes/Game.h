#pragma once

// Classe g�rant le d�roulement de la bataille

#include <memory>
#include <queue>

class Game
{
	public:
		Game();

		// Lancement de la bataille
		void run();

	private:
		// Combattants pr�d�finis pour se battre (Un chevalier et un orc)
		std::shared_ptr<class Knight> _knight;
		std::shared_ptr<class Orc> _orc;

	private:
		// Diff�rents �tats de jeu
		void _introState();
		void _fightState(); // D�termination du combattant commen�ant en premier et gestion du combat
		void _endState(); // Annonce du combattant victorieux

		// Phases de combat
		void _fightSkillPhase(std::queue<std::shared_ptr<class Fighter>> fightersQueue); // Utilisation de capacit�
		void _fightAttackPhase(std::queue<std::shared_ptr<class Fighter>> fightersQueue); // Attaque

		// D�termination de l'ordre de passage des combattants pendant un tour de jeu et construction de la file de combattants initiale 
		void _initFightersQueue(std::queue<std::shared_ptr<class Fighter>>& fightersQueue);
};

