#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <cmath>

class Sommet
{
    private:
        ///propriete
        int m_id;
        std::string m_nom;
        int m_x;
        int m_y;

        ///indice
        float m_Cvp;
        float m_Cd;
        float m_Cdn;
        float m_C;

        int m_marquage;

        ///adjacence
        std::map<Sommet*,int> m_adjacents;

    public:
        /// constructeur
        Sommet (std::istream& is);

        ///getter
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();

        void Adj(int num);
        void affichage();

        std::map<Sommet*,int> get_adj() {return m_adjacents;}

        float get_Cvp();
        float get_Cdn() {return m_Cdn;}
        int get_Cd();
        int get_degre() {return m_adjacents.size();}
        float get_C() {return m_C;}

        ///setter
        void setMarquage(int nv);
        void set_Cvp(float NV) {m_Cvp = NV; }
        int set_Cd(int cd);
        void set_C(float C) {m_C= C;}
        void set_Cdn(int cdn) {m_Cdn = cdn;}

        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);
        void remplir(Sommet* adjacent,int poids);
        void afficherAdj();

        bool estAdjacentA(int i);
        int getMarquage()const;
        int getDist(int i);


};

#endif // SOMMET_H_INCLUDED
