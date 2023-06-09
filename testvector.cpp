#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
 vector<int> v_entier;    // list d'int
 vector<string> v_chaine; // liste de string

 const char *un_char = "0";
 string nombre = "nombreX";

 for (int i = 0; i < 5; i++)
 { // remplissage

  v_entier.insert(v_entier.end(), i);
  nombre.replace(6, 1, 1, '0' + i);
  v_chaine.insert(v_chaine.begin(), nombre);
 }
 for (int j = 0; j < v_entier.size(); j++)
 {
  cout << (string)v_chaine[j] << " ";
  cout << v_entier[j] << endl;
 }

 vector<int>::iterator it1;
 vector<string>::iterator it2;
 it2 = v_chaine.end() - 1;

 for (it1 = v_entier.begin(); it1 != v_entier.end(); it1++)
 {
  cout << *it2-- << " " << *it1 << endl;
 }
 vector<string>::iterator it_debut = v_chaine.begin();
 vector<string>::iterator it_fin = v_chaine.end();

 while (it_debut != it_fin)
 {
  if (*it_debut == "nombre3")
   v_chaine.erase(it_debut);
  it_debut++;
 }
 it_debut = v_chaine.begin();
 it_fin = v_chaine.end() - 1;
 while (it_fin >= it_debut)
 {
  cout << *it_fin-- << endl;
 }

 cout << "Dimension du vector v_entier: " << v_entier.size() << endl;
 cout << "Dimension du vector v_chaine: " << v_chaine.size() << endl;
 return 0;
}
