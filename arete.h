#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Arete
{
    private:
        int m_num;
        std::vector<Arete*> m_adj;

    public:
        Arete (int num);
        void Adj(int num);
        void affichage();
        int get_num();
        std::vector<Sommet*> get_adj();


};

#endif // ARETE_H_INCLUDED
