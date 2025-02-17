#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class Arete
{
    private:
        int m_id;
        int m_id2;
        int m_ID1;
        int m_ID2;
        int m_poids=1;
        std::vector<Arete*> m_adj;

    public:
        Arete (std::istream& is, std::istream& is2);
        Arete(std::istream& is);
        void Adj(int num);
        void affichage();
        int get_id();
        int get_ID1();
        int get_ID2();
        int get_Poids();
        std::vector<Arete*> get_adj();
        friend std::ostream& operator<< (std::ostream& out, const Arete& s);



};

#endif // ARETE_H_INCLUDED
