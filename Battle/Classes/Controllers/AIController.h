#pragma once

// Permet à une IA de controler un combattant

#include "Controller.h"

class AIController :
    public Controller
{
public:
    static int instanceCount;

    AIController(std::shared_ptr<class Fighter> fighter);

    ~AIController();

    // Actions réalisables par un combattant durant un tour de jeu
    void useSkill(std::shared_ptr<Fighter> enemy) override;
    void attack(std::shared_ptr<Fighter> enemy) override;

    std::string getFighterStatus() override;
    std::string getControllerName() override;
};
