#include "graphe.h"
#include "svgfile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

<<<<<<< Updated upstream
Graphe::Graphe (std::string nomFichier )
=======
Graphe::Graphe (std::string nomFichier)
{
    std::cout << "Voulez ouvrir un fichier pondere? 1 pour oui 2 pour non" << std::endl;
    while(m_choix!=1 && m_choix!=2)
        std::cin >> m_choix;
    pondere(nomFichier,m_choix);
    CreationAdj();
}

void Graphe::pondere(std::string nomFichier,int choix)
>>>>>>> Stashed changes
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
    int distance, d_min, id_d_min;

    ///initialisation
    for (auto it : m_sommet)
        it->setMarquage(0);

<<<<<<< Updated upstream
    int tab_distance[m_sommet.size()]; //recupère les plus court chemin de s0 à chaque sommet parcouru
    //std::vector <Sommet*> sommetsParcourus; //recupère la liste et l'odre dans lequel les sommets sont parcouru
=======
    ///recupÃ¨re les plus court chemin de s0 Ã  chaque sommet parcouru
    ///std::vector <Sommet*> sommetsParcourus; //recupÃ¨re la liste et l'odre dans lequel les sommets sont parcouru
    int tab_distance[m_sommet.size()];
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
/*
void Graphe::Dijkstra_pour_toutes_les aretes(int i_debut,int i_fin)
{ for( int i_debut=0; i_debut<m_sommet.size();i_debut++){
 for(int i_fin=0; i_fin<m_sommet.size();i_fin++){
    Dijkstra(i_debut,int i_fin);}}
}*/



void Graphe::centraliteDegre()
{
    std::cout << "          -----  Calcul indice centralite degre  -----" << std::endl;
    ///initialisation
    float Cd=0;
    float Cdn=0;
    int ordre = m_sommet.size();
    int j=0;

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
<<<<<<< Updated upstream
        //on récupère le degre [i] du sommet que l'on met dans la variable
        //on met cet valeur dans le Cd de la classe sommet
        Cd = m_sommet[i]->get_degre();
        m_sommet[i]->set_Cd(Cd);
        std::cout<< "Cd " << i << " : " << m_sommet[i]->get_Cd() << std::endl;
        //calcul de Cp normalisé
        Cdn=Cd/(ordre - 1);
        m_sommet[i]->set_Cdn(Cdn);
        std::cout<<"Cdn " << i << " : " << m_sommet[i]->get_Cdn() << std::endl;
        std::cout << std::endl;
=======
        std::cout <<"tour "<< j <<" : "<<std::endl;
        //on rÃ©cupÃ¨re le degre [i] du sommet que l'on met dans la variable
        //on met cet valeur dans le Cd de la classe sommet
        Cd = m_sommet[i]->get_degre();
        m_sommet[i]->set_Cd(Cd);
        std::cout<< "Centralite degre " << i << " : " << m_sommet[i]->get_Cd() << std::endl;
        //calcul de Cp normalisÃ©
        Cdn=Cd/(ordre - 1);
        m_sommet[i]->set_Cdn(Cdn);
        std::cout<<"Centralite degre normalise " << i << " : " << m_sommet[i]->get_Cdn() << std::endl << std::endl;
        m_afficheIndice=1; // Dire que l'indice vient d'etre calculÃ©
        j+=1;
>>>>>>> Stashed changes
    }
    std::cout << std::endl << std::endl;
}


void Graphe::centraliteVecteurPropre()
{
    std::cout << "          -----  Calcul indice centralite vecteur propre  -----" << std::endl << std::endl;
    ///initialisation variable
    float lambda = 0.0;
    float lambda_prev = 0.0;

    float somme_indice=0;
    float NI = 0;
    int i=0;


    ///initialisation

    for(size_t i = 0; i<m_sommet.size() ; i++)
    {
<<<<<<< Updated upstream
        m_sommet[i]->set_Cvp(1);
        std::cout <<" indice n "<< i <<" : " << m_sommet[i]->get_Cvp() << std::endl;
=======
        m_sommet[i]->set_Cvpn(1);
        ///std::cout <<" indice n "<< i <<" : " << m_sommet[i]->get_Cvpn() << std::endl;
>>>>>>> Stashed changes
    }

    /// calcul
    do
    {
        i+=1;
        std::cout << "tour "<< i <<" : "  << std::endl;
        ///parcours des sommets
        for(size_t i = 0; i<m_sommet.size(); i++)
        {
            float somme_adj = 0.0;
            somme_indice= 0;

            ///parcours des adj de m_sommet[i]
            for(auto it: m_sommet[i]->get_adj())
            {
<<<<<<< Updated upstream
                somme_adj+= it.first->get_Cvp();

                ///std::cout << "TEST : " << it.first->get_Cvp() << std::endl;
                m_sommet[i]->set_C(somme_adj);
=======
                somme_adj+= it.first->get_Cvpn();
                m_sommet[i]->set_Cvp(somme_adj);
>>>>>>> Stashed changes
            }
        }
        ///on recupère la somme des indices par sommet et Total
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
<<<<<<< Updated upstream
    }
    while(abs(lambda - lambda_prev) > 0.01); // condition pour que lambda soit stable
=======

    std::cout << std::endl;
    }
    while(abs(lambda - lambda_prev) > 0.01); // condition pour que lambda soit stable
    std::cout << std::endl;
