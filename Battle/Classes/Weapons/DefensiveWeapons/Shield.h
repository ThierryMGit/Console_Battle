#pragma once

// Création d'un bouclier à partir d'une arme défensive avec des caractéristiques définies

#include "FighterDefensiveWeapon.h"

class Shield :
    public FighterDefensiveWeapon
{
    public:
        Shield();
        ~Shield();
};
