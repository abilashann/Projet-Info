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
        //degre
        float m_Cd;
        float m_Cdn;
        //vecteur propre
        float m_Cvp;
        float m_C;
        //proximite
        double m_Cp;
        double m_Cpn;

        int m_marquage;

        ///adjacence
        std::map<Sommet*,int> m_adjacents;

    public:
        /// constructeur
        Sommet (std::istream& is);
        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);

        ///getter
<<<<<<< Updated upstream
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();

        void Adj(int num);
        void affichage();
=======
        //propriete
        int get_id() {return m_id;}
        std::string get_nom() {return m_nom; }
        int get_x() {return m_x;}
        int get_y() {return m_y; }
        //centralite
        int get_Cd(){return m_Cd;}
        float get_Cdn() {return m_Cdn;}
        float get_Cvp(){return m_Cvp;}
        float get_C() {return m_C;}
        double get_Cp(){return m_Cp;}
        double get_Cpn(){return m_Cpn;}
>>>>>>> Stashed changes

        int get_degre() {return m_adjacents.size();}
        std::map<Sommet*,int> get_adj() {return m_adjacents;}
        int getDist(int i);

        int getMarquage()const {return m_marquage;}
        int getCouleur()const {return m_couleur;}

        ///setter
        void set_Cd(int nv) {m_Cd = nv;}
        void set_Cdn(float nv) {m_Cdn = nv;}
        void set_Cvp(float nv) {m_Cvp = nv; }
        void set_C(float nv) {m_C= nv;}
        void set_Cp(double nv) {m_Cp = nv;}
        void set_Cpn(double nv){m_Cpn = nv;}

        void setMarquage(int nv) {m_marquage = nv;}
        void setCouleur(int nv) {m_couleur = nv;}

        ///fonction
        void affichage();
        void afficherAdj();
        void remplir(Sommet* adjacent,int poids);
        bool estAdjacentA(int i);
        void Adj(int num);
        void suppadj(Sommet* j);
        void reinitialiserCouleur();
};

#endif // SOMMET_H_INCLUDED
