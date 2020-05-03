#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graphe.h"

int main()
{
    Graphe dessin{"graphe_cycle5_topo.txt"};
    dessin.afficher();
    ///dessin.CritereProximite();
    dessin.centraliteVecteurPropre();
    ///dessin.centraliteDegre();
    dessin.sauvegarde();
<<<<<<< Updated upstream
=======

    dessin.Connexite();
    dessin.Suppressionarete();
    dessin.CreationAdj();
    dessin.afficher();
    dessin.Connexite();

>>>>>>> Stashed changes
    return 0;
}
/*int main()
{
    Graphe dessin{"graphe_etoile1_topo.txt"};
    int choix = 0;
<<<<<<< Updated upstream
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
=======
    std::string nom;
    std::cout << "                                    ---> ACCESSIBILITE ET VULNERABILITE DES RESEAUX <--- "<<std::endl << std::endl;
    std::cout << "Choisissez le nom du fichier a ouvrir : "<< std::endl;
    std::cin >> nom;
    Graphe dessin{nom};
    do
    {


        do
        {
            std::cout << std::endl;
            std::cout << "--------------------------------------------------------  MENU  --------------------------------------------------------"<<std::endl;
            std::cout << "  1. Afficher (Console et SVG)"<<std::endl;
            std::cout << std::endl;
            std::cout << "  2. changer le systeme de ponderation"<<std::endl;
            std::cout << std::endl;
            std::cout << "  3. indices de centralite: calcul, affichage, sauvegarde"<<std::endl;
            std::cout << "              - centralite de degre"<< std::endl;
            std::cout << "              - centralite de vecteur propre"<< std::endl;
            std::cout << "              - centralite de proximite"<< std::endl;
            std::cout << "              - centralite d'intermediarite"<< std::endl;
            std::cout << std::endl;
            std::cout << "  4. test de vulnerabilite"<<std::endl;
            std::cout << "              - supprimer une ou plusieurs aretes"<< std::endl;
            std::cout << "              - tester la connexite du graphe"<< std::endl;
            std::cout << "              - calcul des nouveaux indices de centralites pour les comparer avec ceux obtenus avant suppression"<< std::endl;
            std::cout << std::endl;
            std::cout << "  5. quitter le programme"<<std::endl;
            std::cout <<std::endl;
            std::cout << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;
            std::cout << "      Que voulez-vous faire? : ";
            std::cin >> choix;
            std::cout << std::endl << std::endl;

            switch (choix)
            {
            case 1 :

                dessin.afficher();
                break;
            case 2 :
                dessin.pondere(nom,1);
                break;
            case 3 :
                dessin.centraliteDegre();
                dessin.centraliteVecteurPropre();
                dessin.CritereProximite();

                dessin.affichage_centralite();
                dessin.sauvegarde();
                dessin.Connexite();
                break;
            case 4 :
                dessin.Suppressionarete();
                dessin.CreationAdj();
                dessin.afficher();
                dessin.Connexite();
                dessin.lectureFichierCentralite("IndiceSave.txt");
                break;
            case 5 :
                on =0;
                break;
            }
>>>>>>> Stashed changes
        }
    }
    while(choix<1 || choix >4);
    return 0;
}*/
