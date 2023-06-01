#include <iostream>
#include <string>

using namespace std;

class SchtroumpfGeneric1
{
private:
 string nom;
 int compteur1;

protected:
 int compteur2;

public:
 SchtroumpfGeneric1(string lenom);
 string getNom();
 void parle(string texte);
 int getCompteurs();
 static void unStroumpParle(SchtroumpfGeneric1 *unStroump, string texte);
};

class SchtroumpfGrognon1 : public SchtroumpfGeneric1
{
public:
 SchtroumpfGrognon1(string lenom);
 void parle(string texte);
};

SchtroumpfGeneric1::SchtroumpfGeneric1(string lenom) : nom(lenom), compteur1(0), compteur2(0)
{
}

string SchtroumpfGeneric1::getNom()
{
 return nom;
}

void SchtroumpfGeneric1::parle(string texte)
{
 cout << getNom() << " dit " << texte << endl;
 compteur1++;
 compteur2++;
}

int SchtroumpfGeneric1::getCompteurs()
{
 return (100 * compteur1) + compteur2;
}

SchtroumpfGrognon1::SchtroumpfGrognon1(string lenom) : SchtroumpfGeneric1(lenom)
{
}

void SchtroumpfGrognon1::parle(string texte)
{
 cout << getNom() << " dit en grognant " << texte << endl;

 // compteur1; impossible car private
 compteur2++;
}

void SchtroumpfGeneric1::unStroumpParle(SchtroumpfGeneric1 *unStroump, string texte)
{
 unStroump->parle(texte);
}

int main(int argc, char const *argv[])
{
 SchtroumpfGrognon1 *un_bleu;
 un_bleu = new SchtroumpfGrognon1("Petit Grognon");
 un_bleu->parle("Bonjour");
 SchtroumpfGeneric1::unStroumpParle(un_bleu, "Salut");

 cout << "Les compteurs: " << un_bleu->getCompteurs() << endl;
 delete un_bleu;

 return 0;
}
