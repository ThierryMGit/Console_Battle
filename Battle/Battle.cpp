// Battle.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <windows.h> 
#include "Classes/Game.h"

int main()
{
    SetConsoleOutputCP(1252); // Astuce trouvée sur le net : permet d'afficher les caractères spéciaux dans la console

    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->run();

    return 0;
}
