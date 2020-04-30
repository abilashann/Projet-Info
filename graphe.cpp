#include "graphe.h"
#include "svg/svgfile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Graphe::Graphe (std::string nomFichier )
{
    int ordre; /// sommet
    int taille; ///arete
    int taille2;
    std::ifstream fichier(nomFichier);
    if (!fichier)
    {
        throw std::runtime_error("impossible d'ouvrir le fichier");
    }

    fichier>> m_orientation;
    fichier>> ordre;


    for(int i=0; i<ordre; i++)
    {
        m_sommet.push_back(new Sommet(fichier));
    }

    fichier >> taille;
    std::string nomdufichier2="0";
    int choix;
    std::cout << "Voulez ouvrir un fichier pondere? 1 pour oui 2 pour non" << std::endl;
    while(choix!=1 && choix!=2)
        std::cin >> choix;
    if (choix==1)
    {
        std::cout << "Nom du fichier :" << std::endl;
        std::cin >> nomdufichier2;
        std::ifstream fichier2(nomdufichier2);
        if (!fichier2)
        {
            throw std::runtime_error("impossible d'ouvrir le fichier");
        }
        fichier2 >> taille2;
        for (int z=0; z<taille; ++z)
        {
            m_arete.push_back(new Arete(fichier,fichier2));
        }
    }
    else
    {
        for (int z=0; z<taille; ++z)
        {
            m_arete.push_back(new Arete(fichier));
        }
    }
    if(m_orientation==1)
    {

        for (size_t y=0; y<m_arete.size(); ++y)
        {
            m_sommet[m_arete[y]->get_ID1()]->remplir(m_sommet[m_arete[y]->get_ID2()],m_arete[y]->get_Poids());
        }
    }
    else if (m_orientation==0)
    {

        for (size_t y=0; y<m_arete.size(); ++y)
        {
            m_sommet[m_arete[y]->get_ID1()]->remplir(m_sommet[m_arete[y]->get_ID2()],m_arete[y]->get_Poids());
            m_sommet[m_arete[y]->get_ID2()]->remplir(m_sommet[m_arete[y]->get_ID1()],m_arete[y]->get_Poids());
        }
    }
}


void Graphe::afficher()
{
    int ordre = m_sommet.size();
    int taille = m_arete.size();
    if (m_orientation== 0)
    {
        std::cout << "graphe non oriente" << std:: endl;
    }
    else
    {
        std::cout << "graphe oriente" << std::endl;
    }

    std:: cout << "ordre = " << ordre << std::endl;

    /*for(int i=0; i<ordre; ++i)
    {
        m_arete[i]->affichage();
    }*/
    for (const auto& s : m_sommet)
    {
        std::cout << "  " << *s << std::endl;
    }
    std:: cout << "taille = " << taille << std::endl;
    for (const auto& s : m_arete)
    {
        std::cout << "  " << *s << std::endl;
    }

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        m_sommet[i]->afficherAdj();
        std::cout<<std::endl;

    }
    Svgfile svgout;
    svgout.addGrid();
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        svgout.addCircle(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0,5,1,"black");
        svgout.addText(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0-5.0,m_sommet[i]->get_nom(),"black");
    }
    for (size_t j=0; j<m_sommet.size(); ++j)
    {
        for(size_t y=0; y<m_arete.size(); ++y)
        {
            if(m_arete[y]->get_ID1()==m_sommet[j]->get_id())
            {
                for (size_t z=0; z<m_sommet.size(); ++z)
                {
                    if(m_arete[y]->get_ID2()==m_sommet[z]->get_id())
                    {
                        svgout.addLine(m_sommet[j]->get_x()*100.0,m_sommet[j]->get_y()*100.0,m_sommet[z]->get_x()*100.0,m_sommet[z]->get_y()*100.0,"black");
                    }

                }

            }

        }
    }
}

