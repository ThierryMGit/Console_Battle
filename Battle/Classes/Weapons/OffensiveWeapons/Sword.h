#pragma once

// Cr�ation d'une �p�e � partir d'une arme offensive avec des caract�ristiques d�finies

#include "OffensiveWeapon.h"

class Sword :
    public OffensiveWeapon
{
    public:
        Sword();
        ~Sword();
};
