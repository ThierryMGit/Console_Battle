#include "PlayerController.h"
#include "../Fighters/Fighter.h"
#include <iostream>

int PlayerController::instanceCount = 1;

PlayerController::PlayerController(std::shared_ptr<class Fighter> fighter) : Controller(fighter)
{
	_id = instanceCount;
	instanceCount++;
}

PlayerController::~PlayerController(){}

void PlayerController::useSkill(std::shared_ptr<Fighter> enemy)
{
	if (!_fighter->isSkillUsable()) return;

	// Intéraction avec le joueur pour savoir si la capacité doit être utilisée -> o pour oui/ n pour non
	char inputUseSkill;
	do {
		std::cout << getControllerName() << " - Voulez vous utiliser votre capacité ? [o/n]";
		std::cin >> inputUseSkill;
		std::cout << "\n";
	} while (!std::cin.fail() && inputUseSkill != 'o' && inputUseSkill != 'n');

	if (inputUseSkill == 'o') {
		_fighter->useSkill(_fighter, enemy);
	} else {
		std::cout << "Capacité non utilisée\n\n";
	}
	std::cin.ignore();
}

void PlayerController::attack(std::shared_ptr<Fighter> enemy)
{
	_fighter->attack(enemy);
}

std::string PlayerController::getFighterStatus()
{
	return getControllerName() + "\n" + _fighter->getStatus();
}

std::string PlayerController::getControllerName()
{
	return "Joueur " + std::to_string(_id);
}
