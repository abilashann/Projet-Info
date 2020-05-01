#include "arete.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Arete::Arete (std::istream& is,std::istream& is2)
{
    is >> m_id >> m_ID1 >> m_ID2;
                if ( is.fail() )
                throw std::runtime_error("Probleme lecture id,x,y d'une Sommet");
    is2 >> m_id2 >> m_poids;
}

Arete::Arete (std::istream& is)
{
    is >> m_id >> m_ID1 >> m_ID2;
                if ( is.fail() )
                throw std::runtime_error("Probleme lecture id,x,y d'une Sommet");
}
/*void Arete::Adj(int nbre)
{
    m_adj.push_back(new Arete(nbre));
}*/


int Arete::get_id()
{
    return m_id;
}

int Arete::get_ID1()
{
    return m_ID1;
}

int Arete::get_ID2()
{
    return m_ID2;
}
int Arete::get_Poids()
{
    return m_poids;
}
std::ostream& operator<< (std::ostream& out, const Arete& s)
{
    out << "Arete " << s.m_id << " : " << " Sommet 1: "<< s.m_ID1 << " Sommet 2 : " << s.m_ID2 << " Poids : " << s.m_poids;
    /*for (const auto& adj : s.m_adj)
    {
        std::cout << adj->m_num << " ";
    }*/
    return out;
}

/*void Arete::affichage()
{
    std::cout << m_num;
    for (size_t i=0;i<m_adj.size(); ++i)
    {
        std::cout << m_adj[i]->get_num() <<std::endl;
    }
}
*/
