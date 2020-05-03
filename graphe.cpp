#include "graphe.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Graphe::Graphe (std::string nomFichier)
{
    std::ifstream fichier(nomFichier);
    fichier>> m_orientation;
    fichier>> m_ordre;
    if (!fichier)
    {
        throw std::runtime_error("impossible d'ouvrir le fichier");
    }
    for(int i=0; i<m_ordre; i++)
    {
        m_sommet.push_back(new Sommet(fichier));
    }

    fichier >> m_taille;

    for (int z=0; z<m_taille; ++z)
    {
        m_arete.push_back(new Arete(fichier));
    }
    std::cout << "Voulez ouvrir un fichier pondere? 1 pour oui 2 pour non" << std::endl;
    while(m_choix!=1 && m_choix!=2)
        std::cin >> m_choix;
    pondere(nomFichier,m_choix);
    CreationAdj();
}

void Graphe::pondere(std::string nomFichier,int choix)
{

    int id2;
    int poids;
    if (choix==1)
    {
        std::string nomdufichier2;
        std::cout << "Nom du fichier :" << std::endl;
        std::cin >> nomdufichier2;
        int taille2;
        std::ifstream fichier2(nomdufichier2);
        if (!fichier2)
        {
            throw std::runtime_error("impossible d'ouvrir le fichier");
        }
        fichier2 >> taille2;
        for (int z=0; z<m_taille; ++z)
        {
            fichier2 >> id2 >> poids;
            m_arete[z]->set_id2(id2);
            m_arete[z]->set_Poids(poids);
        }
        for (size_t i =0 ; i<m_sommet.size(); ++i)
        {
            for (int z=0; z<m_taille; ++z)
            {
                if(m_orientation==0)
                {
                    m_sommet[i]->changementpoids(m_arete[z]->get_ID1(),m_arete[z]->get_ID2(),m_arete[z]->get_Poids());
                    m_sommet[i]->changementpoids(m_arete[z]->get_ID2(),m_arete[z]->get_ID1(),m_arete[z]->get_Poids());
                }
                else
                {
                    m_sommet[i]->changementpoids(m_arete[z]->get_ID1(),m_arete[z]->get_ID2(),m_arete[z]->get_Poids());
                }
            }
        }
    }
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
        std::cout << "  graphe non oriente" << std:: endl;
    }
    else
    {
        std::cout << "  graphe oriente" << std::endl;
    }
    std::cout << std::endl;
    std:: cout << "ordre : " << ordre << std::endl;

    for (const auto& s : m_sommet)
    {
        std::cout << "  " << *s << std::endl;
    }
    std::cout << std::endl;
    std:: cout << "taille = " << taille << std::endl;
    for (const auto& s : m_arete)
    {
        std::cout << "  " << *s << std::endl;
    }
    std::cout << std::endl;
    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        m_sommet[i]->afficherAdj();
        std::cout<<std::endl;

    }
    std::cout << std::endl;

    Svgfile svgout;
    svgout.addGrid();
    int maxi=0;
    std::string color;
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        if(m_sommet[i]->get_degre()>maxi)
        {
            maxi=m_sommet[i]->get_degre();
        }
    }
    //std::cout<< "Valeur maxi : " << maxi << std::endl;
    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        //std::cout<< "Degre : " << i << " "<< m_sommet[i]->get_degre()<< std::endl;
        //std::cout<< "Valeur : " << i << " "<< val << std::endl;
        svgout.addCircle(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0,7,1,"black");
        svgout.addText(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0-5.0,m_sommet[i]->get_nom(),"black");
    }
    if(m_afficheIndice==1)
    {
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
            /// Arrondi au centieme
            double valeur1 = m_sommet[i]->get_Cd();
            int entier1 = (int)((0.005 + valeur1) * 100.0);
            double result1 = (double)entier1 / 100.0;
            double valeur2 = m_sommet[i]->get_Cdn();
            int entier2 = (int)((0.005 + valeur2) * 100.0);
            double result2 = (double)entier2 / 100.0;
            double valeur3 = m_sommet[i]->get_Cvp();
            int entier3 = (int)((0.005 + valeur3) * 100.0);
            double result3 = (double)entier3 / 100.0;
            double valeur4 = m_sommet[i]->get_Cvpn();
            int entier4 = (int)((0.005 + valeur4) * 100.0);
            double result4 = (double)entier4 / 100.0;
            double valeur5 = m_sommet[i]->get_Cp();
            int entier5 = (int)((0.005 + valeur5) * 100.0);
            double result5 = (double)entier5 / 100.0;
            double valeur6 = m_sommet[i]->get_Cpn();
            int entier6 = (int)((0.005 + valeur6) * 100.0);
            double result6 = (double)entier6 / 100.0;

            svgout.addText(m_sommet[i]->get_x()*100.0+15,m_sommet[i]->get_y()*100.0,result1,"green");
            svgout.addText(m_sommet[i]->get_x()*100.0+30,m_sommet[i]->get_y()*100.0,result2,"green");
            svgout.addText(m_sommet[i]->get_x()*100.0+15,m_sommet[i]->get_y()*100.0+20,result3,"green");
            svgout.addText(m_sommet[i]->get_x()*100.0+50,m_sommet[i]->get_y()*100.0+20,result4,"green");
            svgout.addText(m_sommet[i]->get_x()*100.0+15,m_sommet[i]->get_y()*100.0+40,result5,"green");
            svgout.addText(m_sommet[i]->get_x()*100.0+50,m_sommet[i]->get_y()*100.0+40,result6,"green");
            float val=m_sommet[i]->get_degre()*1.0/maxi*1.0;
            //std::cout<< "Degre : " << i << " "<< m_sommet[i]->get_degre()<< std::endl;
            //std::cout<< "Valeur : " << i << " "<< val << std::endl;
            if(val >0 && val <= 0.1 )
                color="blue";
            if(val >0.1 && val <= 0.2 )
                color="cyan";
            if(val >0.2 && val <= 0.3 )
                color="darkgreen";
            if(val >0.3 && val <= 0.4 )
                color="lightgreen";
            if(val >0.4 && val <= 0.5 )
                color="yellow";
            if(val >0.5 && val <= 0.6 )
                color="orange";
            if(val >0.6 && val <= 0.7 )
                color="brown";
            if(val >0.7 && val <= 0.8 )
                color="magenta";
            if(val >0.8 && val <= 0.9 )
                color="indigo";
            if(val >0.9 && val <1 )
                color="darkred";
            if(val==1)
                color="red";
            svgout.addCircle(m_sommet[i]->get_x()*100.0,m_sommet[i]->get_y()*100.0,7,1,color);
        }
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
                        svgout.addText((m_sommet[j]->get_x()*100.0+m_sommet[z]->get_x()*100.0)/2+3,(m_sommet[j]->get_y()*100.0+m_sommet[z]->get_y()*100.0)/2-5,m_arete[y]->get_Poids(),"red");
                        if(m_orientation==1)
                        {
                            afficherfleche(svgout,m_sommet[j]->get_x(),m_sommet[j]->get_y(),m_sommet[z]->get_x(),m_sommet[z]->get_y());
                        }
                    }
                }
            }
        }
    }

}


