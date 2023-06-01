#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
 /* code */
 if (argc != 2)
 {
  cerr << "Nombre d'arguments invalides" << endl;
  cerr << "Strings fichier" << endl;
  return -1;
 }
 ifstream infile(argv[1], ios::in | ios::binary);
 if (!infile)
 {
  cout << "Fichier d' entrée n 'existe pas";
  return -1;
 }
 const int bloc = 512; // dim bloc lu
 int avant_bloc = 0;   // dim * n lu
 int ncinq_char = 0;   // nombre de premiers chars lus
 char cinq_char[6];    // cinq premiers chars

 cinq_char[5] = 0;

 char tampon[bloc];
 int octets_lus;
 for (;;)
 {
  infile.read(tampon, bloc);
  octets_lus = infile.gcount();
  for (int i = 0; i < octets_lus; i++)
  {
   if ((tampon[i] >= ' ') && (tampon[i] < 127))
   {
    if (ncinq_char < 5)
    {
     cinq_char[ncinq_char] = tampon[i];
     ncinq_char++;
    }
    else
    {
     if (ncinq_char == 5)
     {
      cout << (avant_bloc + 1 + 5) << ": " << cinq_char << tampon[i];
      ncinq_char++;
     }
     else
     {
      cout << endl;
     }
     ncinq_char = 0;
    }
   }
   if (octets_lus < bloc)
    break;             // dernier bloc lu
   avant_bloc += bloc; // avance compteur
  }
  infile.close();
 }

 return 0;
}
