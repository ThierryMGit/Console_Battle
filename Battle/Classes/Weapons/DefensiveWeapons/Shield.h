#pragma once

// Cr�ation d'un bouclier � partir d'une arme d�fensive avec des caract�ristiques d�finies

#include "DefensiveWeapon.h"

class Shield :
    public DefensiveWeapon
{
    public:
        Shield();
        ~Shield();
};
