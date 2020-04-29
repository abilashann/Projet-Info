#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <map>

class Sommet
{
    private:
        int m_id;
        std::string m_nom;
        int m_x;
        int m_y;
        int m_marquage;
        std::map<Sommet*,int> m_adjacents;

    public:
        Sommet (std::istream& is);
        void Adj(int num);
        void affichage();
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();
        std::vector<Sommet*> get_adj();
        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);
        void remplir(Sommet* adjacent,int poids);
        void afficherAdj();
        void setMarquage(int nv);
        bool estAdjacentA(int i);
        int getMarquage()const;
        int getDist(int i);


};

#endif // SOMMET_H_INCLUDED
