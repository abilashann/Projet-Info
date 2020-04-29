#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <string>
<<<<<<< Updated upstream
=======
#include <map>
#include <cmath>

>>>>>>> Stashed changes
class Sommet
{
    private:
        ///propriete
        int m_id;
        std::string m_nom;
        int m_x;
        int m_y;
<<<<<<< Updated upstream
        std::vector<int> m_sommet;
        int m_degre;
=======

        ///indice
        float m_Cvp;
        float m_Cd;

        int m_marquage;

        ///adjacence
        std::map<Sommet*,int> m_adjacents;
>>>>>>> Stashed changes

    public:
        /// constructeur
        Sommet (std::istream& is);

        ///getter
        int get_id();
        std::string get_nom();
        int get_x();
        int get_y();
<<<<<<< Updated upstream
        int get_degre();
        std::vector<Sommet*> get_adj();
=======

        void Adj(int num);
        void affichage();

        std::map<Sommet*,int> get_adj() {return m_adjacents;}

        int get_Cvp();
        int get_Cd();
        int get_degre() {return m_adjacents.size();}

        ///setter
        void setMarquage(int nv);
        int set_Cvp(int nouvVal);
        int set_Cd(int cd);

>>>>>>> Stashed changes
        friend std::ostream& operator<< (std::ostream& out, const Sommet& s);
        void addAdj (int ID);
        void afficherAdj();
<<<<<<< Updated upstream
=======

        bool estAdjacentA(int i);
        int getMarquage()const;
        int getDist(int i);
>>>>>>> Stashed changes


};

#endif // SOMMET_H_INCLUDED
