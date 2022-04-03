#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include "Fighters/Knight.h"
#include "Fighters/Orc.h"

Game::Game() : _knight(std::make_shared<Knight>()), _orc(std::make_shared<Orc>()) {}

void Game::run()
{
    srand((unsigned int)time(NULL)); // Pour le tirage au sort du combattant qui commencera

    _introState();
}

void Game::_introState()
{
    std::cout << "###** BATAILLE ***### \n\n";
    std::cout << "Présentation des combattants : \n\n";

    std::cout << std::string(*(_knight.get())) << "\n";
    std::cout << std::string(*(_orc.get())) << "\n";

    int input;
    do {
        std::cin.clear();
        std::cout << "Appuyez sur entrée pour débuter le combat\n\n";
        input = std::cin.get();
    } while (input != 10);
    

    _fightState();
}

void Game::_fightState()
{
    if (!_knight || !_orc) return;
    
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
                std::cin.clear();
                std::cout << "Appuyez sur entrée pour passer au tour suivant\n\n";
                input = std::cin.get();
            } while (input != 10);
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
        std::cout << std::string(*(_knight.get())) << "\n";
        std::cout << std::string(*(_orc.get())) << "\n";
       
        // Tour suivant
        turnCount++;
    }

    // Un des deux combattants est mort -> Fin de la bataille
    _endState();
}

void Game::_endState()
{
    std::cout << "#### Fin de la partie ####" << "\n\n";
    std::cout << "Victoire " << ((_knight->getLife() > 0) ?
        "du Chevalier" :
        "de l'Orc") <<
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

        // Utilisation de la capacité du combattant courant en faisant passer en paramètre lui-même et son ennemi
        if (currentTurnFighter->getType() == Fighter::Type::KNIGHT) {
            currentTurnFighter->useSkill(currentTurnFighter, _orc);
        } else {
            currentTurnFighter->useSkill(currentTurnFighter, _knight);
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

        /* En fonction du type du combattant courant, il va attaquer son ennemi correspondant
        * Chevalier attaque Orc et inversement
        * Puis ajout du combattant courant dans la file de combattant pour le prochain tour
        */
        if (currentTurnFighter->getType() == Fighter::Type::KNIGHT) {
            currentTurnFighter->attack(_orc);
        } else {
            currentTurnFighter->attack(_knight);
        }
    }
}



void Game::_initFightersQueue(std::queue<std::shared_ptr<Fighter>>& fightersQueue)
{
    std::cout << "Qui commencera le combat ?" << std::endl;
    Fighter::Type fighterTypeToStart = (rand() % 101) >= 50 ?
        Fighter::Type::KNIGHT :
        Fighter::Type::ORC;
    if (fighterTypeToStart == Fighter::Type::KNIGHT) {
        fightersQueue.push(_knight);
        fightersQueue.push(_orc);

        std::cout << "Le chevalier !\n\n";
    }
    else {
        fightersQueue.push(_orc);
        fightersQueue.push(_knight);

        std::cout << "L'orc !\n\n";
    }
}


