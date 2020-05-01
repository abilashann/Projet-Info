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
        ///constructeur
        Arete (std::istream& is, std::istream& is2);
        Arete(std::istream& is);

        ///getteur
        void Adj(int num);
        void affichage();
        int get_id(){return m_id;}
        int get_ID1(){return m_ID1;}
        int get_ID2(){return m_ID2;}
        int get_Poids(){return m_poids;}
        std::vector<Arete*> get_adj();

        ///fonction
        friend std::ostream& operator<< (std::ostream& out, const Arete& s);



};

#endif // ARETE_H_INCLUDED
