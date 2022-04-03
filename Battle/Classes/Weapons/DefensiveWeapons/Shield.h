#pragma once

// Création d'un bouclier à partir d'une arme défensive avec des caractéristiques définies

#include "DefensiveWeapon.h"

class Shield :
    public DefensiveWeapon
{
    public:
        Shield();
        ~Shield();
};
