#pragma once

// Cr�ation d'un orc � partir d'un combattant avec des caract�ristiques d�finies

#include "Fighter.h"

class Orc :
    public Fighter
{
    public:
        Orc();
        ~Orc();

    protected:
        // Retourne le type du combattant en cha�ne de caract�res
        virtual std::string getStringType() const override { return "Orc"; };
};
