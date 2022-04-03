#pragma once

// Création d'une épée à partir d'une arme offensive avec des caractéristiques définies

#include "OffensiveWeapon.h"

class Sword :
    public OffensiveWeapon
{
    public:
        Sword();
        ~Sword();
};
