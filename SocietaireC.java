class PersonneC {
 private String nom;
 private String prenom;
 private int annee;

 public PersonneC(String lenom, String leprenom, int lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = lannee;
 }

 public void un_test() {
  System.out.println(" Nom et prénom: " + nom + " " + prenom);
  System.out.println("Année de naissance: " + annee);
 }

}

public class SocietaireC {
 private PersonneC unSocietaire;
 private int cotisation;

 public SocietaireC(String lenom, String leprenom, int lannee, int lacotis) {
  unSocietaire = new PersonneC(lenom, leprenom, lannee);
  cotisation = lacotis;
 }

 public void un_test() {
  unSocietaire.un_test();
  System.out.println("Cotisation: " + cotisation);
 }

 public static void main(String[] args) {
  SocietaireC unSoc = new SocietaireC("Batina", "Cédric", 1980, 0);
  unSoc.un_test();
 }

}