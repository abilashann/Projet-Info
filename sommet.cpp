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
char Sommet::get_nom()
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

/*std::vector<Sommet*> Sommet:: get_adj()
{
    return m_adj;

}*/
void Sommet::addAdj (int ID)
{
    m_sommet.push_back(ID);
}
void Sommet::afficherAdj()
        {
            for ( size_t y =0 ; y<m_sommet.size();++y)
             {
                    std::cout <<m_sommet[y]<<" ";

             }
        }
/*
void Sommet::Adj(int nbre)
{
    m_adj.push_back(new Sommet(nbre));
}*/

std::ostream& operator<< (std::ostream& out, const Sommet& s)
{
    out << "Sommet " << s.m_id << " : " << " Nom : "<< s.m_nom << " x : " << s.m_x << " y : " << s.m_y;

    return out;
}



