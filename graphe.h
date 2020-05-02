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
        int m_choix=0;
        int m_ordre; /// sommet
        int m_taille;
        int m_afficheIndice=0;
        std::vector <Sommet*> m_sommet;
        std:: vector  <Arete*> m_arete;


    public:
        Graphe(std::string nomFichier);
        int Dijkstra(int i_debut, int i_fin);
        void afficher();
        void CreationAdj();
        void pondere(std::string nomFichier,int choix);
        void set_dejafait(int val);
        void CritereProximite();
        void centraliteVecteurPropre();
        void centraliteDegre();
        void sauvegarde();
        void Suppressionarete();
        void Connexite();
        void recuDFS(std::map<int, int>& i_preds,Sommet* s);
        void lectureFichierCentralite(std::string nomFichier);

};

#endif // GRAPHE_H_INCLUDED
