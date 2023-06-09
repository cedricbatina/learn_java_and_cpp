#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class coupe
{
private:
 /* data */
 string mon _fichier;
 string facr;
 int dimension;
 string merreur;

public:
 coupe(/* args */ const string le_fichier, const int la_dim);
 bool coupe();
 string erreur_message()
 {
  return merreur;
 }
};

coupe::coupe(/* args */)
{
}

coupe::coupe(cosnt le_fichier, const int la_dim)
{
 mon_fichier = le_fichier;
 dimension = la_dim;

 int index_point = mon_fichier.find(".");

 if (index_point > 8)
  index_point = 8;
 else
 {
  if (index_point < 0)
  {
   index_point = mon_fichier.length();
   if (index_point > 8)
    index_point = 8;
  }
 }
 if (index_point == 0)
  facr = "xxx";
 else
  facr = mon_fichier.substr(0, index_point);
}
bool coupe::coupe()
{
 ifstream in;
 ofstream out;
 ofstream outacr;
 string fileName;

 char tampon[512];
 int octets_lus = 512;
 int octets_trans = 0;
 int num_morceau = 1;
 int cs1 = 0;
 int cs2 = 0;

 in.open(mon_fichier.c_str(), ios::in | ios::binary);
 if (in.fail() != 0)
 {
  merreur = "Fichier" + mon_fichier + " ne peut être ouvert";
  return false;
 }
 ostringstream oss;
 oss << facr << ".acr";
 fileName = oss.str();

 outacr.open(fileName.c_str(), ios::out);
 if (outacr.fail() != 0)
 {
  merreur = "Fichier " + fileName + " ne peut être écrit";
  return false;
 }
 outacr << mon_fichier << endl;

 for (;;)
 {
  in.read(tampon, 512);
  if ((octets_lus = in.gcount()) <= 0)
   break;

  total += octets_lus;

  if (octets_trans == 0)
  {
   ostringstream strout;
   strout << facr << "." << num_morceau;
   fileName = strout.str();

   out.open(fileName.c_str(), ios ::out | ios::binary);
   if (out.fail() != 0)
   {
    merreur = "Fichier " + fileName + " ne peut être ouvert";
    return false;
   }
   cs1 = num_morceau;
   cs2 = 0;
   outacr << fileName << endl;
  }
  for (int j = 0; j < octets_lus; j++)
  {
   cs1 = cs1 ^ (int)tampon[j++];
   if (j != octets_lus)
   {
    cs2 = cs2 ^ (int)tampon[j]
   }
  }
  out.write(tampon, octets_lus);
  octets_trans += octets_lus;
  if (octets_trans == dimension)
  {
   out.close();
   outacr << ((256 * cs1) + cs2) << endl;
   octets_trans = 0;
   num_morceau++;
  }
 }
 if (octets_trans > 0)
 {
  outacr << ((256 * cs1) + cs2) << endl;
  out.close()
 }
 outacr << "EnD" << endl;
 outacr << total << endl;
 outacr.close();
 in.close();
 return true;
}
int main(int argc, char const *argv[])
{
 string file_name;
 int fi = 1;
 int cdim = 1457664;

 if ((argc < 2) || (argc > 3))
 {
  cerr << "Nombre invalide de paramètres" << endl;
  cerr << "coupe fichier  (pour disquettes)" << endl;
  cerr << "coupe dim fichier (en fichiers de dim >= 1024 octets) " << endl;
  cerr << "coupe Kn fichier   (en fichiers de n Kilo-octets)" << endl;
  cerr << "coupe Mn fichier      (en fichiers de n mégaoctets)" << endl;

  fil_name = "prgm.exe";
  cdim = 102400;
  // return -1;
 }
 else
 {
  if (argc == 3)
  {
   fi = 2;
   char *pdimension;
   pdimension = &argv[1][0];
   if ((argv[1][0] == 'K') || (argv[1][0] == 'M'))
   {
    pdimension++;
    istringstream(pdimension) >> cdim;
    *cdim *= 1024;
    if (argv[1][0] == 'M')
    {
     cdim *= 1024;
    }
   }
   else
   {
    istringstream(pdimension) >> cdim;
   }
  }
  if (cdim < 1024)
  {
   cerr << "La dimension des fichiers doit être >=1024" << endl;
   return -1
  }
  file_name = (char *)argv[fi];
 }
 coupe ma_coupe(file_name, cdim);
 if (ma_coupe.coupe() == false)
 {
  cerr << "Erreur: " << ma_coupe.erreur_message() << endl;
  return -1;
 }
 cout << "Coupe terminéé correctement" << endl;
 return 0;
}

{
}
