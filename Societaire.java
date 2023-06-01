/// initialisation des constructeurs

class Personne {
 private String nom;
 private String prenom;
 private int annee;

 public Personne(String lenom, String leprenom, int lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = lannee;
  System.out.println("Constructeur de Personne");
 }

 public void un_test() {
  System.out.println("Nom et prénom: " + nom + " " + prenom);
  System.out.println("Année de naissance: " + annee);
 }
}

/**
 * Societaire
 */
public class Societaire extends Personne {
 private int cotisation;

 public Societaire(String lenom, String leprenom, int lannee, int lacotis) {
  super(lenom, leprenom, lannee);
  cotisation = lacotis;
  System.out.println("Constructeur de Societaire");
 }

 public void un_test() {
  super.un_test();
  System.out.println("Cotisation: " + cotisation);
 }

 public static void main(String[] args) {
  Societaire unSoc = new Societaire("Sankara", "Thomas", 1987, 1500);
  unSoc.un_test();
 }
}