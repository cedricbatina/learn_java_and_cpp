import java.io.BufferedReader;
import java.io.FileReader;

public class LectureTexte {
 private String mon_fichier;

 public LectureTexte(String le_fichier) {
  mon_fichier = le_fichier;
 }

 public void lecture() throws Exception {
  String une_ligne;
  BufferedReader in = new BufferedReader(new FileReader(mon_fichier));
  int numero_de_ligne = 1;
  for (;;) {
   une_ligne = in.readLine();
   if (une_ligne == null)
    break;
   System.out.println(numero_de_ligne + " " + une_ligne);
   numero_de_ligne++;
  }
 }

 public static void main(String[] args) throws Exception {
  LectureTexte les_personnes = new LectureTexte("Personnes.txt");
  les_personnes.lecture();
 }
}
