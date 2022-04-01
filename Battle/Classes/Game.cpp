#include "Game.h"
#include <iostream>
#include <stdlib.h>

Game::Game() : _knight(std::make_shared<Knight>()), _orc(std::make_shared<Orc>()) {}

void Game::run()
{
    srand(time(NULL)); // Pour le tirage au sort du combattant qui commencera

    _introState();
}

void Game::_introState()
{
    std::cout << "Que la bataille commence !!\n\n";
    _fightState();
}

void Game::_fightState()
{
    if (!_knight || !_orc) return;
    
    // Compteur des tours de jeu
    int turnCount = 1;

    // Gestion de l'ordre des combattants en action grâce à une file
    std::queue<std::shared_ptr<Fighter>> currentTurnFightersQueue;

    // Permet de garder l'ordre de passage au tour suivant
    std::queue<std::shared_ptr<Fighter>> nextTurnFightersQueue;

    // Détermination du combattant qui commencera
    _initFightersQueue(currentTurnFightersQueue);

    // Affichage de la description des combattants
    std::cout << std::string(*(_knight.get())) << "\n";
    std::cout << std::string(*(_orc.get())) << "\n";

    // Boucle de combat tant que l'orc et le chevalier sont vivants
    do {
        // Affichage du nombre de tours
        std::cout << "**** Tour " << turnCount << " **** \n\n";

        // Boucle d'un tour de jeu d'un combattant tant que les deux sont vivants et qu'il y a au moins un combattant restant à effectuer des actions
        while (_knight->getLife() > 0 && _orc->getLife() > 0 && !currentTurnFightersQueue.empty()) {

            // Récupération du combattant dont c'est le tour de jouer
            std::shared_ptr<Fighter> currentTurnFighter = currentTurnFightersQueue.front();

            // Suppression du combattant de la file pour qu'il ne joue qu'une fois par tour
            currentTurnFightersQueue.pop();

            /* En fonction du type du combattant courant, il va attaquer son ennemi correspondant
            * Chevalier attaque Orc et inversement
            * Puis ajout du combattant courant dans la file de combattant pour le prochain tour
            */
            if (currentTurnFighter->getType() == Fighter::Type::KNIGHT) {
                _knight->attack(_orc);
                nextTurnFightersQueue.push(_knight);
            }
            else {
                _orc->attack(_knight);
                nextTurnFightersQueue.push(_orc);
            }

            // Affichage de la description des combattants après les actions du combattant courant
            std::cout << std::string(*(_knight.get())) << "\n";
            std::cout << std::string(*(_orc.get())) << "\n";
        }
        // Arrivée à ce niveau si un combattant est mort ou que le chevalier et l'orc ont déjà agi pendant un tour 

        // Configuration pour préparer le prochain tour -> la file du tour n + 1 contient les combattants et la file du tour n + 2 devient vide
        currentTurnFightersQueue.swap(nextTurnFightersQueue);

        // Tour suivant
        turnCount++;
    } while (_knight->getLife() > 0 && _orc->getLife() > 0);

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


