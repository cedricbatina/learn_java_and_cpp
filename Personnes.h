#include <string>

class Personnes
{
private:
 /* data */
 std::string nom;
 std::string prenom;
 int annee;

public:
 Personnes(std::string leNom, std::string lePrenom, std::string lAnnee);
 void un_test();
};
