#include "Fighter.h"
#include <iostream>

int Fighter::instanceCount = 1;

Fighter::Fighter() : Fighter(Type::SOLDIER, 10)  {}

Fighter::Fighter(Type type, int life, std::unique_ptr<OffensiveWeapon> offensiveWeapon, std::unique_ptr<DefensiveWeapon> defensiveWeapon, std::unique_ptr<Skill> skill) :
	_type(type), _life(life), _offensiveWeapon(std::move(offensiveWeapon)), _defensiveWeapon(std::move(defensiveWeapon)), _skill(std::move(skill)),
	_effect(nullptr) 
{
	_id = instanceCount;
	instanceCount++;
}

Fighter::~Fighter(){}

void Fighter::useSkill(std::shared_ptr<Fighter> me, std::shared_ptr<Fighter> enemy)
{
	// Si pas de capacité ou capacité pas prête à l'utilisation -> pas d'utilisation de la capacité
	if (!_skill || (_skill && _skill->getRemainingCooldown() > 0)) return;

	// Le combattant est sous l'effet appliqué par la capacité "stun" -> il ne peut pas utiliser de capacité
	if (_effect && _effect->getID() == Effect::ID::STUN) {
		return;
	}

	bool isSkillUsedWithSuccess;
	if (_skill->getType() == Skill::Type::ACTIVE) { // Capacité sur l'ennemi
		isSkillUsedWithSuccess = _skill->use(enemy);
	} else { // Capacité sur soi-même
		isSkillUsedWithSuccess = _skill->use(me);
	}

	std::cout << getStringType() << " utilise la capacité " << _skill->getName();
	if (isSkillUsedWithSuccess) {
		if (_skill->getType() == Skill::Type::ACTIVE) {
			std::cout << " avec succès sur " << enemy->getStringType() << " et applique l'effet \"" 
				<< _skill->getEffect()->getDescription() << "\""<< "\n\n";
		} else {
			std::cout << " avec succès sur lui-même et s'applique l'effet \"" << 
				_skill->getEffect()->getDescription() << "\"" << "\n\n";
		}
	} else {
		std::cout << " et échoue" << "\n\n";
	}
}

void Fighter::attack(std::shared_ptr<Fighter> enemy)
{
	// Si pas d'arme -> le combattant ne peut pas attaquer
	if (!_offensiveWeapon) return;

	// Le combattant est sous l'effet appliqué par la capacité "stun" -> il ne peut pas attaquer
	if (_effect && _effect->getID() == Effect::ID::STUN) {
		std::cout << getStringType() << " est étourdit et ne peut pas attaquer" << "\n\n";
		return;
	}

	int damageToDeal = _offensiveWeapon->getDamage();

	// Le combattant est sous l'effet appliqué par la capacité "charge" -> dégats doublés
	if (_effect && _effect->getID() == Effect::ID::CHARGE) {
		damageToDeal *= 2;
		std::cout << getStringType() << " double ses dégâts pour ce tour" << "\n\n";
	}
	
	std::cout << getStringType() << " attaque " << enemy->getStringType()
		<< " avec " << _offensiveWeapon->getName() <<
		" et inflige " << damageToDeal << " points de dégâts." << "\n\n";

	// Dégâts infligés géré par l'ennemi
	enemy->takeDamage(damageToDeal);
}

void Fighter::takeDamage(int damage)
{
	if (damage <= 0) return;

	// Permet de connaitre les dommages restants après une attaque sur l'armure du combattant
	int damageRemaining = damage;

	// Les dommages sont d'abord infligés à l'armure d'un combattant s'il en possède
	if (_defensiveWeapon && _defensiveWeapon->getArmor() > 0) {
		int currentArmor = _defensiveWeapon->getArmor();
		int damageInflictedToArmor = std::min(currentArmor, damage);
		currentArmor -= damageInflictedToArmor;
		_defensiveWeapon->setArmor(currentArmor);
		damageRemaining = damage - damageInflictedToArmor;
	}

	if (damageRemaining <= 0) return;

	// Le combattant perd une quantité de vie en fonction des dommages restants
	_life = std::max(0, _life - damageRemaining);
}

void Fighter::updateSkillAndEffectStatus()
{
	_updateSkillStatus();
	_updateEffectStatus();
}

std::string Fighter::getStatus() const
{
	int armor = (!_defensiveWeapon) ? 0 : _defensiveWeapon->getArmor();

	std::string name = getStringType() + " :";
	std::string lifeStatus = "Vie : " + std::to_string(_life);
	std::string armorStatus = "Armure : " + std::to_string(armor);

	return name + "\n" + lifeStatus + "\n" + armorStatus + "\n";
}

bool Fighter::isSkillUsable()
{
	// Pas de capacité
	if (!_skill) {
		std::cout << getStringType() << " ne possède pas de capacité" << "\n\n";
		return false;
	} else if (_skill && _skill->getRemainingCooldown() > 0) { // capacité pas prête à l'utilisation
		std::cout << "Capacité non disponible : " << getStringType() << " pourra utiliser sa capacité " << _skill->getName() << " dans " << _skill->getRemainingCooldown() <<
			((_skill->getRemainingCooldown() > 1) ? " tours" : " tour") << "\n\n";
		return false;
	} else if (_effect && _effect->getID() == Effect::ID::STUN) { // Le combattant est sous l'effet appliqué par la capacité "stun" -> il ne peut pas utiliser de capacité
		std::cout << getStringType() << " est étourdit et ne peut utiliser sa capacité" << "\n\n";
		return false;
	} else {
		std::cout << getStringType() << " peut utiliser sa capacité " << _skill->getName() <<
			" : " << _skill->getDescription() << "\n\n";
		return true;
	}
}

void Fighter::_updateSkillStatus()
{
	if (!_skill) return;

	_skill->updateCooldown();
}

void Fighter::_updateEffectStatus()
{
	if (!_effect) return;

	int effectRemainingActiveDuration = _effect->updateActiveDuration();

	// Si l'effet n'est plus actif -> suppression de l'effet sur le combattant
	if (effectRemainingActiveDuration == 0) {
		std::cout << getStringType() << " n'a plus l'effet \"" << _effect->getDescription() << "\"" << "\n\n";
		_effect = nullptr;
		return;
	}

	std::cout << getStringType() << " est sous l'effet \"" << _effect->getDescription() << "\"" << "\n\n";
}
