#include "FighterDefensiveWeapon.h"

// De base, une arme d�fensive apporte un point d'armure
FighterDefensiveWeapon::FighterDefensiveWeapon() : _armor(1) {}

FighterDefensiveWeapon::FighterDefensiveWeapon(int armor) : _armor(armor) {}

FighterDefensiveWeapon::~FighterDefensiveWeapon(){}
