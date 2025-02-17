#include "graphe.h"
#include "svgfile.h"
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
<<<<<<< Updated upstream
   CreationAdj();
=======
    CreationAdj();
>>>>>>> Stashed changes
}
void Graphe::CreationAdj()
{
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
int Graphe::Dijkstra(int i_debut, int i_fin)
{
    int longeur=0;
    ///initialisation
    for (auto it : m_sommet)
        it->setMarquage(0);

    int tab_distance[m_sommet.size()]; //recup�re les plus court chemin de s0 � chaque sommet parcouru
    //std::vector <Sommet*> sommetsParcourus; //recup�re la liste et l'odre dans lequel les sommets sont parcouru
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
            if (s->estAdjacentA(it->get_id())) //si on peut aller de s � it
            {
                distance=s->getDist(it->get_id());

                if (tab_distance[it->get_id()]>tab_distance[s->get_id()]+distance)//si c'est plus court d'aller de s0 � it en passant par s
                {
                    //si on trouve un plus court chemin que celui en m�moire
                    tab_distance[it->get_id()]=tab_distance[s->get_id()]+distance;
                    tab_predecesseurs[it->get_id()]=s->get_id();
                }
            }

        }
        //recherche du plus pr�s sommet de s0 qui n'a pas encore �tait �tudi�
        for (size_t i=0; i<m_sommet.size(); ++i) //on parcours la tab de distance
        {
            if (m_sommet[i]->getMarquage()!=1) //pas parcouru
            {
                if (tab_distance[i]<d_min) //si c'est le plus pr�s
                {
                    d_min=tab_distance[i];
                    id_d_min=i; //on garde en m�moire l'identifiant du plus pr�s
                }
            }
        }
        s=m_sommet[id_d_min]; //le plus proche sommet pas encore etudier devient le prochain sommet � parcourir
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
                //on remonte le tableau jusqu'� ce que le predecesseur soit s0
                pred = temp;
                std::cout<<" <-- "<<pred; //on aficche chaque predecesseur
                sommetsParcourus.push_back(m_sommet[pred]); //on ajoute � la liste chaque predecesseur
                temp=tab_predecesseurs[pred];

            }
            while (i_debut!=pred);

        }

        else //si pas d'interm�diaire entre s0 et le sommet de fin
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
/*
void Graphe::Dijkstra_pour_toutes_les aretes(int i_debut,int i_fin)
{ for( int i_debut=0; i_debut<m_sommet.size();i_debut++){
 for(int i_fin=0; i_fin<m_sommet.size();i_fin++){
    Dijkstra(i_debut,int i_fin);}}
}*/
void Graphe::CritereProximite()
{
    float Cn[m_sommet.size()]; // Normalis�
    float Cnn[m_sommet.size()]; // Non normalis�
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


int Graphe::Dijkstra(int i_debut, int i_fin)
{
    int longeur=0;
    ///initialisation
    for (auto it : m_sommet)
        it->setMarquage(0);

<<<<<<< Updated upstream
    int tab_distance[m_sommet.size()]; //recup�re les plus court chemin de s0 � chaque sommet parcouru
    //std::vector <Sommet*> sommetsParcourus; //recup�re la liste et l'odre dans lequel les sommets sont parcouru
=======
    int tab_distance[m_sommet.size()]; //recupère les plus court chemin de s0 à chaque sommet parcouru
    //std::vector <Sommet*> sommetsParcourus; //recupère la liste et l'odre dans lequel les sommets sont parcouru
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
            if (s->estAdjacentA(it->get_id())) //si on peut aller de s � it
            {
                distance=s->getDist(it->get_id());

                if (tab_distance[it->get_id()]>tab_distance[s->get_id()]+distance)//si c'est plus court d'aller de s0 � it en passant par s
                {
                    //si on trouve un plus court chemin que celui en m�moire
=======
            if (s->estAdjacentA(it->get_id())) //si on peut aller de s à it
            {
                distance=s->getDist(it->get_id());

                if (tab_distance[it->get_id()]>tab_distance[s->get_id()]+distance)//si c'est plus court d'aller de s0 à it en passant par s
                {
                    //si on trouve un plus court chemin que celui en mémoire
>>>>>>> Stashed changes
                    tab_distance[it->get_id()]=tab_distance[s->get_id()]+distance;
                    tab_predecesseurs[it->get_id()]=s->get_id();
                }
            }

        }
<<<<<<< Updated upstream
        //recherche du plus pr�s sommet de s0 qui n'a pas encore �tait �tudi�
=======
        //recherche du plus près sommet de s0 qui n'a pas encore était étudié
>>>>>>> Stashed changes
        for (size_t i=0; i<m_sommet.size(); ++i) //on parcours la tab de distance
        {
            if (m_sommet[i]->getMarquage()!=1) //pas parcouru
            {
<<<<<<< Updated upstream
                if (tab_distance[i]<d_min) //si c'est le plus pr�s
                {
                    d_min=tab_distance[i];
                    id_d_min=i; //on garde en m�moire l'identifiant du plus pr�s
                }
            }
        }
        s=m_sommet[id_d_min]; //le plus proche sommet pas encore etudier devient le prochain sommet � parcourir
=======
                if (tab_distance[i]<d_min) //si c'est le plus près
                {
                    d_min=tab_distance[i];
                    id_d_min=i; //on garde en mémoire l'identifiant du plus près
                }
            }
        }
        s=m_sommet[id_d_min]; //le plus proche sommet pas encore etudier devient le prochain sommet à parcourir
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
                //on remonte le tableau jusqu'� ce que le predecesseur soit s0
                pred = temp;
                std::cout<<" <-- "<<pred; //on aficche chaque predecesseur
                sommetsParcourus.push_back(m_sommet[pred]); //on ajoute � la liste chaque predecesseur
=======
                //on remonte le tableau jusqu'à ce que le predecesseur soit s0
                pred = temp;
                std::cout<<" <-- "<<pred; //on aficche chaque predecesseur
                sommetsParcourus.push_back(m_sommet[pred]); //on ajoute à la liste chaque predecesseur
>>>>>>> Stashed changes
                temp=tab_predecesseurs[pred];

            }
            while (i_debut!=pred);

        }

