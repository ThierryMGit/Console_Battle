#include "Knight.h"
#include "../Weapons/OffensiveWeapons/Sword.h"
#include "../Weapons/DefensiveWeapons/Shield.h"

// Un chevalier a 20 points de vie, une épée faisant 5 de dégâts, un bouclier avec 50 d'armure
Knight::Knight() : Fighter(Type::KNIGHT, 20, std::make_unique<Sword>(), std::make_unique<Shield>()){}

Knight::~Knight(){}