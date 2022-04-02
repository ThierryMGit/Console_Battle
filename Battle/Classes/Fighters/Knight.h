#pragma once

// Création d'un chevalier à partir d'un combattant avec des caractéristiques définies

#include "Fighter.h"

class Knight :
    public Fighter
{
    public:
        Knight();
        ~Knight();

    protected:
        // Retourne le type du combattant en chaîne de caractères
        virtual std::string getStringType() const override { return "Chevalier"; };
};