int Graphe::Dijkstra(int i_debut, int i_fin)
{
    int longeur=0;
    int distance, d_min, id_d_min=0;

    ///initialisation
    for (auto it : m_sommet)
        it->setMarquage(0);

    ///recupère les plus court chemin de s0 à chaque sommet parcouru
    ///std::vector <Sommet*> sommetsParcourus; //recupère la liste et l'odre dans lequel les sommets sont parcouru
    int tab_distance[m_sommet.size()];
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
        //std::cout<<std::endl<<i_fin;
        if (i_debut!=temp)
        {
            do
            {
                //on remonte le tableau jusqu'à ce que le predecesseur soit s0
                pred = temp;
                //std::cout<<" <-- "<<pred; //on aficche chaque predecesseur
                sommetsParcourus.push_back(m_sommet[pred]); //on ajoute à la liste chaque predecesseur
                temp=tab_predecesseurs[pred];

            }
            while (i_debut!=pred);

        }

        //else //si pas d'intermédiaire entre s0 et le sommet de fin
            //std::cout<<" <-- "<<i_debut;
    }

    //on affiche la longeur pour chaque arc parcouru
    //std::cout<<" longeur = ";
    size_t taille=sommetsParcourus.size();

    if (taille!=1) //si s0 et le sommet final sont adjacents
    {
        for (size_t i=taille-1 ; i>1; --i) //sens inverse parce que pour remplir le vecteur on est partie de la fin
        {
            //std::cout<<sommetsParcourus[i]->getDist(sommetsParcourus[i-1]->get_id())<<"+";
        }
        //std::cout<<sommetsParcourus[1]->getDist(sommetsParcourus[0]->get_id())<<"=";
    }
    //std::cout<<tab_distance[i_fin];
    longeur=tab_distance[i_fin];
    return longeur;
}

