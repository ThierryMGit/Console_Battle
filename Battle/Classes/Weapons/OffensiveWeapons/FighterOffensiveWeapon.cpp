#include "FighterOffensiveWeapon.h"

FighterOffensiveWeapon::FighterOffensiveWeapon(Type type) : _type(type)
{
	switch (type) {
		case Type::SWORD:
			_damage = 5;
			break;
		case Type::AXE:
			_damage = 8;
			break;
		case Type::NONE: // Ne pas avoir d'armes signifie que l'on se bat avec ses poings faisant 1 de dégât
		default:
			_damage = 1;
			break;
	}
}

FighterOffensiveWeapon::FighterOffensiveWeapon(Type type, int damage) : _type(type), _damage(damage) {}
