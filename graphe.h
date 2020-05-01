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
        void CreationAdj();
        void CritereProximite();
        void centraliteVecteurPropre();
        void centraliteDegre();
        void sauvegarde();
        void Suppressionarete();
        void Connexite();
        void recuDFS(std::map<int, int>& i_preds,Sommet* s);
<<<<<<< Updated upstream

=======
        void lectureFichierCentralite(std::string nomFichier);
        void difference();
>>>>>>> Stashed changes
};

#endif // GRAPHE_H_INCLUDED
