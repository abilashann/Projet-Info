#include "sommet.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Sommet::Sommet (int num)
{
    m_num = num;
}

int Sommet::get_num()
{
    return m_num;
}

std::vector<Sommet*> Sommet:: get_adj()
{
    return m_adj;

}


void Sommet::Adj(int nbre)
{
    m_adj.push_back(new Sommet(nbre));
}

void Sommet::affichage()
{
    std::cout << m_num;
    for (int i=0;i<m_adj.size(); ++i)
    {
        std::cout << m_adj[i]->get_num() <<std::endl;
    }
}