<<<<<<< Updated upstream
        else //si pas d'interm�diaire entre s0 et le sommet de fin
=======
        else //si pas d'intermédiaire entre s0 et le sommet de fin
>>>>>>> Stashed changes
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

void Graphe::centraliteDegre()
{
    float Cd=0;
    float Cdn=0;
    int ordre = m_sommet.size();

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
<<<<<<< Updated upstream
        Cd = m_sommet[i]->get_degre();
        m_sommet[i]->set_Cd(Cd);
        std::cout<< "Cd " << i << " : " << m_sommet[i]->get_Cd() << std::endl;
=======
        //on récupère le degre [i] du sommet que l'on met dans la variable
        //on met cet valeur dans le Cd de la classe sommet
        Cd = m_sommet[i]->get_degre();
        m_sommet[i]->set_Cd(Cd);
        std::cout<< "Cd " << i << " : " << m_sommet[i]->get_Cd() << std::endl;
        //calcul de Cp normalisé
>>>>>>> Stashed changes
        Cdn=Cd/(ordre - 1);
        m_sommet[i]->set_Cdn(Cdn);
        std::cout<<"Cdn " << i << " : " << m_sommet[i]->get_Cdn() << std::endl;
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
        m_sommet[i]->set_Cvpn(1);
        std::cout <<" indice n "<< i <<" : " << m_sommet[i]->get_Cvpn() << std::endl;
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
                somme_adj+= it.first->get_Cvpn();

                ///std::cout << "TEST : " << it.first->get_Cvpn() << std::endl;
                m_sommet[i]->set_Cvp(somme_adj);
            }
        }
<<<<<<< Updated upstream

=======
        ///on recupère la somme des indices par sommet et Total
>>>>>>> Stashed changes
        for(size_t i = 0; i<m_sommet.size(); i++)
        {

            somme_indice += m_sommet[i]->get_Cvp()* m_sommet[i]->get_Cvp();
            std::cout <<"somme des indices voisins : " << m_sommet[i]->get_Cvp()  << std::endl;
            std::cout <<"somme des indices voisins au carre : " << m_sommet[i]->get_Cvp()* m_sommet[i]->get_Cvp()  << std::endl;
        }
        std::cout << "somme indice TOTAL : " << somme_indice << std::endl;




        ///calcul de lambda
        lambda_prev = lambda;
        lambda = sqrt(somme_indice);

        std::cout << "lambda : " << lambda << "   lambda precedent : " << lambda_prev << std::endl;

        /// calcul nouvel indice
        for(size_t i=0 ; i<m_sommet.size(); i++)
        {
<<<<<<< Updated upstream

            NI = m_sommet[i]->get_C()/lambda;
            m_sommet[i]->set_Cvp(NI);
            std::cout << "calcule nouvel indice : " << m_sommet[i]->get_Cvp() << std::endl;
        }
    }
    while(abs(lambda - lambda_prev) > 0.01);
