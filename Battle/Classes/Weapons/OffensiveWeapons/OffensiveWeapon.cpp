#include "OffensiveWeapon.h"

// De base, on se bat avec ses poings faisant 1 de dégât
OffensiveWeapon::OffensiveWeapon() : _name("Poings"), _damage(1) {}

OffensiveWeapon::OffensiveWeapon(std::string name, int damage) : _name(name), _damage(damage) {}

OffensiveWeapon::~OffensiveWeapon(){}
