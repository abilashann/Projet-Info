#include "graphe.h"
#include "svgfile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Graphe::Graphe (std::string nomFichier )
{
    int ordre; /// sommet
    int taille; ///arete
    int taille2;
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
    std::string nomdufichier2="0";
    int choix;
    std::cout << "Voulez ouvrir un fichier pondere? 1 pour oui 2 pour non" << std::endl;
    while(choix!=1 && choix!=2)
    std::cin >> choix;
    if (choix==1)
    {
        std::cout << "Nom du fichier :" << std::endl;
        std::cin >> nomdufichier2;
    std::ifstream fichier2(nomdufichier2);
    if (!fichier2)
    {
        throw std::runtime_error("impossible d'ouvrir le fichier");
    }
    fichier2 >> taille2;
    for (int z=0; z<taille; ++z)
    {
        m_arete.push_back(new Arete(fichier,fichier2));
    }
    }
    else
    {
    for (int z=0; z<taille; ++z)
    {
        m_arete.push_back(new Arete(fichier));
    }
    }
    std::cout << "test114 : " << m_arete[0]->get_ID1() << std::endl;
    if(m_orientation==1)
    {
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
            for (size_t y=0; y<m_arete.size(); ++y)
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
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
            for (size_t y=0; y<m_arete.size(); ++y)
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

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        std::cout<<"Sommet "<<i<<" Adjacent :";
        m_sommet[i]->afficherAdj();
        std::cout<<std::endl;

    }
    Svgfile svgout;
    svgout.addGrid();
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        svgout.addCircle(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0,5,1,"black");
        svgout.addText(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0-5.0,m_sommet[i]->get_nom(),"black");
    }
    for (size_t j=0; j<m_sommet.size(); ++j)
    {
        for(size_t y=0; y<m_arete.size(); ++y)
        {
            if(m_arete[y]->get_ID1()==m_sommet[j]->get_id())
            {
                for (size_t z=0; z<m_sommet.size(); ++z)
                {
                    if(m_arete[y]->get_ID2()==m_sommet[z]->get_id())
                    {
                        svgout.addLine(m_sommet[j]->get_x()*100.0,m_sommet[j]->get_y()*100.0,m_sommet[z]->get_x()*100.0,m_sommet[z]->get_y()*100.0,"black");
                    }

                }

            }

        }
    }
}

