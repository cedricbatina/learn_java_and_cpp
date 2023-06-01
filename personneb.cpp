// la forme du constructeur par copie

#include <iostream>
#include <string>

using namespace std;

class PersonneB
{
private:
 string nom;
 string prenom;
 int annee;

public:
 PersonneB(const char *plenom, const char *pleprenom)
 {
  nom = plenom;
  prenom = pleprenom;
  annee = -1;
 }
 PersonneB(const PersonneB &une_autre_personne)
 {
  nom = une_autre_personne.nom;
  prenom = une_autre_personne.prenom;
  annee = -1;
 }
 void set_annee(int lannee)
 {
  annee = lannee;
 }
 void test()
 {
  cout << nom << " " << prenom << " : " << annee << endl;
 }
};
int main(int argc, char const *argv[])
{
 /* code */
 PersonneB personne1("Nvuluzi", "Kimbangu");
 personne1.set_annee(1921);
 personne1.test();

 PersonneB personne2(personne1);
 personne2.test();

 return 0;
}