/*
int Graphe::Dijkstra(int i_debut, int i_fin)
{
    int longeur=0;
    ///initialisation
    for (auto it : m_sommet)
        it->setMarquage(0);

    int tab_distance[m_sommet.size()]; //recupère les plus court chemin de s0 à chaque sommet parcouru
    //std::vector <Sommet*> sommetsParcourus; //recupère la liste et l'odre dans lequel les sommets sont parcouru
    int tab_predecesseurs[m_sommet.size()];

    for (size_t i=0; i<m_sommet.size(); ++i)
        tab_distance[i]=999; //~infini

    for (size_t i=0; i<m_sommet.size(); ++i)
        tab_predecesseurs[i]=99;


    Sommet*s=m_sommet[i_debut]; //s=s0
    tab_distance[i_debut]=0;
    m_sommet[i_debut]->setMarquage(1);//1 pour dire qu'on a trouver la plus petite distance
    //sommetsParcourus.push_back(m_sommets[i_debut]);

    int distance, d_min, id_d_min;

    ///recherche

    do
    {
        d_min=999;
        //on determine le plus proche de s0 en partant de s
        for (auto it : m_sommet)
        {
            if (s->estAdjacentA(it->get_id())) //si on peut aller de s à it
            {
                distance=s->getDist(it->get_id());

                if (tab_distance[it->get_id()]>tab_distance[s->get_id()]+distance)//si c'est plus court d'aller de s0 à it en passant par s
                {
                    //si on trouve un plus court chemin que celui en mémoire
                    tab_distance[it->get_id()]=tab_distance[s->get_id()]+distance;
                    tab_predecesseurs[it->get_id()]=s->get_id();
                }
            }

        }
        //recherche du plus près sommet de s0 qui n'a pas encore était étudié
        for (size_t i=0; i<m_sommet.size(); ++i) //on parcours la tab de distance
        {
            if (m_sommet[i]->getMarquage()!=1) //pas parcouru
            {
                if (tab_distance[i]<d_min) //si c'est le plus près
                {
                    d_min=tab_distance[i];
                    id_d_min=i; //on garde en mémoire l'identifiant du plus près
                }
            }
        }
        s=m_sommet[id_d_min]; //le plus proche sommet pas encore etudier devient le prochain sommet à parcourir
        s->setMarquage(1);//1 pour dire qu'on a trouver la plus petite distance
        //sommetsParcourus.push_back(s);

    }
    while (m_sommet[i_fin]->getMarquage()!=1);  //tant qu'on a pas trouver le plus court chemin jusqu'au sommet final


    ///affichage

    std::cout<<std::endl;

    std::vector<Sommet*> sommetsParcourus; //liste de sommets en chemin
    sommetsParcourus.push_back(m_sommet[i_fin]);
    int pred;
    int temp=tab_predecesseurs[i_fin];
    if (temp!=99)
    {
        std::cout<<std::endl<<i_fin;
        if (i_debut!=temp)
        {
            do
            {
                //on remonte le tableau jusqu'à ce que le predecesseur soit s0
                pred = temp;
                std::cout<<" <-- "<<pred; //on aficche chaque predecesseur
                sommetsParcourus.push_back(m_sommet[pred]); //on ajoute à la liste chaque predecesseur
                temp=tab_predecesseurs[pred];

            }
            while (i_debut!=pred);

        }

        else //si pas d'intermédiaire entre s0 et le sommet de fin
            std::cout<<" <-- "<<i_debut;
    }

    //on affiche la longeur pour chaque arc parcouru
    std::cout<<" longeur = ";
    size_t taille=sommetsParcourus.size();

    if (taille!=1) //si s0 et le sommet final sont adjacents
    {
        for (size_t i=taille-1 ; i>1; --i) //sens inverse parce que pour remplir le vecteur on est partie de la fin
        {
            std::cout<<sommetsParcourus[i]->getDist(sommetsParcourus[i-1]->get_id())<<"+";
        }
        std::cout<<sommetsParcourus[1]->getDist(sommetsParcourus[0]->get_id())<<"=";
    }
    std::cout<<tab_distance[i_fin];
    longeur=tab_distance[i_fin];
    return longeur;
}

void Graphe::Dijkstra_pour_toutes_les aretes(int i_debut,int i_fin)
{ for( int i_debut=0; i_debut<m_sommet.size();i_debut++){
 for(int i_fin=0; i_fin<m_sommet.size();i_fin++){
    Dijkstra(i_debut,int i_fin);}}
}*/



