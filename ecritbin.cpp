#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int dim = 100;

int main(int argc, char const *argv[])
{
 /* code */
 ofstream outfile("au_hasard.bin", ios::out | ios::binary);
 if (!outfile)
 {
  cerr << " Fichier de sortie ne peut être créee";
  return false;
 }
 char tampon[dim]; // nos valeurs aléatoires
 srand(time(NULL));

 for (int i = 0; i < dim; i++)
 {
  tampon[i] = (char)((rand() * 256) / RAND_MAX); // entre 0 et 255
  // tampon[i] = (char)rand(256);                   // entre 0 et 255 certains compilateurs
 }
 outfile.write(tampon, dim) /*<< endl*/;
 outfile.close();
 return 0;
}
