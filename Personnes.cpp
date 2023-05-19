#include "Personnes.h"

#include <iostream>
#include <sstream>

using namespace std;

/* code */
Personnes::Personnes(string leNom, string lePrenom, string lAnnee)
{
 nom = leNom;
 prenom = lePrenom;

 // flux pour la conversion d'un string
 istringstream iss(lAnnee);
 iss >> annee;
}
void Personnes::un_test()
{
 cout << "Nom et prénom: " << nom << " " << prenom << endl;
 cout << "Année de naissance: " << annee << endl;
}
/* code */
