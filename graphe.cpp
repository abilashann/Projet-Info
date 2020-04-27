#include "graphe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Graphe::Graphe (std::string nomFichier )
{
    int nbre1;
    int nbre2;
    int indice;
    char nom;

    int ordre; /// sommet
    int taille; ///arete

    std::ifstream fichier(nomFichier);
    if (!fichier)
    {
        throw std::runtime_error("impossible d'ouvrir le fichier");
    }

    fichier>> m_orientation;
    fichier>> ordre;


    for(int i=0; i<ordre; i++)
    {
        m_sommet.push_back(new Sommet(i));
    }

    for (int i=0; i<ordre; ++i)
    {
        fichier >> indice >> nom >> nbre1 >> nbre2;
        m_sommet[nbre1]->Adj(nbre2);
        m_sommet[nbre2]->Adj(nbre1);
    }

    fichier >> taille;

    for (int i=0; i<taille; ++i)
    {
        m_arete.push_back(new Arete(i));
    }

    for (int i=0; i<taille; ++i)
    {
        fichier >> indice >> nbre1 >> nbre2;
        m_arete[nbre1]->Adj(nbre2);
        m_arete[nbre2]->Adj(nbre1);
    }
}

void Graphe::afficher()
{
    int ordre = m_sommet.size();
    int taille = m_arete.size();

    if (m_orientation== 0)
    {
        std::cout << "graphe non oriente" << std:: endl;
    }
    else
    {
        std::cout << "graphe oriente" << std::endl;
    }

    std:: cout << "ordre = " << ordre << std::endl;

    for(int i=0; i<ordre; ++i)
    {
        m_sommet[i]->affichage();
    }

    std:: cout << "taille = " << taille << std::endl;

    for(int i=0; i<ordre; ++i)
    {
        m_arete[i]->affichage();
    }



}

