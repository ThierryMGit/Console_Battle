#include "Stun.h"

// Le stun est une capacité qui se recharge en 5 tours, a 20% de réussite, applique l'effet étourdissement qui dure 1 tour
Stun::Stun() : Skill(Skill::Type::ACTIVE, "Stun", 5, 0.2f, std::make_shared<Effect>(Effect::ID::STUN, "Etourdissement", 1)){}

Stun::~Stun(){}