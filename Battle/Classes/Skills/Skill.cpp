#include "Skill.h"
#include "../Fighters/Fighter.h"
#include <iostream>

Skill::Skill(Type type, std::string name, int cooldown, float successRate, std::shared_ptr<Effect> effect) :
	_type(type), _name(name), _initialCooldown(cooldown), _remainingCooldown(0), _successRate(successRate), _effect(effect), _used(false) {}

Skill::~Skill(){}

bool Skill::use(std::shared_ptr<class Fighter> fighter)
{
	// Si le rechargement de la capacité est encore en cours
	if (_remainingCooldown > 0) {
		return false;
	}

	// Calcul de la probabilité de réussite
	float useChance = (float)rand() / (float)RAND_MAX;
	bool useSkillWithSuccess = (useChance <= _successRate);

	// Application de l'effet de la capacité sur le combattant
	if (useSkillWithSuccess) {
		fighter->applyEffect(std::make_shared<Effect>(*_effect));
	}

	// Marquer la capacité comme utilisée
	_used = true;

	return useSkillWithSuccess;
}

void Skill::updateCooldown()
{
	// Si la capacité a été utilisée au tour précédent -> il faut attendre son temps de recharge avant de pouvoir la réutiliser
	if (_used) {
		_remainingCooldown = _initialCooldown;
		_used = false;
		return;
	}

	// Pas besoin d'actualiser le temps de recharge si la capacité est utilisable
	if (_remainingCooldown == 0) return;
	
	// Temps de recharge mis à jour
	_remainingCooldown = std::max(_remainingCooldown - 1, 0);
}
