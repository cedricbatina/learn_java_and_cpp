class SchtroumpfGeneric1 {
 private String nom;
 private int compteur1 = 0;

 protected int compteur2;

 public SchtroumpfGeneric1(String lenom) {
  nom = lenom;
 }

 public String getNom() {
  return nom;
 }

 public void parle(String texte) {
  System.out.println(getNom() + " dit " + texte);
  compteur1++;
  compteur2++;
 }

 public int getCompteurs() {
  return (100 * compteur1) + compteur2;
 }

}

/**
 * InnerSchtroumpfGeneric1
 */
public class SchtroumpfGrognon1 extends SchtroumpfGeneric1 {
 public SchtroumpfGrognon1(String lenom) {
  super(lenom);
 }

 public void parle(String texte) {
  System.out.println(getNom() + " dit en grognant " + texte);
  // compteur1++; //impossible car private
  compteur2++;
 }

 public static void unStroumpParle(SchtroumpfGeneric1 unStroump, String texte) {
  unStroump.parle(texte);
 }

 public static void main(String[] args) {
  SchtroumpfGeneric1 unBleu = new SchtroumpfGrognon1("Petit Grognon");
  unBleu.parle("Bonjour");
  unStroumpParle(unBleu, "Salut");
  System.out.println("Compteurs: " + unBleu.getCompteurs());
 }
}