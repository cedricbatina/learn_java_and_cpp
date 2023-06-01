#include <iostream>
#include <string>

using namespace std;

class SoldeUtilisateurException
{
private:
 /* data */
 int solde_du_compte;

public:
 SoldeUtilisateurException(int un_solde)
 {
  solde_du_compte = un_solde;
 }
 int getSolde()
 {
  return solde_du_compte;
 }
};
class SoldeMachineException
{
private:
 int solde_billets;

public:
 SoldeMachineException(int solde_machine)
 {
  solde_billets = solde_machine / 100;
 }
 int getSolde()
 {
  return solde_billets;
 }
};

class Bancomat2
{
private:
 string utilisateur;
 int soldem;    // solde de l'appareil
 int soldeutil; // solde de l'utilisateur
public:
 void set_solde_machine(int lasoldem)
 {
  soldem = lasoldem;
 }
 void set_utilisateur(const string lutilisateur)
 {
  utilisateur = lutilisateur;
 }
 void set_solde_utilisateur(int lasoldeutil)
 {
  soldeutil = lasoldeutil;
 }
 void retrait_possible(int nb_billets);
 void retrait(int nb_billets);
};
void Bancomat2::retrait_possible(int nb_billets)
{
 if ((soldeutil - (100 * nb_billets)) < 0)
  throw SoldeUtilisateurException(soldeutil);

 if ((soldem - (100 * nb_billets)) < 0)
  throw SoldeMachineException(soldem);
}
void Bancomat2::retrait(int nb_billets)
{
 try
 {
  retrait_possible(nb_billets);
  cout << "Retirez vos " << nb_billets << " billets ! merci ! " << endl;
 }
 catch (SoldeUtilisateurException sue)
 {
  cerr << "Vous n'avez plus que " << sue.getSolde() << " euros sur votre compte!";
 }
 catch (SoldeMachineException sme)
 {
  cerr << "Il n' y a plus que " << nb_billets << " dans la machine!";
 }
}

int main(int argc, char const *argv[])
{
 /* code */
 Bancomat2 labanque;

 labanque.set_solde_machine(1000);
 labanque.set_solde_utilisateur(500);
 labanque.set_utilisateur("Mahungu");

 labanque.retrait(4);
 labanque.retrait(6);
 labanque.set_solde_utilisateur(2000);
 labanque.retrait(11);

 // return 0;
}
