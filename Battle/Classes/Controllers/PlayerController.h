#pragma once

// Permet à un joueur de controler un combattant

#include "Controller.h"

class PlayerController :
    public Controller
{
    public:
        static int instanceCount;

        PlayerController(std::shared_ptr<class Fighter> fighter);

        ~PlayerController();

        // Actions réalisables par un combattant durant un tour de jeu
        void useSkill(std::shared_ptr<Fighter> enemy) override;
        void attack(std::shared_ptr<Fighter> enemy) override;

        std::string getFighterStatus() override;
        std::string getControllerName() override;
};
