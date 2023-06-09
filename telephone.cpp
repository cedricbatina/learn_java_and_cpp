// liste de numéros de téléphone avec map
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

int main(int argc, char const *argv[])
{
 string sankara = "Thomas Sankara";
 string numBatina = "0748484902";

 map<string, string> list_tel;

 list_tel[sankara] = "0780845004";
 list_tel["Elijah Batina"] = numBatina;
 list_tel["Cédric Batina"] = numBatina;
 list_tel["Patrice Lumumba"] = "0243196360";
 list_tel["Nvuluzi Kimbangu"] = "01921195980";
 list_tel["Nuvluzi Kimbangu"] = "18871921159";

 map<string, string>::iterator it;

 for (it = list_tel.begin(); it != list_tel.end(); it++)
 {
  cout << (*it).first << " : " << (*it).second << endl;
 }

 cout << endl;

 it = list_tel.find(sankara);
 if (it == list_tel.end())
 {
  cout << "Le numéro de " << sankara << "est Inconnu" << endl;
 }
 else
 {
  cout << "Le numéro de " << sankara << " est: " << (*it).second << endl;
 }

 int nombre = 0;
 string resultat = "Le numéro " + numBatina + " appartient à: \n";

 for (it = list_tel.begin(); it != list_tel.end(); it++)
 {
  if ((*it).second == numBatina)
  {
   resultat += (*it).first + "\n";
   nombre++;
  }
 }
 if (nombre == 0)
 {
  cout << "Il n' y a personne avec le numéro: " << numBatina << endl;
 }
 else
 {
  cout << resultat;
 }

 return 0;
}
