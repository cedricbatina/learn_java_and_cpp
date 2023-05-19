package monpaquet;

public class Personne {
 private String nom;
 private String prenom;
 private int annee;
 private Salaire salaire;

 public Personne(String leNom, String lePrenom, String lannee) {
  nom = leNom;
  prenom = lePrenom;
  annee = Integer.parseInt(lannee);
  salaire = new Salaire(0, "Dollar");
 }

 public void setSalaire(int unSalaire, String uneMonnaie) {
  salaire = new Salaire(unSalaire, uneMonnaie);
 }

 public void un_test() {
  System.out.println("Nom et prenom: " + nom + " " + prenom);
  System.out.println("Année de naissance: " + annee);
  System.out.println("Salaire annuel: " + salaire.salaireAnnuel() + " " + salaire.getMonnaie());
 }

 public static void main(String[] args) {
  Personne unePersonne = new Personne("Batina", "Cédric", "1980");
  unePersonne.setSalaire(5000, " Euros");
  unePersonne.un_test();

  ConversionMonnaie uneConversion = new ConversionMonnaie(" Euros");
  System.out.println("Taux: " + uneConversion.tauxConversion());

 }
}