=======
            NI = m_sommet[i]->get_Cvp()/lambda;
            m_sommet[i]->set_Cvpn(NI);
            std::cout << "calcule nouvel indice : " << m_sommet[i]->get_Cvpn() << std::endl;
        }
    }
    while(abs(lambda - lambda_prev) > 0.01); // condition pour que lambda soit stable

    /*
    for(size_t i = 0; i<m_sommet.size(); i++)
    {
        ///std::cout << "FINALEMENT" << std::endl;
        //std::cout << " CVP non  normalise" << m_sommet[i]->get_Cvp() << std::endl;
        ///std::cout << " CVP normalise" << m_sommet[i]->get_Cvpn() << std::endl;
    }
    */

>>>>>>> Stashed changes
}


void Graphe::CritereProximite()
{
<<<<<<< Updated upstream
    double Cp; // Normalis�
    double Cpn; // Non normalis�
=======
    double Cp; // non Normalisé
    double Cpn; // normalisé
>>>>>>> Stashed changes
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
            Cp=((m_sommet.size()-1)/(Somme));
            Cpn=((1)/(Somme));
            m_sommet[i]->set_Cp(Cp);
            m_sommet[i]->set_Cpn(Cpn);
            std::cout<< "Cn numero :"<< i << " = " << m_sommet[i]->get_Cp() << std::endl;
            std::cout<< "Cnn numero :"<< i << " = " << m_sommet[i]->get_Cpn() << std::endl;
        }
        Somme=0;

    }
}
void Graphe::sauvegarde()
{
    std::ofstream fichier("IndiceSave.txt");
    if (fichier)
    {
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
<<<<<<< Updated upstream
            fichier << i << " " << m_sommet[i]->get_Cd() << " " << m_sommet[i]->get_Cdn() << " "
            << m_sommet[i]->get_Cvp() << " "
            << m_sommet[i]->get_Cp() << " " << m_sommet[i]->get_Cpn() <<std::endl;
=======
            fichier << i << "   " << m_sommet[i]->get_Cd()
                    << "   " << m_sommet[i]->get_Cdn()
                    << "   " << m_sommet[i]->get_Cvp()
                    << "   " << m_sommet[i]->get_Cvpn()
                    << "   " << m_sommet[i]->get_Cp()
                    << "   " << m_sommet[i]->get_Cpn() <<std::endl;
>>>>>>> Stashed changes
        }
    }
    else
    {
        std::cout << "Impossible d'ecrire/ouvrir sur le fichier" <<std::endl;
    }

}
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
void Graphe::Suppressionarete()
{
    int choix;
    int indice;
<<<<<<< Updated upstream
=======
    int taille = m_arete.size();

    std::cout << "il y a : "<< taille << " arete dans le graph" <<std::endl;
>>>>>>> Stashed changes
    std::cout << "Nombre d'arrete a supprimer? " <<std::endl;
    std::cin >> choix;
    for(int i=0; i<choix; ++i)
    {
        std::cout << "Indice de l'arrete? " <<std::endl;
        std::cin >> indice;
        for(size_t j=0; j<m_arete.size(); ++j)
        {
            if(indice==m_arete[j]->get_id())
            {
                m_sommet[m_arete[j]->get_ID1()]->suppadj(m_sommet[m_arete[j]->get_ID2()]);
                m_sommet[m_arete[j]->get_ID2()]->suppadj(m_sommet[m_arete[j]->get_ID1()]);
                m_arete.erase(m_arete.begin()+j);
            }


        }
    }
}

void Graphe::recuDFS(std::map<int, int>& i_preds,Sommet* s)
{
    //algorithme recurence de Mme Palasi
    s->setCouleur(1);//gris
    for (auto it : m_sommet)
    {
        if (it->estAdjacentA(s->get_id()))
        {
            if (it->getCouleur()==0) //si ne fait pas d�j� partie de la pile
            {
                i_preds[it->get_id()]=s->get_id();
                recuDFS(i_preds,it); //par recurence

            }
        }

    }
    s->setCouleur(2); //met en noir

}

