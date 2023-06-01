// Ecriture d'un fichier XML
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class WriteXML
{
private:
 /* data */
 ofstream outfile;
 string avecBalise(const string balise, const string valeur)
 {
  return "<" + balise + ">" + valeur + "</" + balise + ">";
 }

public:
 bool write_debut(const char *fichier)
 {
  outfile.open(fichier, ios::out);

  if (!outfile.is_open())
  {
   return false;
  }
  outfile << "<?xml version=\"1.0\?>" << endl;
  outfile << "<carnet>" << endl;
  return true;
 }
 void write_record(const char *nom, const char *prenom)
 {
  outfile << " <personne>" << endl;
  outfile << avecBalise("nom", nom) << endl;
  outfile << avecBalise("prenom", prenom) << endl;
  outfile << "   </personne>" << endl;
 }
 void write_fin()
 {
  outfile << "</carnet>" << endl;
  outfile.close();
 }
};
int main(int argc, char const *argv[])
{
 WriteXML mon_xml;
 if (!mon_xml.write_debut("personne.xml"))
 {
  cout << "Ne peut pas écrire dans le fichier personne.xml" << endl;
  return -1;
 }
 mon_xml.write_record("Nvuluzi", "Kimbangu");
 mon_xml.write_record("Batina", "Cédric");
 mon_xml.write_fin();

 cout << "Fichier personne.xml généré" << endl;

 return 0;
}