>>>>>>> Stashed changes
}

void Graphe::CritereProximite()
{
<<<<<<< Updated upstream
    double Cp; // non Normalisé
    double Cpn; // normalisé
=======
    std::cout << "          -----  Calcul indice centralite proximite  -----" << std::endl << std::endl;
    double Cp; // non NormalisÃ©
    double Cpn; // normalisÃ©
    int k=0;
>>>>>>> Stashed changes
    float Somme=0;;
    int longeur=0;
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        k+=1;
        std::cout << "tour "<< k <<" : ";
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
<<<<<<< Updated upstream
            Cp=((m_sommet.size()-1)/(Somme));
            Cpn=((1)/(Somme));
=======
            Cp=((1)/(Somme));
            Cpn=((m_sommet.size()-1)/(Somme));
>>>>>>> Stashed changes
            m_sommet[i]->set_Cp(Cp);
            m_sommet[i]->set_Cpn(Cpn);
            std::cout<< "Cp numero :"<< i << " = " << m_sommet[i]->get_Cp() << std::endl;
            std::cout<< "Cpn numero :"<< i << " = " << m_sommet[i]->get_Cpn() << std::endl;
        }
        Somme=0;
    }
    std::cout << std::endl << std::endl;
}

void Graphe::sauvegarde()
{
    std::ofstream fichier("IndiceSave.txt");
    std::cout << "Enregistrement des donnees . . . " <<std::endl;
    if (fichier)
    {
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
            fichier << "sommet : " << i << "    Cd : " << m_sommet[i]->get_Cd() << "    Cdn :  " << m_sommet[i]->get_Cdn() << "    Cvp : "
            << m_sommet[i]->get_Cvp() << "    Cp :  "
            << m_sommet[i]->get_Cp() << "    Cpn : " << m_sommet[i]->get_Cpn() <<std::endl;
        }
    }
    else
    {
        std::cout << "Impossible d'ecrire/ouvrir sur le fichier" <<std::endl;
    }
    std::cout << "vous avez bien enregistrer les donnees dans le fichier" <<std::endl;

}
<<<<<<< Updated upstream
=======

void Graphe::affichage_centralite()
{
    std::cout << "------------------------------------------------  INDICE DE CENTRALITE  ------------------------------------------------"<<std::endl;


    for (size_t i=0; i<m_sommet.size(); ++i)
    {

        int entier1 = (int)( m_sommet[i]->get_Cd() * 1000.0);
        int entier2 = (int)( m_sommet[i]->get_Cdn() * 1000.0);
        int entier3 = (int)( m_sommet[i]->get_Cvp() * 1000.0);
        int entier4 = (int)( m_sommet[i]->get_Cvpn() * 1000.0);
        int entier5 = (int)( m_sommet[i]->get_Cp() * 1000.0);
        int entier6 = (int)( m_sommet[i]->get_Cpn() * 1000.0);

        if(100.0 * m_sommet[i]->get_Cd() - (double)entier1 >= 0.5)
            ++entier1;
        if(100.0 * m_sommet[i]->get_Cdn() - (double)entier2 >= 0.5)
            ++entier2;
        if(100.0 * m_sommet[i]->get_Cvp() - (double)entier3 >= 0.5)
            ++entier3;
        if(100.0 * m_sommet[i]->get_Cvpn() - (double)entier4 >= 0.5)
            ++entier4;
        if(100.0 * m_sommet[i]->get_Cp() - (double)entier5 >= 0.5)
            ++entier5;
        if(100.0 * m_sommet[i]->get_Cpn() - (double)entier6 >= 0.5)
            ++entier6;

        m_sommet[i]->set_Cd((double)entier1 / 1000.0);
        m_sommet[i]->set_Cdn((double)entier2 / 1000.0);
        m_sommet[i]->set_Cvp((double)entier3 / 1000.0);
        m_sommet[i]->set_Cvpn((double)entier4 / 1000.0);
        m_sommet[i]->set_Cp((double)entier5 / 1000.0);
        m_sommet[i]->set_Cpn((double)entier6 / 1000.0);


        std::cout << "     ------------------------------------------------- SOMMET " << i << " ---------------------------------------------------     "<<std::endl;

        std::cout <<"   centralite degre : "<< m_sommet[i]->get_Cd() << std::endl;
        std::cout <<"   centralite degre normalise : "<< m_sommet[i]->get_Cdn() << std::endl << std::endl;
        std::cout <<"   centralite vecteur propre : "<< m_sommet[i]->get_Cvp() << std::endl;
        std::cout <<"   centralite vecteur propre normalise : "<< m_sommet[i]->get_Cvpn() << std::endl << std::endl;
        std::cout <<"   centralite proximite : "<< m_sommet[i]->get_Cp() << std::endl;
        std::cout <<"   centralite proximite normalise : "<< m_sommet[i]->get_Cpn()<< std::endl<< std::endl;

    }
std::cout << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;
}

