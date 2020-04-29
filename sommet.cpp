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
<<<<<<< Updated upstream
int Sommet::get_degre()
{
    return m_degre;
=======

int Sommet::getMarquage()const
{
    return m_marquage;
}
void Sommet::setMarquage(int nv)
{
    m_marquage=nv;
}

int Sommet::get_Cvp()
{
    return m_Cvp;
}

int Sommet::get_Cd()
{
    return m_Cd;
}

int Sommet::set_Cvp(int nouvVal)
{
    return m_Cvp= nouvVal;
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
>>>>>>> Stashed changes
}

void Sommet::addAdj (int ID)
{
    m_sommet.push_back(ID);
}
void Sommet::afficherAdj()
        {
            m_degre=0;
            for ( size_t y =0 ; y<m_sommet.size();++y)
             {
                    std::cout <<m_sommet[y]<<" ";
                    m_degre+=1;

             }
        }


std::ostream& operator<< (std::ostream& out, const Sommet& s)
{
    out << "Sommet " << s.m_id << " : " << " Nom : "<< s.m_nom << " x : " << s.m_x << " y : " << s.m_y;

    return out;
}



