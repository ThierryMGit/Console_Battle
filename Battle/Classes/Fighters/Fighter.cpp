#include "Fighter.h"
#include <iostream>

Fighter::Fighter() : _type(Type::SOLDIER), _life(10) {}

Fighter::Fighter(Type type, int life, std::unique_ptr<FighterOffensiveWeapon> offensiveWeapon, std::unique_ptr<FighterDefensiveWeapon> defensiveWeapon) : 
	_type(type), _life(life), _offensiveWeapon(std::move(offensiveWeapon)), _defensiveWeapon(std::move(defensiveWeapon)) {}

Fighter::~Fighter(){}

void Fighter::attack(std::shared_ptr<Fighter> enemy)
{
	if (!_offensiveWeapon) return;

	std::cout << getStringType() << " attaque " << enemy->getStringType()
		<< " avec " << _offensiveWeapon->getStringName() <<
		" et inflige " << _offensiveWeapon->getDamage() << " points de dégâts." << "\n\n";

	enemy->takeDamage(_offensiveWeapon->getDamage());
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

Fighter::operator std::string() const
{
	int armor = (!_defensiveWeapon) ? 0 : _defensiveWeapon->getArmor();

	std::string name = getStringType() + " :";
	std::string lifeStatus = "Vie : " + std::to_string(_life);
	std::string armorStatus = "Armure : " + std::to_string(armor);

	return name + "\n" + lifeStatus + "\n" + armorStatus + "\n";
}
