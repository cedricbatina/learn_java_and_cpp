
/*import java.io.*;
import java.net.*;

public class LectureUrl {
 public static void main(String[] args) throws Exception {
  URL apache_local = new URL("http://localhost/mon_test.html");

  BufferedReader in = new BufferedReader(new InputStreamReader(apache_local.openStream()));

  String inputLine;
  while ((inputLine = in.readLine()) != null) {
   System.out.println(inputLine);
   in.close();
  }
 }
}
*/
import java.io.*;
import java.net.*;

public class LectureUrl {
 public static void main(String[] args) throws Exception {
  // Crée une instance de la classe URI en spécifiant l'URL à lire
  URI uri = new URI("http://localhost/mon_test.html");

  // Convertit l'URI en URL
  URL apache_local = uri.toURL();

  // Crée un BufferedReader pour lire le contenu de l'URL
  BufferedReader in = new BufferedReader(new InputStreamReader(apache_local.openStream()));

  String inputLine;
  // Lit chaque ligne du contenu de l'URL et l'affiche
  while ((inputLine = in.readLine()) != null) {
   System.out.println(inputLine);
  }

  // Ferme le BufferedReader après avoir terminé la lecture
  in.close();
 }
}