void Graphe::Connexite()
{
    int nbCompo=0;
    bool stop = false;
    std::map<int, int> i_preds; //liste des prdecesseurs pour le DFS
    std::map<int,std::vector<int>> compoConnexes; //num�ro et identidfiant des sommets de chaque composante

    ///mets les sommets en blancs
    for (auto it : m_sommet)
        it->reinitialiserCouleur();

    ///recherche de composante de sommets
    do
    {
        stop=false;
        for (auto it : m_sommet)
        {

            if (it->getCouleur()!=2 && !stop)
            {
                //si on d�couvre un nouveau sommet qui n'a pas encore �t� rang� dan sune composante connexe
                ++nbCompo; //nouvelle composante
                compoConnexes[nbCompo].push_back(it->get_id()); //on ajoute le premier dans une nouvel composante que l'on cr�e
                recuDFS(i_preds,it); //recherche de tous les sommets de la composante avec un DFS
                if (!i_preds.empty())
                    for (auto et : i_preds)
                        compoConnexes[nbCompo].push_back(et.first); //on ajoute tous les sommets trouv� � la composante


<<<<<<< Updated upstream

        }
    }
}
void Graphe::recuDFS(std::map<int, int>& i_preds,Sommet* s)
{
    //algorithme recurence de Mme Palasi
    s->setCouleur(1);//gris
    for (auto it : m_sommet)
    {
        if (it->estAdjacentA(s->get_id()))
        {
            if (it->getCouleur()==0) //si ne fait pas d�j� partie de la pile
            {
                i_preds[it->get_id()]=s->get_id();
                recuDFS(i_preds,it); //par recurence

            }
        }

    }
    s->setCouleur(2); //met en noir

}
void Graphe::Connexite()
{
    int nbCompo=0;
    bool stop = false;
    std::map<int, int> i_preds; //liste des prdecesseurs pour le DFS
    std::map<int,std::vector<int>> compoConnexes; //num�ro et identidfiant des sommets de chaque composante

    ///mets les sommets en blancs
    for (auto it : m_sommet)
        it->reinitialiserCouleur();

    ///recherche de composante de sommets
    do
    {
        stop=false;
        for (auto it : m_sommet)
        {

            if (it->getCouleur()!=2 && !stop)
            {
                //si on d�couvre un nouveau sommet qui n'a pas encore �t� rang� dan sune composante connexe
                ++nbCompo; //nouvelle composante
                compoConnexes[nbCompo].push_back(it->get_id()); //on ajoute le premier dans une nouvel composante que l'on cr�e
                recuDFS(i_preds,it); //recherche de tous les sommets de la composante avec un DFS
                if (!i_preds.empty())
                    for (auto et : i_preds)
                        compoConnexes[nbCompo].push_back(et.first); //on ajoute tous les sommets trouv� � la composante


                stop=true; //on s'occupe d'une composante � la fois
            }

        }
        i_preds.clear(); //on recommence en vidant la liste de sommets

    }
    while (stop); //tant qu'il a des sommets qui n'ont pas �t� parcouru

    ///affichage
    for (auto it : compoConnexes)
    {
        std::cout<<std::endl<<"Composante connexe "<<it.first<<" : ";
        for (auto et : it.second)
            std::cout<<et<<" ";
    }
std::cout<<"Composante taille : "<< compoConnexes.size()<<std::endl;
if (compoConnexes.size()>1)
{
    std::cout<<"Le graph n'est pas connexe "<< std::endl;
}
else
{
    std::cout<<"Le graph est connexe "<< std::endl;
}
=======
                stop=true; //on s'occupe d'une composante � la fois
            }

        }
        i_preds.clear(); //on recommence en vidant la liste de sommets

    }
    while (stop); //tant qu'il a des sommets qui n'ont pas �t� parcouru

    ///affichage
    for (auto it : compoConnexes)
    {
        std::cout<<std::endl<<"Composante connexe "<<it.first<<" : ";
        for (auto et : it.second)
            std::cout<<et<<" ";
    }
    std::cout<<"Composante taille : "<< compoConnexes.size()<<std::endl;
    if (compoConnexes.size()>1)
    {
        std::cout<<"Le graphe n'est pas connexe "<< std::endl;
    }
    else
    {
        std::cout<<"Le graphe est connexe "<< std::endl;
    }
}

