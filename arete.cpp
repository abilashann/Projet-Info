#include "arete.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Arete::Arete (std::istream& is)
{
    is >> m_id >> m_ID1 >> m_ID2;
                if ( is.fail() )
                throw std::runtime_error("Probleme lecture id,x,y d'une Sommet");
}

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

std::ostream& operator<< (std::ostream& out, const Arete& s)
{
    out << "Arete " << s.m_id << " : " << " Sommet 1: "<< s.m_ID1 << " Sommet 2 : " << s.m_ID2;
    /*for (const auto& adj : s.m_adj)
    {
        std::cout << adj->m_num << " ";
    }*/

    return out;
}

