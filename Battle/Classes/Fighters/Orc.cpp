#include "Orc.h"
#include "../Weapons/OffensiveWeapons/Axe.h"
#include "../Skills/Stun.h"

// Un orc a 60 points de vie, une hache faisant 8 de d�g�ts, pas d'armure et la capacit� "stun"
Orc::Orc() : Fighter(Type::ORC, 60, std::make_unique<Axe>(), nullptr, std::make_unique<Stun>()) {}

Orc::~Orc(){}