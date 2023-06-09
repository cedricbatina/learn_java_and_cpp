import java.io.*;
import java.util.*;

public class TestSet {
 public static void filtre(Collection uneCollect) {
  Integer objet;
  int nombre;

  Iterator it1 = uneCollect.iterator();
  while (it1.hasNext()) {
   objet = (Integer) it1.next();
   nombre = objet.intValue();

   if ((nombre % 2) == 1) {
    it1.remove();
   }
  }
  System.out.print("");
 }

 public static void main(String[] args) {
  Set maListe1 = new HashSet<>();

  for (int i = 0; i < 20; i++) {
   maListe1.add(new Integer((int) (20 * Math.random())));
  }
  viewList(maListe1);
  filtre(maListe1);
  viewList(maListe1);
 }
}
// many methods are deprecated in this file