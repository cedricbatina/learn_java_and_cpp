public class Personnes {
 private String nom;
 private String prenom;
 private int annee;

 Personnes(String lenom, String leprenom, String lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = Integer.parseInt(lannee);
 }

 Personnes(String lenom, String leprenom, int lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = lannee;
 }

 void un_test() {
  System.out.println("Nom et prénom: " + nom + " " + prenom);
  System.out.println("Année de naissance: " + annee);
 }

 public static void main(String[] args) {
  Personnes nom1 = new Personnes("Marley", "Bob", "1945");
  Personnes nom2 = new Personnes("X", "Malcolm", 1927);
  Personnes nom3 = new Personnes("Nvuluzi", "Kimbangu", 1887);
  nom1.un_test();
  nom2.un_test();
  nom3.un_test();
 }
}
