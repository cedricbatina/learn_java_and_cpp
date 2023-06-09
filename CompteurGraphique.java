import java.util.Observable;
import java.util.Observer;

public class CompteurGraphique implements Observer {

 CompteurObservable compteur;
 int forme;

 public CompteurGraphique(CompteurObservable leCompteur, int uneForme) {
  forme = uneForme;
  compteur = leCompteur;
  compteur.addObserver(this);

 }

 public void update(Observable ob, Object arg) {
  System.out.print("Montre le compteur " + compteur.getValue());
  System.out.print(" dans la forme " + forme);
 }

 public static void main(String[] args) {
  CompteurObservable compteur = new CompteurObservable(50);

  CompteurGraphique dessin1 = new CompteurGraphique(compteur, 1);
  CompteurGraphique dessin2 = new CompteurGraphique(compteur, 2);

  compteur.augmente();

 }
}