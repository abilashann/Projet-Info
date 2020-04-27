#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Sommet
{
    private:
        int m_num;
        std::vector<Sommet*> m_adj;

    public:
        Sommet (int num);
        void Adj(int num);
        void affichage();
        int get_num();
        std::vector<Sommet*> get_adj();


};

#endif // SOMMET_H_INCLUDED
