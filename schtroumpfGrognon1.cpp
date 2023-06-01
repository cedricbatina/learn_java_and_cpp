#include <iostream>
#include <string>

using namespace std;

class schtroumpfgeneric1
{
private:
 string nom;
 int compteur1;

protected:
 int compteur2;

public:
 schtroumpfgeneric1(string lenom);
 string getNom();
 void parle(string texte);
 int getCompteurs();
 static void unStroumpParle(const schtroumpfgeneric1 *unStroump, string texte);
};
class schtroumpfgeneric1 : public schtroumpfgeneric1
{
public:
 schtroumpfGrognon1(string lenom);
 void parle(string texte);
};
schtroumpfgeneric1::schtroumpfGrognon1(string lenom) : nom(lenom), compteur1(0), compteur2(0)
{
}
string schtroumpfgeneric1::getNom()
{
 return nom;
}
void schtroumpfgeneric1::parle(string texte)
{
 cout << getNom() << " dit " << texte << endl;
 compteur1++;
 compteur2++
}

int schtroumpfgeneric1::getCompteurs()
{
 return (100 * compteur1) + compteur2;
}
schtroumpfGrognon1::schtroumpfGrognon1(string lenom) : schtroumpfgeneric1(lenom)
{
}
void schtroumpfGrognon1::parle(string texte)
{
 cout << getNom() << " dit en grognant " << texte << endl;

 // compteur1; impossible car private
 compteur2++
}
void unStroumpfParle(schtroumpfgeneric1 *unStroumpf, const string texte)
{
 unStroumpf->parle(texte);
}

int main(int argc, char const *argv[])
{
 /* code */
 schtroumpfGrognon1 *un_bleu;
 un_bleu = new schtroumpfGrognon1("Petit Grognon");
 un_bleu->parle("Bonjour");
 unStroumpfParle(&un_bleu, "Salut");

 cout << "Les compteurs: " << un_bleu->getCompteurs() << endl;
 delete un_bleu;

 return 0;
}
