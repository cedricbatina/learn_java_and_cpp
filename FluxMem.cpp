// introduction istringstream et ostringstream
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
// Lit une ligne de la console
{
 /* code */
 cout << "Entrer deux chiffres en HEXA (ex: 12 AO) : ";
 string input;
 getline(cin, input);

 // Décode l'entréé
 istringstream is(input);
 int c1;
 int c2;

 is.setf(ios::hex, ios::basefield); // on travaille en hexadécimal
 is >> c1 >> c2;
 cout << "test1: " << c1 << endl;
 cout << "test2: " << c2 << endl;

 int resultat = c1 * c2;

 // Affiche le résultat
 ostringstream os;
 os << "Le résultat est: " << resultat << endl;

 cout << os.str();

 // Empêche la fenêtre DOS de se fermer
 cout << "Entrer retour";
 getline(cin, input);
 return 0;
}
