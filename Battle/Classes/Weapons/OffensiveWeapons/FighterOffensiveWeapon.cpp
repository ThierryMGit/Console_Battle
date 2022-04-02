#include "FighterOffensiveWeapon.h"

// De base, on se bat avec ses poings faisant 1 de dégât
FighterOffensiveWeapon::FighterOffensiveWeapon() : _damage(1) {}

FighterOffensiveWeapon::FighterOffensiveWeapon(int damage) : _damage(damage) {}

FighterOffensiveWeapon::~FighterOffensiveWeapon(){}
