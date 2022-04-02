#pragma once

// Création d'un orc à partir d'un combattant avec des caractéristiques définies

#include "Fighter.h"

class Orc :
    public Fighter
{
    public:
        Orc();
        ~Orc();

    protected:
        // Retourne le type du combattant en chaîne de caractères
        virtual std::string getStringType() const override { return "Orc"; };
};
