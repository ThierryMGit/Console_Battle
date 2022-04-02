#pragma once

// Cr�ation d'un chevalier � partir d'un combattant avec des caract�ristiques d�finies

#include "Fighter.h"

class Knight :
    public Fighter
{
    public:
        Knight();
        ~Knight();

    protected:
        // Retourne le type du combattant en cha�ne de caract�res
        virtual std::string getStringType() const override { return "Chevalier"; };
};
