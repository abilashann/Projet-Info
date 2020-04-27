#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "graphe.h"



int main()
{
    Graphe dessin("graphe_etoile1_topo.txt");
    dessin.afficher();

    return 0;
}
