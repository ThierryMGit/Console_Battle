#include "Orc.h"
#include "../Weapons/OffensiveWeapons/Axe.h"

// Un orc a 60 points de vie et une hache faisant 8 de dégâts
Orc::Orc() : Fighter(Type::ORC, 60, std::make_unique<Axe>()) {}

Orc::~Orc(){}