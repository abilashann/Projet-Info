#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include "sommet.h"
#include "arete.h"


class Graphe
{
    private:
        int m_orientation;
        std::vector <Sommet*> m_sommet;
        std:: vector  <Arete*> m_arete;


    public:
        Graphe(std::string nomFichier);
        int Dijkstra(int i_debut, int i_fin);
        void afficher();
<<<<<<< Updated upstream
=======
        void affichage_centralite();
        void CreationAdj();
        void pondere(std::string nomFichier,int choix);
        void set_dejafait(int val);
>>>>>>> Stashed changes
        void CritereProximite();
        void centraliteVecteurPropre();
        void centraliteDegre();
        void sauvegarde();


};

#endif // GRAPHE_H_INCLUDED
