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
    for (int z=0; z<taille; ++z)
    {
        m_arete.push_back(new Arete(fichier));
    }
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

void Graphe::centraliteDegre()
{
    int ordre = m_sommet.size();
    std::vector <int> degre;
///    int degres=0;

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        std::cout<<"Sommet "<<i<<" Adjacent :";
        m_sommet[i]->afficherAdj();
        std::cout<<std::endl;

    }


<<<<<<< Updated upstream
=======
    if (taille!=1) //si s0 et le sommet final sont adjacents
    {
        for (size_t i=taille-1 ; i>1; --i) //sens inverse parce que pour remplir le vecteur on est partie de la fin
        {
            std::cout<<sommetsParcourus[i]->getDist(sommetsParcourus[i-1]->get_id())<<"+";
        }
        std::cout<<sommetsParcourus[1]->getDist(sommetsParcourus[0]->get_id())<<"=";
    }
    std::cout<<tab_distance[i_fin];
    longeur=tab_distance[i_fin];
    return longeur;
}
/*
void Graphe::Dijkstra_pour_toutes_les aretes(int i_debut,int i_fin)
{ for( int i_debut=0; i_debut<m_sommet.size();i_debut++){
 for(int i_fin=0; i_fin<m_sommet.size();i_fin++){
    Dijkstra(i_debut,int i_fin);}}
}*/


void Graphe::centraliteDegre()
{
    float Cd=0;
    std::vector <int> degre;

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        m_sommet[i]->set_Cd(Cd);
        Cd = m_sommet[i]->get_degre();
        std::cout<< Cd << std::endl;

    }
}


void Graphe::centraliteVecteurPropre()
{
    ///initialisation variable
    double lambda = 0.0;
    double lambda_prev = 0.0;
    std::vector<float> somme_indice_Si;
    int somme_indice=0;

    ///initialisation

    for(size_t i = 0; i<m_sommet.size() ; i++)
    {
        m_sommet[i]->set_Cvp(1);
    }

    /// calcul

    do
    {
        ///parcours des sommets
        for(size_t i = 0; i<m_sommet.size(); i++)
        {
            float somme_adj = 0.0;
            int deg=0;

            ///parcours des adj de m_sommet[i]

        for(auto it: m_sommet[i]->get_adj())
        {
            somme_adj+= it.first->get_Cvp();
        }
        /*
            for (int j=0 ; j<m_sommet[i]->get_degre() ; j++)
                {
                    deg = m_sommet[i].get_adj();
                    somme_adj += deg->get_Cvp();
                }
        */


            somme_indice_Si.push_back(somme_adj);
        }

        ///calcul de lambda
        lambda_prev = lambda;
        lambda = sqrt(somme_indice);

        /// calcul nouvel indice
        for(size_t i=0 ; i<m_sommet.size(); i++)
        {
            m_sommet[i]->set_Cvp(somme_indice_Si[i]/lambda);
        }

    }while(abs(lambda - lambda_prev) > 0.01);



}

void Graphe::CritereProximite()
{
    float Cn[m_sommet.size()]; // Normalisé
    float Cnn[m_sommet.size()]; // Non normalisé
    float Somme=0;;
    int longeur=0;
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        for (size_t y=0; y<m_sommet.size(); ++y)
        {
            if (i==y)
            {
                longeur=0;
            }
            else
            {
                longeur=Dijkstra(i,y);
            }

            Somme+=longeur;
            longeur=0;
        }
        std::cout << std::endl;
        std::cout << "Somme = :" << Somme<< std::endl;
        if(Somme!=0)
        {
            Cn[i]=((m_sommet.size()-1)/(Somme));
            Cnn[i]=((1)/(Somme));
            std::cout<< "Cn numero :"<< i << " = " << Cn[i] << std::endl;
        std::cout<< "Cnn numero :"<< i << " = " << Cnn[i] << std::endl;
        }
Somme=0;
>>>>>>> Stashed changes

}
