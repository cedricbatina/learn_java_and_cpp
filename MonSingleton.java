public class MonSingleton {
 private static MonSingleton monSingle;
 private static int compteur;
 private static int nbAppel;

 private MonSingleton() {
  compteur = 1;
  nbAppel = 0;
 }

 public static MonSingleton obtientInstance() {
  if (monSingle == null) {
   monSingle = new MonSingleton();
  }
  nbAppel++;
  return monSingle;
 }

 public void augmente() {
  compteur++;
 }

 public String toString() {
  return "Compteur =  " + compteur + " (" + nbAppel + ")";
 }

 public static void main(String[] args) {
  MonSingleton ms1 = MonSingleton.obtientInstance();
  ms1.augmente();
  MonSingleton ms2 = MonSingleton.obtientInstance();
  ms2.augmente();
  System.out.println(ms1);
  System.out.println(ms2);
 }
}