void Graphe::centraliteDegre()
{
    std::cout << "          ----  Calcul indice centralite degre  -----" << std::endl;
    ///initialisation
    float Cd=0;
    float Cdn=0;
    int ordre = m_sommet.size();
    int j=0;

    for (size_t i =0 ; i<m_sommet.size(); ++i)
    {
        std::cout <<"tour "<< j <<" : "<<std::endl;
        //on récupère le degre [i] du sommet que l'on met dans la variable
        //on met cet valeur dans le Cd de la classe sommet
        Cd = m_sommet[i]->get_degre();
        m_sommet[i]->set_Cd(Cd);
        std::cout<< "Centralite degre " << i << " : " << m_sommet[i]->get_Cd() << std::endl;
        //calcul de Cp normalisé
        Cdn=Cd/(ordre - 1);
        m_sommet[i]->set_Cdn(Cdn);
        std::cout<<"Centralite degre normalise " << i << " : " << m_sommet[i]->get_Cdn() << std::endl << std::endl;
        m_afficheIndice=1; // Dire que l'indice vient d'etre calculé
        j+=1;
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
        m_sommet[i]->set_Cvpn(1);
        ///std::cout <<" indice n "<< i <<" : " << m_sommet[i]->get_Cvpn() << std::endl;
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
                somme_adj+= it.first->get_Cvpn();
                m_sommet[i]->set_Cvp(somme_adj);
            }
        }
        ///on recupère la somme des indices par sommet et Total
        for(size_t i = 0; i<m_sommet.size(); i++)
        {

            somme_indice += m_sommet[i]->get_Cvp()* m_sommet[i]->get_Cvp();
            //std::cout <<"somme des indices voisins : " << m_sommet[i]->get_Cvp()  << std::endl;
            //std::cout <<"somme des indices voisins au carre : " << m_sommet[i]->get_Cvp()* m_sommet[i]->get_Cvp()  << std::endl;
        }
        std::cout << "somme indice TOTAL : " << somme_indice << std::endl;

        ///calcul de lambda
        lambda_prev = lambda;
        lambda = sqrt(somme_indice);
        std::cout << "lambda : " << lambda << "   lambda precedent : " << lambda_prev << std::endl;

        /// calcul nouvel indice
        for(size_t i=0 ; i<m_sommet.size(); i++)
        {
            NI = m_sommet[i]->get_Cvp()/lambda;
            m_sommet[i]->set_Cvpn(NI);
            std::cout << "calcule nouvel indice : " << m_sommet[i]->get_Cvpn() << std::endl;
        }

        std::cout << std::endl;
    }
    while(abs(lambda - lambda_prev) > 0.01); // condition pour que lambda soit stable
    std::cout << std::endl;
}

void Graphe::CritereProximite()
{
    std::cout << "          -----  Calcul indice centralite proximite  -----" << std::endl << std::endl;
    double Cp; // non Normalisé
    double Cpn; // normalisé
    int k=0;
    float Somme=0;;
    int longeur=0;
    if(m_connexite==0)
    {
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
                Cp=((1)/(Somme));
                Cpn=((m_sommet.size()-1)/(Somme));
                m_sommet[i]->set_Cp(Cp);
                m_sommet[i]->set_Cpn(Cpn);
                std::cout<< "Cp numero :"<< i << " = " << m_sommet[i]->get_Cp() << std::endl;
                std::cout<< "Cpn numero :"<< i << " = " << m_sommet[i]->get_Cpn() << std::endl;
            }
            Somme=0;
        }
        std::cout << std::endl << std::endl;
    }
    else
    {
        std::cout <<" Le graph n'etant pas connexe le calcul du critere de proximite est impossible, les indices auront comme valeur 0" << std::endl;
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
            m_sommet[i]->set_Cp(0);
            m_sommet[i]->set_Cpn(0);
        }
    }

}

