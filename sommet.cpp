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

float Sommet::get_Cd()
{
    return m_Cd;
}

std::vector<Sommet*> Sommet::get_adj()
{
    return m_adj;

}

void Sommet::addAdj (Sommet* new_adj)
{
    m_adj.push_back(new_adj);
}

void Sommet::afficherAdj()
{
    for ( size_t y =0 ; y<get_degre(); ++y)
    {
        std::cout <<m_adj[y]->get_id() <<" ";
        std::cout <<get_degre()<< std::endl;

    }
}

void Sommet:: set_Cd(float Cd)
{
    m_Cd=Cd;
}

///void Sommet:: set_Cdn(float Cdn)
///{
   /// m_Cdn=Cdn;
///}



std::ostream& operator<< (std::ostream& out, const Sommet& s)
{
    out << "Sommet " << s.m_id << " : " << " Nom : "<< s.m_nom << " x : " << s.m_x << " y : " << s.m_y;

    return out;
}