void Graphe :: lectureFichierCentralite(std::string nomFichier)
{
    int identifiant;

    float Cd_modif;
    float Cdn_modif;
    float Cvp_modif;
    float Cvpn_modif;
    float Cp_modif;
    float Cpn_modif;

    std::ifstream fichier(nomFichier);
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        fichier >> identifiant;
        fichier >> Cd_modif;
        fichier >> Cdn_modif;
        fichier >> Cvp_modif;
        fichier >> Cvpn_modif;
        fichier >> Cp_modif;
        fichier >> Cpn_modif;
        //std::cout << "identifiant: " << identifiant;
        //std::cout <<" Cd_modif :  "<< Cd_modif << " Cdn_modif :  "<< Cdn_modif;
        //std::cout <<" Cvp_modif :  "<< Cvp_modif << " Cvpn_modif :  "<< Cvpn_modif;
        //std::cout <<" Cp_modif :  "<< Cp_modif << " Cpn_modif :  "<< Cpn_modif<< std::endl;

        m_sommet[i]->set_Cd_modif(Cd_modif);
        m_sommet[i]->set_Cdn_modif(Cdn_modif);
        m_sommet[i]->set_Cvp_modif(Cvp_modif);
        m_sommet[i]->set_Cvpn_modif(Cvpn_modif);
        m_sommet[i]->set_Cp_modif(Cp_modif);
        m_sommet[i]->set_Cpn_modif(Cpn_modif);
        std::cout << std::endl;
        //std::cout <<"identifiant: " << identifiant;
        //std::cout <<" Cd_modif :  "<< m_sommet[i]->get_Cd_modif() << " Cdn_modif :  "<< m_sommet[i]->get_Cdn_modif();
        //std::cout <<" Cvp_modif :  "<< m_sommet[i]->get_Cvp_modif() << " Cvpn_modif :  "<< m_sommet[i]->get_Cvpn_modif();
        //std::cout <<" Cp_modif :  "<< m_sommet[i]->get_Cp_modif() << " Cpn_modif :  "<< m_sommet[i]->get_Cpn_modif()<< std::endl;
    }
}

void Graphe :: difference()
{
    float diff_Cd;
    float diff_Cdn;
    float diff_Cvp;
    float diff_Cvpn;
    float diff_Cp;
    float diff_Cpn;

    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        std::cout <<std::endl;
        std::cout <<"indice de centralite obtenus avant changement" <<  std::endl;
        std::cout <<"identifiant : "<< i;
        std::cout <<" Cd_modif :  "<< m_sommet[i]->get_Cd_modif() << " Cdn_modif :  "<< m_sommet[i]->get_Cdn_modif();
        std::cout <<" Cvp_modif :  "<< m_sommet[i]->get_Cvp_modif() << " Cvpn_modif :  "<< m_sommet[i]->get_Cvpn_modif();
        std::cout <<" Cp_modif :  "<< m_sommet[i]->get_Cp_modif() << " Cpn_modif :  "<< m_sommet[i]->get_Cpn_modif()<< std::endl;

        std::cout <<"indice de centralite obtenus apres changement " << std::endl;
        std::cout <<"identifiant : "<< i;
        std::cout <<" Cd :  "<< m_sommet[i]->get_Cd() << " Cdn :  "<< m_sommet[i]->get_Cdn();
        std::cout <<" Cvp :  "<< m_sommet[i]->get_Cvp() << " Cvpn :  "<< m_sommet[i]->get_Cvpn();
        std::cout <<" Cp :  "<< m_sommet[i]->get_Cp() << " Cpn :  "<< m_sommet[i]->get_Cpn()<< std::endl;
        std::cout <<std::endl;

        diff_Cd = abs(m_sommet[i]->get_Cd()- m_sommet[i]->get_Cd_modif());
        diff_Cdn = abs(m_sommet[i]->get_Cdn()- m_sommet[i]->get_Cdn_modif());
        diff_Cvp = abs(m_sommet[i]->get_Cvp()- m_sommet[i]->get_Cvp_modif());
        diff_Cvpn = abs(m_sommet[i]->get_Cvpn()- m_sommet[i]->get_Cvpn_modif());
        diff_Cp = abs(m_sommet[i]->get_Cp()- m_sommet[i]->get_Cp_modif());
        diff_Cpn = abs(m_sommet[i]->get_Cpn()- m_sommet[i]->get_Cpn_modif());
    }

    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        std::cout <<"difference d'indice avant et apres changement " << std::endl;
        std::cout <<"identifiant : "<< i;
        std::cout <<" diff_Cd :  "<< diff_Cd  << " diff_Cdn :  "<< diff_Cdn ;
        std::cout <<" diff_Cvp :  "<<diff_Cvp  << " diff_Cvpn :  "<< diff_Cvpn ;
        std::cout <<" diff_Cp :  "<<diff_Cp  << " diff_Cpn :  "<< diff_Cpn << std::endl;
        std::cout <<std::endl;
    }
>>>>>>> Stashed changes
}

