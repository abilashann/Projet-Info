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
int Sommet::get_degre()
{
    return m_degre;
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



