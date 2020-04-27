#include "arete.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Arete::Arete (int num)
{
    m_num = num;
}

void Arete::Adj(int nbre)
{
    m_adj.push_back(new Arete(nbre));
}


int Arete::get_num()
{
    return m_num;
}

std::vector<Arete*> Arete:: get_adj()
{
    return m_adj;

}

void Arete::affichage()
{
    std::cout << m_num;
    for (int i=0;i<m_adj.size(); ++i)
    {
        std::cout << m_adj[i]->get_num() <<std::endl;
    }
}
