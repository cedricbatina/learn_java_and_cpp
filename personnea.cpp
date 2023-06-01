// le constructeur  de copie par défaut
#include <iostream>
#include <string>

using namespace std;

class PersonneA
{
private:
 /* data */
 string nom;
 string prenom;
 int annee_mort;

public:
 PersonneA(/* args */ const char *plenom, const char *pleprenom)
 {
  nom = plenom;
  prenom = pleprenom;
  annee_mort = -1;
 }
 void set_annee(int lannee)
 {
  annee_mort = lannee;
 }
 void test()
 {
  cout << nom << " " << prenom << " : " << annee_mort << endl;
 }
};
int main(int argc, char const *argv[])
{
 /* code */
 PersonneA personne1("Kimpa", "Vita");
 personne1.set_annee(1702);
 personne1.test();

 PersonneA personne2(personne1);

 personne2.test();
 return 0;
}
