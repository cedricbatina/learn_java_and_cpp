// les modèles ou patrons en c++
// modèle de fonction

#include <iostream>

using namespace std;

class uneclasse
{
private:
 /* data */
 int compteur;

public:
 uneclasse(/* args */ int valeur = 0) : compteur(valeur){};
 uneclasse(const uneclasse &objet1) : compteur(objet1.compteur){};
 uneclasse &operator=(const uneclasse &objet1)
 {
  compteur = objet1.compteur;
  return *this;
 }
 friend int operator==(const uneclasse &objet1, const uneclasse &objet2)
 {
  if (objet1.compteur == objet2.compteur)
   return 1;
  return 0;
 }
 uneclasse operator+(const uneclasse &original) const
 {
  int nouveau = compteur + original.compteur;

  uneclasse nouvelle(nouveau);
  return nouvelle;
 }
 friend ostream &operator<<(ostream &stream, const uneclasse &original)
 {
  return stream << original.compteur;
 }
};
template <class T>
T somme(const T &obj1, const T &obj2)
{
 if (obj1 == obj2)
  return obj1;
 return obj1 + obj2;
}
int main(int argc, char const *argv[])
{
 uneclasse mca(1);
 uneclasse mcb(2);

 cout << somme<uneclasse>(mca, mcb) << endl;
 cout << somme<uneclasse>(mca, mca) << endl;
 cout << somme<uneclasse>(mcb, mcb) << endl;

 return 0;
}
