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
void Sommet::set_Cp(double nv)
{
    m_Cp=nv;
}
void Sommet::set_Cpn(double nv)
{
    m_Cpn=nv;
}

float Sommet::get_Cvp()
{
    return m_Cvp;
}

int Sommet::get_Cd()
{
    return m_Cd;
}

double Sommet::get_Cp()
{
    return m_Cp;
}
double Sommet::get_Cpn()
{
    return m_Cpn;
}

int Sommet::set_Cd(int cd)
{
    return m_Cd= cd;
}

void Sommet::remplir(Sommet* adjacent,int poids)
{
     m_adjacents.emplace(adjacent,poids);
}
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
void Sommet::suppadj(Sommet* j)
{
    auto it= m_adjacents.find(j);
    m_adjacents.erase(j);
}
<<<<<<< Updated upstream
int Sommet::getDist (int i) //retourne la poid de l'arc allant du sommet ï¿½ un autre sommet de numï¿½ro i
=======

int Sommet::getDist (int i) //retourne la poid de l'arc allant du sommet à un autre sommet de numéro i
>>>>>>> Stashed changes
{
    int d=99;
    for (auto it : m_adjacents)
        if (it.first->get_id()==i)
            d=it.second;
    return d; //s'il ne sont pas adjacent retourne 99
}
bool Sommet::estAdjacentA(int i) //dertmine si on peut aller du sommet au un autre sommet de numï¿½ro i
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
                 <<"("<<it.second<<") "; //poids de l'arc
    }
}
void Sommet::reinitialiserCouleur()
{
    m_couleur=0;
}

<<<<<<< Updated upstream
void Sommet::setCouleur(int nv)
{
    m_couleur=nv;
}
int Sommet::getCouleur()const
{
    return m_couleur;
}
=======
void Sommet::reinitialiserCouleur()
{
    m_couleur=0;
}

>>>>>>> Stashed changes
std::ostream& operator<< (std::ostream& out, const Sommet& s)
{
    out << "Sommet " << s.m_id << " : " << " Nom : "<< s.m_nom << " x : " << s.m_x << " y : " << s.m_y;

    return out;
}
