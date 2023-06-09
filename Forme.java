public abstract class Forme {
 protected int origineX;
 protected int originY;

 public Forme(int posx, int posy) {
  origineX = posx;
  originY = posy;
 }

 public abstract void dessine();
}

public class Rectangle extends Forme {
 protected int longueur;
 protected int hauteur;

 public Rectangle(int posx, int posy, int lalongueur, int lahauteur) {
  super(posx, posy);

  longueur = lalongueur;
  hauteur = lahauteur;
 }

 public void dessine() {
  System.out.print("Notre rectangle a la position: " + origineX + ", " + originY);
  System.out.print("et de dimension: " + longueur + ", " + hauteur + " est dessiné!.");
 }

}

public class Cercle extends Forme {
 protected int rayon;

 public Cercle(int posx, int posy, int lerayon) {
  super(posx, posy);
  rayon = lerayon;
 }

 public void dessine() {
  System.out.print("Notre cercle à la position " + origineX + ", " + originY);
  System.out.println(" et de rayon " + rayon + " est dessiné!");
 }

 public class Dessin {
  Forme[] lesObjets;

  public Dessin() {
   lesObjets = new Forme[4];
   lesObjets[0] = new Rectangle(0, 0, 1, 1);
   lesObjets[1] = new Rectangle(5, 1, 1, 2);
   lesObjets[2] = new Cercle(1, 5, 1);
   lesObjets[3] = new Cercle(2, 2, 4);

  }

  public void dessine() {
   for (int i = 0; i < lesObjets.length; i++) {
    lesObjets[i].dessine();
   }
  }

 }

 static public void main(String[] args) {
  Dessin unDessin = new Dessin();
  unDessin.dessine();
 }
}
