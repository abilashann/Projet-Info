#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graphe.h"

int main()
{
    int on=1;
    int choix = 0;
    std::string nom="graphe_cycle4_topo.txt";
    std::cout << "Choisissez le nom du fichier a ouvrir : (Le std::cin est en commentaire juste apres)"<< std::endl;
    //std::cin >> nom;
    Graphe dessin{nom};
    do
    {

        std::cout << "                                    ---> ACCESSIBILITE ET VULNERABILITE DES RESEAUX <--- "<<std::endl;
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
                dessin.CritereProximite();
                dessin.centraliteVecteurPropre();
                dessin.centraliteDegre();
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
        }
        while(choix<1 || choix >5);
    }
    while(on==1);

}
