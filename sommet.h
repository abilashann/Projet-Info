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
        ///propriete
        int m_id;
        std::string m_nom;
        int m_x;
        int m_y;

        ///indice de centralite
        float m_Cd;
        float m_Cdn;
        float m_Cvp;

        //std::vector<int> m_degre;
        std::vector<Sommet*> m_adj;


    public:
        Sommet (std::istream& is);
        //void Adj(int num);
        void affichage();
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();
        float get_Cd();

        std::vector<Sommet*> get_adj();
        int get_degre(){ return m_adj.size(); }

        Sommet* get_current_sommet()
        {
            return this;
        }


        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);
        void addAdj (Sommet* new_adj);
        void afficherAdj();
        void set_Cd(float Cd);
        float get_Cvp() { return m_Cvp; }
        void set_Cvp(int new_value) { m_Cvp = new_value; }


};

#endif // SOMMET_H_INCLUDED
