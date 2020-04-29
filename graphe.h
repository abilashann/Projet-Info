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
        void afficher();
        void centraliteDegre();
        void centraliteVecteurPropre();

};

#endif // GRAPHE_H_INCLUDED
