#ifndef GRAPHE_HPP_INCLUDED
#define GRAPHE_HPP_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include "sommet.h"

class Graphe
{
    private:
        int m_orientation;
        std::vector <Sommet*> m_sommet;

    public:

        Graphe(std::string nomFichier);
        void afficher();
        std::string parcoursLargeur(int sommetInitial);
        std::string parcoursProfondeur(int sommetInitial);

};

#endif // GRAPHE_HPP_INCLUDED
