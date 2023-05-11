// int_long.cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 unsigned long valeur = 2147483648;
 valeur++;

 cout << "Valeur: " << valeur << endl;
 cout << "Valeur: " << (unsigned)valeur << endl;
 cout << "Valeur: " << static_cast<unsigned>(valeur) << endl;

 int valeur1 = 1;
 cout << "Valeur: " << valeur1 << endl;
 {
  int valeur2 = 2;
  cout << "Valeur: " << valeur2 << endl;
 }
 int valeur3 = 3;
 cout << "Valeur: " << valeur3 << endl;

 int nombre1 = 1;
 int *pnombre2;
 pnombre2 = &nombre1;
 *pnombre2 = 2;
 cout << nombre1 << *pnombre2 << endl;

 int *mon_int;
 mon_int = (int *)malloc(sizeof(int));
 *mon_int = 10;
 cout << "*mon_int " << endl;
 free(mon_int);
 cout << "Sizeof int: " << sizeof(int) << endl;
 cout << "Sizeof char: " << sizeof(char) << endl;
 cout << "Sizeof short: " << sizeof(short) << endl;
 cout << "Sizeof double: " << sizeof(double) << endl;
 cout << "Sizeof long: " << sizeof(long) << endl;
 const int dim_nom = 8;
 const int dim_ext = 3;
 char nom_fichier[dim_nom + 1];
 char ext_fichier[dim_ext + 1];

 return 0;
}
