#include "AIController.h"
#include "../Fighters/Fighter.h"

int AIController::instanceCount = 1;

AIController::AIController(std::shared_ptr<class Fighter> fighter) : Controller(fighter) 
{
	_id = instanceCount;
	instanceCount++;
}

AIController::~AIController() {}

void AIController::useSkill(std::shared_ptr<Fighter> enemy)
{
	if (!_fighter->isSkillUsable()) return;

	_fighter->useSkill(_fighter, enemy);
}

void AIController::attack(std::shared_ptr<Fighter> enemy)
{
	_fighter->attack(enemy);
}

std::string AIController::getFighterStatus()
{
	return getControllerName() + "\n" + _fighter->getStatus();
}

std::string AIController::getControllerName()
{
	return "IA " + std::to_string(_id);
}
