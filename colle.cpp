#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class colle
{
private:
 /* data */
 string fichier_acr;
 string merreur;

public:
 colle(/* args */ const string le_fichier);
 bool colle();
 string erreur_message()
 {
  return merreur;
 }
}

;

colle::colle(/* args */ const string le_fichier)
{
 fichier_acr = le_fichier;
}
bool colle::colle()
{
 string mon_fichier;
 string un_fichier;

 // ifstream in;
 ifstream inacr;
 ofstream out;
 int dim_total = 0;
 char tampon[512];
 int octets_lus = 0;
 int num_morceau = 0;
 int cs = 0;
 int cs1 = 0;
 int cs2 = 0;

 inacr.open(fichier_acr.c_str(), ios::in);
 if (inacr.fail() != 0)
 {
  merreur = "Erreur de lecture du fichier .acr";
  return;
 }
 inacr >> mon_fichier; // le fichier final
 if (mon_fichier.length() > 50)
 {
  merreur = "Fichier trop long (>50) ou erreur de lecture du fichier .acr";
  return;
 }
 out.open(mon_fichier.c_str(), ios::out | ios::binary);
 if (out.fail() != 0)
 {
  merreur = "Le fichier " + string(mon_fichier) + " ne peut être écrit";
  return false;
 }
 for (;;)
 {
  inacr >> un_fichier;
  if (un_fichier.length() < 1)
  {
   merreur = "Fichier .acr incorrect";
   return false;
  }
  if (un_fichier.compare("EnD") == 0)
  {
   out.close();
   inacr >> dim_total;

   if (dim_total == octets_trans)
    return true;
   else
   {
    merreur = "Nombre invalide de caractères transférés";
    return false;
   }
  }
  inacr >> cs;
  num_morceau++;
  cs1 = num_morceau;
  cs2 = 0;
  cout << "TEST: [" << un_fichier.c_str() << "]" << endl;

  ifstream in;
  in.open(un_fichier.c_str(), ios::in | ios::binary);
  if (in.fail() != 0)
  {
   merreur = "fichier " + string(un_fichier) + " ne peut être ouvert";
   return false;
  }
  for (;;)
  {
   in.read(tampon, 512);
   octets_lus = in.gcount();
   if (octets_lus <= 0)
    break;
   for (int j = 0; j < octets_lus; j++)
   {
    cs1 = cs1 ^ (int)tampon[j++] if (j != octets_lus)
    {
     cs2 = cs2 ^ (int)tampon[j];
    }
   }
   out.write(tampon, octets_lus);
   octets_trans += octets_lus;
  }
  in.close();
  if (cs != ((256 * cs1) + cs2))
  {
   merrreur = "Acr invalide pour le fichier " + string(un_fichier);
   return false;
  }
 }
}
int main(int argc, char const *argv[])
{
 string le_fichier;

 if (argc != 2)
 {
  cerr << "nombre de paramètres invalides" << endl;
  cerr << "Colle fichier_acr" << endl;

  le_fichier_arc = "prgm.acr";
  // return -1
 }
 else
 {
  le_fichier_arc = argv[1];
 }
 if (le_fichier_arc.rfind(".acr") != (le_fichier_arc.length() - 4))
 {
  cerr << "Ce n'est pas un fichier .acr" << endl;
  return -1;
 }
 colle ma_colle(le_fichier_arc);
 if (ma_colle.colle())
 {
  cout << "Colle terminée correctement  " << endl;
 }
 else
 {
  cerr << "Colle erreur: " << ma_colle.erreur_message() << endl;
 }
 return 0;
}
