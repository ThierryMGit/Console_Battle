#pragma once

// Cr�ation d'une �p�e � partir d'une arme offensive avec des caract�ristiques d�finies

#include "FighterOffensiveWeapon.h"

class Sword :
    public FighterOffensiveWeapon
{
    public:
        Sword();
        ~Sword();

        // Retourne le type de l'arme en cha�ne de caract�res
        virtual std::string getStringName() const override { return "�p�e"; }
};
