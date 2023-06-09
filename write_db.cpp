#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

class Personne
{
private:
 string nom; // nom de la personne
 string prenom;
 int annee;

public:
 /*Personne::*/ Personne(string leNom, string lePrenom, int lAnnee) : nom(leNom), prenom(lePrenom), annee(lAnnee) {}

 // char *get_delim() const {
 string get_delim() const
 {
  ostringstream enregistrement;
  enregistrement << "\"" << nom << "\"; \"" << prenom << "\";" << annee << ends;
  return enregistrement.str();
 }
};
class WritePersonDB
{
private:
 ofstream outfile;

public:
 bool write_debut(const char *fichier)
 {
  outfile.open(fichier, ios::out);
  if (!outfile.is_open())
  {
   return false;
  }
  outfile << "\"Nom\";\"Prenom\"; \"Annee\"";
  return true;
 }
 void write_record(const Personne &personne)
 {
  outfile << endl;
  outfile << personne.get_delim();
 }
 void write_fin()
 {
  outfile.close();
 }
};
int main(int argc, char const *argv[])
{
 WritePersonDB wpersonne_db;

 Personne personnes[2] = {
     Personne("Nvuluzi", "Kimbangu", 1921),
     Personne("Batina", "Cedric", 1980)};

 if (!wpersonne_db.write_debut("personnes.txt"))
 {
  cout << "Ne peut pas écrire dans le fichier personnes.txt" << endl;
  return -1;
 }
 wpersonne_db.write_record(personnes[0]);
 wpersonne_db.write_record(personnes[1]);

 wpersonne_db.write_fin();

 cout << "Fichier personnes.txt généré" << endl;

 return 0;
}
