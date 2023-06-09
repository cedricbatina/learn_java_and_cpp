#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class MonSingleton
{
private:
 /* data */
 static MonSingleton monSingleton;
 static int nbAppel;
 int compteur;

 MonSingleton(int le_compteur) : compteur(le_compteur)
 {
  nbAppel = 0;
 }
 MonSingleton(MonSingleton &);
 void operator=(MonSingleton &);

public:
 static MonSingleton &obtientInstance()
 {
  nbAppel++;
  return monSingleton;
 }
 void augmente()
 {
  compteur++;
 }
 string toString()
 {
  ostringstream sortie;
  sortie << "Compteur = ";
  sortie << compteur << "(" << nbAppel << ")" << ends;

  return sortie.str();
 }
};

MonSingleton MonSingleton::monSingleton(1);
int MonSingleton::nbAppel(1);

int main(int argc, char const *argv[])
{
 MonSingleton &ms1 = MonSingleton::obtientInstance();
 ms1.augmente();

 MonSingleton &ms2 = MonSingleton::obtientInstance();
 ms2.augmente();

 cout << ms1.toString() << endl;
 return 0;
}