void Graphe::sauvegarde()
{
    std::ofstream fichier("IndiceSave.txt");
    std::cout << "Enregistrement des donnees . . . " <<std::endl;
    if (fichier)
    {
        for (size_t i=0; i<m_sommet.size(); ++i)
        {
            fichier << i << "   " << m_sommet[i]->get_Cd()
                    << "   " << m_sommet[i]->get_Cdn()
                    << "   " << m_sommet[i]->get_Cvp()
                    << "   " << m_sommet[i]->get_Cvpn()
                    << "   " << m_sommet[i]->get_Cp()
                    << "   " << m_sommet[i]->get_Cpn() <<std::endl;
        }
    }
    else
    {
        std::cout << "Impossible d'ecrire/ouvrir sur le fichier" <<std::endl;
    }
    std::cout << "vous avez bien enregistrer les donnees dans le fichier" <<std::endl;

}

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
    int choix;
    int indice;
    int taille = m_arete.size();

    std::cout << "Il y a : "<< taille << " arete dans le graphe" <<std::endl;
    do
    {
        std::cout << "Nombre d'arrete a supprimer? " <<std::endl;
        std::cin >> choix;
    }
    while(choix > taille || choix <0);


    for(int i=0; i<choix; ++i)
    {
        do
        {
            std::cout << "Arete numero : " << i+1<< " a supprimer "<< std::endl;
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
        while(indice > taille || choix <0);
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
        std::cout<<"Le graphe n'est pas connexe "<< std::endl;
        m_connexite=1;
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
    int entier1,entier2,entier3,entier4,entier5,entier6;
    double result1,result2,result3,result4,result5,result6;
    centraliteDegre();
    centraliteVecteurPropre();
    CritereProximite();
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
        std::cout <<"indice de centralite obtenus avant changement" <<  std::endl;
        std::cout << "identifiant: " << identifiant << std::endl;
        std::cout <<" Centralite degre non normalise :  "<< Cd_modif << " normalise :  "<< Cdn_modif<< std::endl;
        std::cout <<" Centralite vecteur propre non normalise :  "<< Cvp_modif << " normalise :  "<< Cvpn_modif<< std::endl;
        std::cout <<" Centralite proximite non normalise :  "<< Cp_modif << " normalise :  "<< Cpn_modif<< std::endl;
        std::cout <<std::endl;
        std::cout <<"indice de centralite obtenus apres changement " << std::endl;
        std::cout <<"identifiant : "<< i << std::endl;
        std::cout <<" Centralite degre non normalise :  "<< m_sommet[i]->get_Cd() << " normalise :  "<< m_sommet[i]->get_Cdn()<< std::endl;
        std::cout <<" Centralite vecteur propre non normalise :  "<< m_sommet[i]->get_Cvp() << " normalise :  "<< m_sommet[i]->get_Cvpn()<< std::endl;
        std::cout <<" Centralite proximite non normalise :  "<< m_sommet[i]->get_Cp() << " normalise :  "<< m_sommet[i]->get_Cpn()<< std::endl;
        std::cout <<std::endl;


        diff_Cd = m_sommet[i]->get_Cd()- Cd_modif;
        diff_Cdn = m_sommet[i]->get_Cdn()- Cdn_modif;
        diff_Cvp = m_sommet[i]->get_Cvp()- Cvp_modif;
        diff_Cvpn = m_sommet[i]->get_Cvpn()- Cvpn_modif;
        diff_Cp = m_sommet[i]->get_Cp()- Cp_modif;
        diff_Cpn = m_sommet[i]->get_Cpn()- Cpn_modif;
        /// CONVERSION EN 2 CHIFFRE APRES LA VIRGULE
        entier1 = (int)((0.005 + diff_Cd) * 100.0);
        entier2 = (int)((0.005 + diff_Cdn) * 100.0);
        entier3 = (int)((0.005 + diff_Cvp) * 100.0);
        entier4 = (int)((0.005 + diff_Cvpn) * 100.0);
        entier5 = (int)((0.005 + diff_Cp) * 100.0);
        entier6 = (int)((0.005 + diff_Cpn) * 100.0);
result1 = (double)entier1 / 100.0;
result2= (double)entier2 / 100.0;
result3 = (double)entier3 / 100.0;
result4 = (double)entier4 / 100.0;
result5 = (double)entier5 / 100.0;
result6 = (double)entier6 / 100.0;
    }
    std::cout << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;

    for (size_t i=0; i<m_sommet.size(); ++i)
    {
        std::cout << "     --------------------------------------------- DIFFERENCE INDICE " << i << " -----------------------------------------------     "<<std::endl;
        std::cout <<"difference d'indice avant et apres changement " << std::endl;
        std::cout <<"identifiant : "<< i << std::endl;
        std::cout <<" difference centralite degre non normalise :  "<< result1  << " normalise : "<< result2 << std::endl;
        std::cout <<" difference centralite vecteur propre non normalise:  "<<result3  << " normalise : "<< result4 << std::endl;
        std::cout <<" difference centralite proximite non normalise :  "<<result5  << " normalise : "<< result6 << std::endl;
        std::cout <<std::endl;
    }
    std::cout << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;
}
void Graphe::afficherfleche(Svgfile& svgout, double x1, double y1, double x2, double y2)
{
    if(x1<x2 && y1 == y2) ///1
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0-5,y2*100.0-5,x2*100.0-10,y2*100.0+5,"red",1,"black");
    }
    if(x1>x2 && y1 == y2) ///2
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0+5,y2*100.0-5,x2*100.0+5,y2*100.0+5,"red",1,"black");
    }
    if(x1==x2 && y1 > y2) ///3
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0-5,y2*100.0+5,x2*100.0+5,y2*100.0+5,"red",1,"black");
    }
    if(x1==x2 && y1 < y2)  ///4
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0-5,y2*100.0-5,x2*100.0+5,y2*100.0-5,"red",1,"black");
    }
    if(x1> x2 && y1 > y2)  ///5
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0+5,y2*100.0+10,x2*100.0+10,y2*100.0+5,"red",1,"black");
    }
    if(x1> x2 && y1 < y2) ///6
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0+5,y2*100.0-10,x2*100.0+10,y2*100.0-5,"red",1,"black");
    }
    if(x1< x2 && y1 > y2) ///7
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0-10,y2*100.0+5,x2*100.0-5,y2*100.0+10,"red",1,"black");
    }
    if(x1< x2 && y1 < y2) ///8
    {
        svgout.addTriangle(x2*100.0,y2*100.0,x2*100.0-10,y2*100.0-5,x2*100.0-5,y2*100.0-10,"red",1,"black");
    }

}

