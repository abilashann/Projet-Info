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
<<<<<<< Updated upstream
        void centraliteDegre();
=======
        void CritereProximite();
        void centraliteVecteurPropre();
        void centraliteDegre();

>>>>>>> Stashed changes

};

#endif // GRAPHE_H_INCLUDED
