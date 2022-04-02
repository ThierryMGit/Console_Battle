#pragma once

// Création d'une épée à partir d'une arme offensive avec des caractéristiques définies

#include "FighterOffensiveWeapon.h"

class Sword :
    public FighterOffensiveWeapon
{
    public:
        Sword();
        ~Sword();

        // Retourne le type de l'arme en chaîne de caractères
        virtual std::string getStringName() const override { return "Épée"; }
};
