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
        void CritereProximite();
        void centraliteVecteurPropre();
        void centraliteDegre();


};

#endif // GRAPHE_H_INCLUDED
