#pragma once

// Cr�ation d'une hache � partir d'une arme offensive avec des caract�ristiques d�finies

#include "FighterOffensiveWeapon.h"

class Axe :
    public FighterOffensiveWeapon
{
    public:
        Axe();
        ~Axe();

        // Retourne le type de l'arme en cha�ne de caract�res
        virtual std::string getStringName() const override { return "Hache"; }
};
