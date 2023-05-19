public class Personne {
 private String nom;
 private String prenom;
 private int annee;

 Personne(String lenom, String leprenom, String lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = Integer.parseInt(lannee);
 }

 Personne(String lenom, String leprenom, int lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = lannee;
 }

 void un_test() {
  System.out.println("Nom et prénom: " + nom + " " + prenom);
  System.out.println("Année de naissance: " + annee);
 }

 public static void main(String[] args) {
  Personne nom1 = new Personne("Marley", "Bob", "1945");
  Personne nom2 = new Personne("X", "Malcolm", 1927);
  nom1.un_test();
  nom2.un_test();
 }
}
