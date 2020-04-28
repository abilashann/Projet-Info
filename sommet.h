#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
class Sommet
{
    private:
        int m_id;
        std::string m_nom;
        int m_x;
        int m_y;
        std::vector<int> m_sommet;
        int m_degre;

    public:
        Sommet (std::istream& is);
        void Adj(int num);
        void affichage();
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();
        int get_degre();
        std::vector<Sommet*> get_adj();
        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);
        void addAdj (int ID);
        void afficherAdj();


};

#endif // SOMMET_H_INCLUDED
