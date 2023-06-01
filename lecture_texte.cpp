/*#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Lecture_texte
{
private:
 string nom_fichier;

public:
 Lecture_texte(const string le_fichier)
 {
  void lecture();
 }

 Lecture_texte::Lecture_texte(const string le_fichier) : nom_fichier(le_fichier){};

 void Lecture_texte::lecture()
 {
  ifstream ifichier(nom_fichier.c_str());
  if (!ifichier)
  {
   cerr << " Impossible d'ouvrir le fichier " << nom_fichier << endl;
   return;

   string une_ligne;
   int numero_de_ligne = 1;
   while (ifichier.getline(une_ligne, 1024))
   {
    cout << numero_de_ligne << ":  " << une_ligne << endl;
    numero_de_ligne++;
   }
  }
  int main(int argc, char const *argv[])
  {
Lecture_texte les_personnes("Personnes.txt");
les_personnes.lecture();
// char un_char;
// ifichier.get(un_char);
// cout << "Un caractère: " << un_char << endl;
return 0;
}
}
* /
   /* code */
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Lecture_texte
{
private:
 string nom_fichier;

public:
 Lecture_texte(const string le_fichier) : nom_fichier(le_fichier) {}

 void lecture()
 {
  ifstream ifichier(nom_fichier.c_str());
  if (!ifichier)
  {
   cerr << "Impossible d'ouvrir le fichier " << nom_fichier << endl;
   return;
  }
  char une_ligne[1024];
  int numero_de_ligne = 1;
  while (getline(ifichier, une_ligne))
  {
   cout << numero_de_ligne << ":  " << une_ligne << endl;
   numero_de_ligne++;
  }
 }
};

int main(int argc, char const *argv[])
{
 Lecture_texte les_personnes("Personnes.txt");
 les_personnes.lecture();
 return 0;
}
