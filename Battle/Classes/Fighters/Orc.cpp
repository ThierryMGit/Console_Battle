#include "Orc.h"
#include "../Weapons/OffensiveWeapons/Axe.h"
#include "../Skills/Stun.h"

// Un orc a 60 points de vie, une hache faisant 8 de dégâts, pas d'armure et la capacité "stun"
Orc::Orc() : Fighter(Type::ORC, 60, std::make_unique<Axe>(), nullptr, std::make_unique<Stun>()) {}

Orc::~Orc(){}