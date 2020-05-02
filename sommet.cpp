#include "sommet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Sommet::Sommet (std::istream& is)
{
    is >> m_id >> m_nom >> m_x >> m_y ;
    //std::cout<< m_id<<std::endl;
    if ( is.fail() )
        throw std::runtime_error("Probleme lecture id,x,y d'une Sommet");
}

void Sommet::remplir(Sommet* adjacent,int poids)
{
    m_adjacents.emplace(adjacent,poids);
}

void Sommet::suppadj(Sommet* j)
{
    m_adjacents.erase(j);
}

int Sommet::getDist (int i) //retourne la poid de l'arc allant du sommet à un autre sommet de numéro i
{
    int d=99;
    for (auto it : m_adjacents)
        if (it.first->get_id()==i)
            d=it.second;
    return d; //s'il ne sont pas adjacent retourne 99
}

bool Sommet::estAdjacentA(int i) //dertmine si on peut aller du sommet au un autre sommet de numéro i
{
    bool adjacent=false;
    for (auto it : m_adjacents)
        if (it.first->get_id()==i)
            adjacent=true;
    return adjacent;
}

void Sommet::afficherAdj()
{
    std::cout<<"Sommet "
             <<m_id<<" : ";
    for (auto it : m_adjacents)
    {
        std::cout<<it.first->get_id()<<""  //identifiant
                 <<"("<<it.second<<") ";
    }

}
void Sommet::changementpoids(int id1,int id2, int poids)
{
    for (auto &it : m_adjacents)
    {
        if(m_id==id1 && it.first->get_id()== id2 )
        {
            it.second=poids;//poids de l'arc
        }

    }
}
void Sommet::reinitialiserCouleur()
{
    m_couleur=0;
}

std::ostream& operator<< (std::ostream& out, const Sommet& s)
{
    out << "Sommet " << s.m_id << " : " << " Nom : "<< s.m_nom << " x : " << s.m_x << " y : " << s.m_y;

    return out;
}
