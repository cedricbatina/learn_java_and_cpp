#include <iostream>
#include <string>

using namespace std;

class Personne
{
private:
 string nom;
 string prenom;
 int annee;

public:
 Personne(const string lenom, const string leprenom, int lannee);
 void un_test();
};

class societairec
{
private:
 /* data */
 Personne *pun_societaire;
 int cotisation;

public:
 societairec(/* args */ const string lenom, const string leprenom, int lannee, int lacotis);
 ~societairec();
 void un_test();
};
Personne::Personne(const string lenom, const string leprenom, int lannee) : nom(lenom), prenom(leprenom), annee(lannee)
{
}

void Personne::un_test()
{
 cout << "Nom et prénom: " << nom << " " << prenom << endl;
 cout << "Année de naissance: " << annee << endl;
}
societairec::societairec(/* args */ const string lenom, const string leprenom, int lannee, int lacotis)
{
 pun_societaire = new Personne(lenom, leprenom, lannee);
 cotisation = lacotis;
}

societairec::~societairec()
{
 delete pun_societaire;
}
void societairec::un_test()
{
 pun_societaire->un_test();
 cout << "Cotisation: " << cotisation << endl;
}
int main(int argc, char const *argv[])
{
 /* code */
 societairec un_soc("Batina", "Yohann", 2004, 1000);
 un_soc.un_test();
 return 0;
}
