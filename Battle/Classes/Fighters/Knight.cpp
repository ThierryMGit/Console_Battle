#include "Knight.h"
#include "../Weapons/OffensiveWeapons/Sword.h"
#include "../Weapons/DefensiveWeapons/Shield.h"
#include "../Skills/Charge.h"

// Un chevalier a 20 points de vie, une �p�e faisant 5 de d�g�ts, un bouclier avec 50 d'armure et la capacit� "charge"
Knight::Knight() : Fighter(Type::KNIGHT, 20, std::make_unique<Sword>(), std::make_unique<Shield>(), std::make_unique<Charge>()){}

Knight::~Knight(){}