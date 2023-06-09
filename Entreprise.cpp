#include <iostream>
#include <string>

using namespace std;

class Employe
{
protected:
 string nom;

public:
 Employe(string le_nom) : nom(le_nom){};
 virtual string get_nom()
 {
  return nom;
 }
};
class Directeur : public Employe
{
public:
 Directeur(const string le_nom) : Employe(le_nom){};

 void dirige()
 {
  cout << "Le directeur " << nom << " dirige!. " << endl;
 }
};
int main(int argc, char const *argv[])
{
 Employe *lentreprise[3];
 lentreprise[0] = new Employe("employe1");
 lentreprise[1] = new Employe("employe2");
 lentreprise[2] = new Directeur("directeur1");

 for (int i = 0; i < 3; i++)
 {
  cout << "Le nom: " << lentreprise[i]->get_nom() << endl;
 }

 for (int i = 0; i < 3; i++)
 {
  Directeur *direc = dynamic_cast<Directeur *>(lentreprise[i]);
  if (direc != NULL)
  {
   direc->dirige();
  }
 }
 for (int i = 0; i < 3; i++)
 {
  delete lentreprise[i];
 }
 return 0;
}
