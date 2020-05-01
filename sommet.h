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
<<<<<<< Updated upstream
        float m_C;
=======
        //vecteur propre
        float m_Cvp;
        float m_Cvpn;
        //proximite
>>>>>>> Stashed changes
        double m_Cp;
        double m_Cpn;

        ///indice centralité modifié
        float m_Cd_modif;
        float m_Cdn_modif;
        float m_Cvp_modif;
        float m_Cvpn_modif;
        double m_Cp_modif;
        double m_Cpn_modif;

        int m_marquage;
        int m_couleur;

        ///adjacence
        std::map<Sommet*,int> m_adjacents;

    public:
        /// constructeur
        Sommet (std::istream& is);

        ///getter
<<<<<<< Updated upstream
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();

        void Adj(int num);
        void affichage();
        void suppadj(Sommet* j);
        void reinitialiserCouleur();
        void setCouleur(int nv);
        int getCouleur()const;
=======

        //propriete
        int get_id() {return m_id;}
        std::string get_nom() {return m_nom; }
        int get_x() {return m_x;}
        int get_y() {return m_y; }

        //indice centralite
        float get_Cd(){return m_Cd;}
        float get_Cdn() {return m_Cdn;}
        float get_Cvp() {return m_Cvp;}
        float get_Cvpn(){return m_Cvpn;}
        double get_Cp(){return m_Cp;}
        double get_Cpn(){return m_Cpn;}

        //indice centralité modifié
        float get_Cd_modif(){return m_Cd;}
        float get_Cdn_modif() {return m_Cdn_modif;}
        float get_Cvp_modif() {return m_Cvp_modif;}
        float get_Cvpn_modif(){return m_Cvpn_modif;}
        double get_Cp_modif(){return m_Cp_modif;}
        double get_Cpn_modif(){return m_Cpn_modif;}
>>>>>>> Stashed changes

        std::map<Sommet*,int> get_adj() {return m_adjacents;}

        float get_Cvp();
        float get_Cdn() {return m_Cdn;}
        int get_Cd();
        double get_Cp();
        double get_Cpn();
        int get_degre() {return m_adjacents.size();}
        float get_C() {return m_C;}

        ///setter
<<<<<<< Updated upstream
        void setMarquage(int nv);
        void set_Cvp(float NV) {m_Cvp = NV; }
        void set_Cp(double NV);
        void set_Cpn(double NV);
        int set_Cd(int cd);
        void set_C(float C) {m_C= C;}
        void set_Cdn(float cdn) {m_Cdn = cdn;}
=======
        //indice centralité
        void set_Cd(int nv) {m_Cd = nv;}
        void set_Cdn(float nv) {m_Cdn = nv;}
        void set_Cvp(float nv) {m_Cvp = nv;}
        void set_Cvpn(float nv) {m_Cvpn = nv; }
        void set_Cp(double nv) {m_Cp = nv;}
        void set_Cpn(double nv){m_Cpn = nv;}
        //indice centralité modifié
        void set_Cd_modif(int nv) {m_Cd_modif = nv;}
        void set_Cdn_modif(float nv) {m_Cdn_modif = nv;}
        void set_Cvp_modif(float nv) {m_Cvp_modif = nv;}
        void set_Cvpn_modif(float nv) {m_Cvpn_modif = nv; }
        void set_Cp_modif(double nv) {m_Cp_modif = nv;}
        void set_Cpn_modif(double nv){m_Cpn_modif = nv;}

        void setMarquage(int nv) {m_marquage = nv;}
        void setCouleur(int nv) {m_couleur = nv;}
>>>>>>> Stashed changes

        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);
        void remplir(Sommet* adjacent,int poids);
        void afficherAdj();
        void setMarquage(int nv);
        bool estAdjacentA(int i);
        int getMarquage()const;
        int getDist(int i);

        bool estAdjacentA(int i);
        int getMarquage()const;
        int getDist(int i);


};

#endif // SOMMET_H_INCLUDED
