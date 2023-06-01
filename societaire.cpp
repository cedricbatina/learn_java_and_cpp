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
 Personne(const string lenom, const string lepreom, int lannee);
 ~Personne();
 void un_test();
};

class societaire : public Personne
{
private:
 /* data */
 int cotisation;

public:
 societaire(/* args */ const string lenom, const string leprenom, int lannee, int lacotis);

 ~societaire();
 void un_test();
};
Personne::Personne(const string lenom, const string leprenom, int lannee) : nom(lenom), prenom(leprenom), annee(lannee)
{
 cout << "Constructeur de Personne" << endl;
}
Personne::~Personne()
{
 cout << "Destructeur de Personne" << endl;
}

void Personne::un_test()
{
 cout << "Nom et prénom: " << nom << " " << prenom << endl;
}

societaire::societaire(/* args */ const string lenom, const string leprenom, int lannee, int lacotis) : Personne(lenom, leprenom, lannee)
{
 cotisation = lacotis;
 cout << "Constructeur de Sociétaire" << endl;
}
societaire::~societaire()
{
 cout << "Destructeur de Sociétaire" << endl;
}
void societaire::un_test()
{
 Personne::un_test();
 cout << "Cotisation: " << cotisation << endl;
}

int main(int argc, char const *argv[])
{
 /* code */
 societaire un_soc("Sékou", "Touré", 1986, 1200);
 un_soc.un_test();
 return 0;
}
