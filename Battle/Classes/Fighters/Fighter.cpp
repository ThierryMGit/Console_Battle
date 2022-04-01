#include "Fighter.h"
#include <iostream>

Fighter::Fighter(Type type) : _type(type)
{
	switch (type) {
		case Type::KNIGHT:
			_life = 20;
			_armor = 50;
			_offensiveWeapon = std::make_unique<FighterOffensiveWeapon>(FighterOffensiveWeapon::Type::SWORD);
			break;
		case Type::ORC:
			_life = 60;
			_armor = 0;
			_offensiveWeapon = std::make_unique<FighterOffensiveWeapon>(FighterOffensiveWeapon::Type::AXE);
			break;
		default: // Choix de caractéristiques par défaut d'un combattant
			_life = 10;
			_armor = 0;
			_offensiveWeapon = std::make_unique<FighterOffensiveWeapon>(FighterOffensiveWeapon::Type::NONE);
			break;
	}
}

Fighter::Fighter(Type type, int life, int armor, std::unique_ptr<FighterOffensiveWeapon> weapon) : 
	_type(type), _life(life), _armor(armor), _offensiveWeapon(std::move(weapon)) {}

Fighter::Fighter(Type type, int life, int armor, FighterOffensiveWeapon::Type weaponType) : 
	Fighter(type, life, armor, std::make_unique<FighterOffensiveWeapon>(weaponType)) {}

Fighter::~Fighter(){}

void Fighter::attack(std::shared_ptr<Fighter> enemy)
{
	if (!_offensiveWeapon) return;

	std::cout << getStringType() << " attaque " << enemy->getStringType()
		<< " avec " << ((_offensiveWeapon->getType() == FighterOffensiveWeapon::Type::SWORD) ?
		"son épée " : (_offensiveWeapon->getType() == FighterOffensiveWeapon::Type::AXE) ?
		"sa hache " :
		"ses poings ") <<
		"et inflige " << _offensiveWeapon->getDamage() << " points de dommages." << "\n\n";

	enemy->takeDamage(_offensiveWeapon->getDamage());
}

void Fighter::takeDamage(int damage)
{
	if (damage <= 0) return;

	// Permet de connaitre les dommages restants après une attaque sur l'armure du combattant
	int damageRemaining = damage;

	// Les dommages sont d'abord infligés à l'armure d'un combattant s'il en possède
	if (_armor > 0) {
		int damageInflictedToArmor = std::min(_armor, damage);
		_armor -= damageInflictedToArmor;
		damageRemaining = damage - damageInflictedToArmor;
	}

	if (damageRemaining <= 0) return;

	// Le combattant perd une quantité de vie en fonction des dommages restants
	_life = std::max(0, _life - damageRemaining);
}

Fighter::operator std::string() const
{
	std::string name = getStringType() + " :";
	std::string lifeStatus = "Vie : " + std::to_string(_life);
	std::string armorStatus = "Armure : " + std::to_string(_armor);

	return name + "\n" + lifeStatus + "\n" + armorStatus + "\n";
}

std::string Fighter::getStringType() const
{
	std::string stringType;

	switch (_type) {
		case Type::KNIGHT:
			stringType = "Chevalier";
			break;
		case Type::ORC:
			stringType = "Orc";
			break;
		default:
			stringType = "Combattant";
			break;
	}

	return stringType;
}
