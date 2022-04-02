#pragma once

// Création d'une hache à partir d'une arme offensive avec des caractéristiques définies

#include "FighterOffensiveWeapon.h"

class Axe :
    public FighterOffensiveWeapon
{
    public:
        Axe();
        ~Axe();

        // Retourne le type de l'arme en chaîne de caractères
        virtual std::string getStringName() const override { return "Hache"; }
};