void Graphe::centraliteDegre()
{
    float Cd=0;
    float Cdn=0;
    int ordre = m_sommet.size();

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        m_sommet[i]->set_Cd(Cd);
        Cd = m_sommet[i]->get_degre();
        std::cout<< "Cd " << i << " : " << std::endl;
        m_sommet[i]->set_Cdn(Cdn);
        Cdn=Cd/ordre - 1;
        std::cout<<"Cdn " << i << " : " << Cdn << std::endl;
        std::cout << std::endl;
    }
}


void Graphe::centraliteVecteurPropre()
{
    ///initialisation variable
    float lambda = 0.0;
    float lambda_prev = 0.0;

    float somme_indice=0;
    float NI = 0;


    ///initialisation

    for(size_t i = 0; i<m_sommet.size() ; i++)
    {
        m_sommet[i]->set_Cvp(1);
        std::cout <<" indice n "<< i <<" : " << m_sommet[i]->get_Cvp() << std::endl;
    }

    /// calcul
    do
    {
        ///parcours des sommets
        for(size_t i = 0; i<m_sommet.size(); i++)
        {
            float somme_adj = 0.0;
            somme_indice= 0;

            ///parcours des adj de m_sommet[i]

            for(auto it: m_sommet[i]->get_adj())
            {
                somme_adj+= it.first->get_Cvp();

                ///std::cout << "TEST : " << it.first->get_Cvp() << std::endl;
                m_sommet[i]->set_C(somme_adj);
            }
        }

        for(size_t i = 0; i<m_sommet.size(); i++)
        {

            somme_indice += m_sommet[i]->get_C()* m_sommet[i]->get_C();
            std::cout <<"somme des indices voisins : " << m_sommet[i]->get_C()  << std::endl;
            std::cout <<"somme des indices voisins au carre : " << m_sommet[i]->get_C()* m_sommet[i]->get_C()  << std::endl;
        }
        std::cout << "somme indice TOTAL : " << somme_indice << std::endl;




        ///calcul de lambda
        lambda_prev = lambda;
        lambda = sqrt(somme_indice);

        std::cout << "lambda : " << lambda << "   lambda precedent : " << lambda_prev << std::endl;

        /// calcul nouvel indice
        for(size_t i=0 ; i<m_sommet.size(); i++)
        {

            NI = m_sommet[i]->get_C()/lambda;
            m_sommet[i]->set_Cvp(NI);
            std::cout << "calcule nouvel indice : " << m_sommet[i]->get_Cvp() << std::endl;
        }
    }
    while(abs(lambda - lambda_prev) > 0.6);



}

/*
void Graphe::CritereProximite()
{
    float Cn[m_sommet.size()]; // Normalisé
    float Cnn[m_sommet.size()]; // Non normalisé
    float Somme=0;;
    int longeur=0;
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        for (size_t y=0; y<m_sommet.size(); ++y)
        {
            if (i==y)
            {
                longeur=0;
            }
            else
            {
                longeur=Dijkstra(i,y);
            }

            Somme+=longeur;
            longeur=0;
        }
        std::cout << std::endl;
        std::cout << "Somme = :" << Somme<< std::endl;
        if(Somme!=0)
        {
            Cn[i]=((m_sommet.size()-1)/(Somme));
            Cnn[i]=((1)/(Somme));
            std::cout<< "Cn numero :"<< i << " = " << Cn[i] << std::endl;
        std::cout<< "Cnn numero :"<< i << " = " << Cnn[i] << std::endl;
        }
Somme=0;

    }
}
*/

