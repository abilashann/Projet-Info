#include "graphe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Graphe::Graphe (std::string nomFichier )
{
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
        m_sommet.push_back(new Sommet(fichier));
    }

    fichier >> taille;
    for (int z=0; z<taille;++z)
    {
        m_arete.push_back(new Arete(fichier));
    }
    if(m_orientation==1)
    {
        for (size_t i=0; i<m_sommet.size();++i)
{
    for (size_t y=0;y<m_arete.size(); ++y)
    {
        if (m_sommet[i]->get_id()==m_arete[y]->get_ID1())
        {
        m_sommet[i]->addAdj(m_arete[y]->get_ID2());
        }
    }
    }
    }
else if (m_orientation==0)
{
for (size_t i=0; i<m_sommet.size();++i)
{
    for (size_t y=0;y<m_arete.size(); ++y)
    {
        if (m_sommet[i]->get_id()==m_arete[y]->get_ID1())
        {
        m_sommet[i]->addAdj(m_arete[y]->get_ID2());
        }
        else if (m_sommet[i]->get_id()==m_arete[y]->get_ID2())
                    {
                        m_sommet[i]->addAdj(m_arete[y]->get_ID1());
                    }
        }

    }
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

    /*for(int i=0; i<ordre; ++i)
    {
        m_arete[i]->affichage();
    }*/
for (const auto& s : m_sommet)
    {
        std::cout << "  " << *s << std::endl;
    }
    std:: cout << "taille = " << taille << std::endl;
    for (const auto& s : m_arete)
    {
        std::cout << "  " << *s << std::endl;
    }
for (size_t i =0 ; i<m_sommet.size();++i)
         {
             std::cout<<"Sommet "<<i<<" Adjacent :";
            m_sommet[i]->afficherAdj();
             std::cout<<std::endl;

         }

}