int Graphe::Dijkstra_avec_affichageV2Passagesommet(int i_debut, int i_fin, int sommet_choisi)
{
    int longueur2=0;
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
    std::vector<Sommet*> sommetsParcourus; //liste de sommets en chemin
    sommetsParcourus.push_back(m_sommet[i_fin]);
    int pred;
    int temp=tab_predecesseurs[i_fin];
    if (temp!=99)
    {
        //std::cout<<std::endl<<i_fin;
        if (i_debut!=temp)
        {
            do
            {
                //on remonte le tableau jusqu'à ce que le predecesseur soit s0
                pred = temp;
                //std::cout<<" <-- "<<pred; //on aficche chaque predecesseur
                sommetsParcourus.push_back(m_sommet[pred]);//on ajoute à la liste chaque predecesseur
                if(temp==sommet_choisi){
                    longueur2=1;
                }
                temp=tab_predecesseurs[pred];
            }
            while (i_debut!=pred);

        }

        /*else //si pas d'intermédiaire entre s0 et le sommet de fin
            std::cout<<" <-- "<<i_debut;
            std::cout<<";";*/

    }
    return longueur2;
}
int Graphe::Dijkstra_sans_affichage(int i_debut, int i_fin)
{
    int longeur=0;
    ///initialisation
    for (auto it : m_sommet)
        it->setMarquage(0);

    int tab_distance[m_sommet.size()]; //recupère les plus court chemin de s0 à chaque sommet parcouru
    //std::vector <Sommet*> sommetsParcourus; //recupère la liste et l'odre dans lequel les sommets sont parcouru

    for (size_t i=0; i<m_sommet.size(); ++i)
        tab_distance[i]=999; //~infini

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
    longeur=tab_distance[i_fin];
    return longeur;
}
void Graphe::Critere_intermediarite(int sommet_choisi)
{
    int nombre=0;
    int nombre1=0;
    double indice=0;
    double indicenormalise=0;
    for (size_t k=0; k<m_sommet.size()+1; k++)
    {
        sommet_choisi=m_sommet[k]->get_id();

    for (size_t i=0; i<m_sommet.size(); i++)
    {
        for(size_t j=i; j<m_sommet.size(); j++)
        {
            if(m_sommet[i]->get_id()!=sommet_choisi)
            {
                if(m_sommet[j]->get_id()!=sommet_choisi)
                {

                    if(Dijkstra_sans_affichage(m_sommet[i]->get_id(),m_sommet[j]->get_id())!=0)
                    {
                        nombre=1;
                        nombre1=0;
                        if(Dijkstra_avec_affichageV2Passagesommet(m_sommet[i]->get_id(),m_sommet[j]->get_id(),sommet_choisi)==1)
                        {
                            nombre1=1;

                        }
                        indice=indice+nombre1/nombre;
                    }
                }
            }
        }
    }
    indicenormalise=indicenormalise+2*indice/(m_sommet.size()*m_sommet.size()-3*m_sommet.size()+2);
    std::cout<<"\nPour le sommet:"<<sommet_choisi<<"\nL'indice d'intermediarite non normalise est egal :"<<indice<<"\nL'indice nromalise est egal:"<<indicenormalise;
     m_sommet[k]->set_Ct(indice);
     m_sommet[k]->set_Ctn(indicenormalise);
    indice=0;
    indicenormalise=0;
    }
}
