#include "Charge.h"

// La charge est une capacit� qui se recharge en 3 tours, a 60% de r�ussite, applique un effet doublant les d�g�ts qui dure 1 tour
Charge::Charge() : Skill(Skill::Type::PASSIVE, "Charge", 3, 0.6f, std::make_shared<Effect>(Effect::ID::CHARGE, "Double les d�g�ts", 1)){}

Charge::~Charge() {}