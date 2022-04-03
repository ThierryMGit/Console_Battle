#include "DefensiveWeapon.h"

// De base, une arme défensive apporte un point d'armure
DefensiveWeapon::DefensiveWeapon(std::string name) : _name(name), _armor(1) {}

DefensiveWeapon::DefensiveWeapon(std::string name, int armor) : _name(name), _armor(armor) {}

DefensiveWeapon::~DefensiveWeapon(){}
