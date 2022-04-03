#include "Charge.h"

// La charge est une capacité qui se recharge en 3 tours, a 60% de réussite, applique un effet doublant les dégâts qui dure 1 tour
Charge::Charge() : Skill(Skill::Type::PASSIVE, "Charge", 3, 0.6f, std::make_shared<Effect>(Effect::ID::CHARGE, "Double les dégâts", 1)){}

Charge::~Charge() {}