//le constructeur de copie par défaut en java n'existe pas. Il faut définier un constructeur spécifique

public class ObjetCopiable {
 private String objet;
 private int valeur;

 public ObjetCopiable(String nom, int prix) {
  objet = nom;
  valeur = prix;
  System.out.println(objet + " : " + valeur);
 }

 public ObjetCopiable(ObjetCopiable oc) {
  objet = oc.objet;
  valeur = (int) (oc.valeur * 0.9);
  System.out.println(objet + " : " + valeur);
 }

 public static void main(String[] args) {
  ObjetCopiable co1 = new ObjetCopiable("Statuette", 1000);
  ObjetCopiable co2 = new ObjetCopiable(co1);
 }

}