void Graphe::Suppressionarete()
{
    int taille = m_arete.size();
    int choix;
    int indice;

    std::cout << "il y a : "<< taille << " arete dans le graph" <<std::endl;
    std::cout << "Nombre d'arrete a supprimer? " <<std::endl;
    std::cin >> choix;
    for(int i=0;i<choix;++i)
    {
        std::cout << "Indice de l'arrete? " <<std::endl;
        std::cin >> indice;
        for(size_t j=0;j<m_arete.size();++j)
        {
            if(indice==m_arete[j]->get_id())
                {
                    m_sommet[m_arete[j]->get_ID1()]->suppadj(m_sommet[m_arete[j]->get_ID2()]);
                    m_sommet[m_arete[j]->get_ID2()]->suppadj(m_sommet[m_arete[j]->get_ID1()]);
                    m_arete.erase(m_arete.begin()+j);
                }

>>>>>>> Stashed changes


<<<<<<< Updated upstream

=======
    ///affichage
    /*for (auto it : compoConnexes)
    {
        std::cout<<std::endl<<"Composante connexe "<<it.first<<" : ";
        for (auto et : it.second)
            std::cout<<et<<" ";
    }*/
    //std::cout<<"Composante taille : "<< compoConnexes.size()<<std::endl;
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
    std::cout << "----------------------------------------------------  VULNERABILTE  ----------------------------------------------------"<<std::endl;
    std::cout << std::endl;
    int identifiant;

    float Cd_modif;
    float Cdn_modif;
    float Cvp_modif;
    float Cvpn_modif;
    float Cp_modif;
    float Cpn_modif;

    float diff_Cd;
    float diff_Cdn;
    float diff_Cvp;
    float diff_Cvpn;
    float diff_Cp;
    float diff_Cpn;

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

        std::cout << "     ------------------------------------------------- SOMMET " << i << " ---------------------------------------------------     "<<std::endl;
        std::cout << std::endl;
        std::cout <<"indice de centralite obtenus avant changement " << std::endl;
        std::cout <<"identifiant : "<< i << std::endl;
        std::cout <<" Centralite degre non normalise :  "<< m_sommet[i]->get_Cd() << " normalise :  "<< m_sommet[i]->get_Cdn()<< std::endl;
        std::cout <<" Centralite vecteur propre non normalise :  "<< m_sommet[i]->get_Cvp() << " normalise :  "<< m_sommet[i]->get_Cvpn()<< std::endl;
        std::cout <<" Centralite proximite non normalise :  "<< m_sommet[i]->get_Cp() << " normalise :  "<< m_sommet[i]->get_Cpn()<< std::endl;
        std::cout <<std::endl;

        std::cout <<std::endl;
        std::cout <<"indice de centralite obtenus apres changement" <<  std::endl;
        std::cout << "identifiant: " << identifiant << std::endl;
        std::cout <<" Centralite degre non normalise :  "<< Cd_modif << " normalise :  "<< Cdn_modif<< std::endl;
        std::cout <<" Centralite vecteur propre non normalise :  "<< Cvp_modif << " normalise :  "<< Cvpn_modif<< std::endl;
        std::cout <<" Centralite proximite non normalise :  "<< Cp_modif << " normalise :  "<< Cpn_modif<< std::endl;

        diff_Cd = abs(m_sommet[i]->get_Cd()- Cd_modif);
        diff_Cdn = abs(m_sommet[i]->get_Cdn()- Cdn_modif);
        diff_Cvp = abs(m_sommet[i]->get_Cvp()- Cvp_modif);
        diff_Cvpn = abs(m_sommet[i]->get_Cvpn()- Cvpn_modif);
        diff_Cp = abs(m_sommet[i]->get_Cp()- Cp_modif);
        diff_Cpn = abs(m_sommet[i]->get_Cpn()- Cpn_modif);
    }
        std::cout << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;

    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        std::cout << "     --------------------------------------------- DIFFERENCE INDICE " << i << " -----------------------------------------------     "<<std::endl;
        std::cout <<"difference d'indice avant et apres changement " << std::endl;
        std::cout <<"identifiant : "<< i << std::endl;
        std::cout <<" difference centralite degre non normalise :  "<< diff_Cd  << " normalise : "<< diff_Cdn << std::endl;
        std::cout <<" difference centralite vecteur propre non normalise:  "<<diff_Cvp  << " normalise : "<< diff_Cvpn << std::endl;
        std::cout <<" difference centralite proximite non normalise :  "<<diff_Cp  << " normalise : "<< diff_Cpn << std::endl;
        std::cout <<std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;
}
>>>>>>> Stashed changes
