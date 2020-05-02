#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graphe.h"


int main()
{
    system("mode con LINES=1000 COLS=100");//permet d'avoir mille lignes dans la console.
    Graphe dessin{"graphe_cycle4_topo.txt"};
    dessin.afficher();
    dessin.Critere_intermediarite(0);
/*
    dessin.CritereProximite();
    dessin.centraliteVecteurPropre();
    dessin.centraliteDegre();
    dessin.sauvegarde();
    dessin.Connexite();
    dessin.Suppressionarete();
    dessin.CreationAdj();
    dessin.afficher();
    dessin.Connexite();
    dessin.Dijkstra(0,1);*/


    return 0;
}
/*int main()
{
    Graphe dessin{"graphe_etoile1_topo.txt"};
    int choix = 0;
    std::cout << "bienvenue sur l'accessibilite et la vulnerabilite des reseaux"<<std::endl;
    do
    {
        std::cout << std::endl;
        std::cout << "1. dessiner le graphe"<<std::endl;
        std::cout << "2. indices de centralite"<<std::endl;
        std::cout << "3. rien"<<std::endl;
        std::cout << "4. quitter"<<std::endl;
        std::cout << "que voulez-vous faire?"<< std::endl;
        std::cin >> choix;
        switch (choix)
        {
        case 1 :
            dessin.afficher();
            break;
        case 2 :
            dessin.centraliteDegre();
            break;
        case 3 :
            std::cout << "en cours de creation "<<std::endl;
            break;
        case 4 :
            return 0;
            break;
        }
    }
    while(choix<1 || choix >4);
    return 0;
}*/
