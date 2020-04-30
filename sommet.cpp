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

int Sommet::get_id()
{
    return m_id;
}
std::string Sommet::get_nom()
{
    return m_nom;
}
int Sommet::get_x()
{
    return m_x;
}
int Sommet::get_y()
{
    return m_y;
}

int Sommet::getMarquage()const
{
    return m_marquage;
}
void Sommet::setMarquage(int nv)
{
    m_marquage=nv;
}

float Sommet::get_Cvp()
{
    return m_Cvp;
}

int Sommet::get_Cd()
{
    return m_Cd;
}


int Sommet::set_Cd(int cd)
{
    return m_Cd= cd;
}

void Sommet::remplir(Sommet* adjacent,int poids)
{
     m_adjacents.emplace(adjacent,poids);
}
int Sommet::getDist (int i) //retourne la poid de l'arc allant du sommet à un autre sommet de numéro i
{
    int d=99;
    for (auto it : m_adjacents)
        if (it.first->get_id()==i)
            d=it.second;
    return d; //s'il ne sont pas adjacent retourne 99
}


void Sommet::afficherAdj()
{
    std::cout<<"Sommet "
                        <<m_id<<" : ";
    for (auto it : m_adjacents)
    {
        std::cout<<it.first->get_id()<<""  //identifiant
                 <<"("<<it.second<<") "; //poids de l'arc
    }
}

std::ostream& operator<< (std::ostream& out, const Sommet& s)
{
    out << "Sommet " << s.m_id << " : " << " Nom : "<< s.m_nom << " x : " << s.m_x << " y : " << s.m_y;

    return out;
}



