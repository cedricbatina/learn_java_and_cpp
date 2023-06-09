public class Clown1 implements Cloneable {
 private String nom;
 private String prenom;
 private int annee;

 public Clown1(String lenom, String leprenom, String lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = Integer.parseInt(lannee);
 }

 public void setAnnee(int lannee) {
  annee = lannee;
 }

 public void unTest() {
  System.out.println("Nom et prenom: " + nom + " " + prenom);
  System.out.println(" : " + annee);
 }

 public Object clone() {
  Clown1 co = null;

  try {
   co = (Clown1) super.clone();
   co.annee = -1;
  } catch (CloneNotSupportedException e) {

  }
  return co;
 }

 public static void main(String[] args) {
  Clown1 nom1 = new Clown1("Maradonna", "Diego", "1960");
  Clown1 nom2;
  Clown1 nom3;

  nom2 = nom1;

  nom3 = (Clown1) nom1.clone();

  if (!nom3.equals(nom1)) {
   System.out.println("Object nom1 et nom2 sont différents");
  }
  nom2.setAnnee(1960);
  nom1.unTest();
  nom2.unTest();
  nom3.unTest();

  if (nom2.equals((nom1))) {
   System.out.println("Object nom1 et nom2 sont égaux");
  }

 }
}
