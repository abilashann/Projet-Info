#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <fstream>
#include <iostream>
#include <string>
#include "sommet.h"
#include "arete.h"
#include "svgfile.h"

class Graphe
{
    private:
        int m_orientation;
        int m_choix=0;
        int m_ordre; /// sommet
        int m_taille;
        int m_afficheIndice=0;
        int m_connexite=0;
        std::vector <Sommet*> m_sommet;
        std:: vector  <Arete*> m_arete;

    public:
        Graphe(std::string nomFichier);
        int Dijkstra(int i_debut, int i_fin);
        void afficher();
        void affichage_centralite();
        void CreationAdj();
        void pondere(std::string nomFichier,int choix);
        void CritereProximite();
        void centraliteVecteurPropre();
        void centraliteDegre();
        void sauvegarde();
        void Suppressionarete();
        void Connexite();
        void recuDFS(std::map<int, int>& i_preds,Sommet* s);
        void lectureFichierCentralite(std::string nomFichier);
        void afficherfleche(Svgfile& svgout, double x1, double y1, double x2, double y2);
        int Dijkstra_avec_affichage(int i_debut, int i_fin);
        int Dijkstra_sans_affichage(int i_debut, int i_fin);
        int Dijkstra_avec_affichageV2Passagesommet(int i_debut, int i_fin, int sommet);
        void Critere_intermediarite(int sommet_choisi);

};

#endif // GRAPHE_H_INCLUDED
