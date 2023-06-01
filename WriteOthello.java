
//2criture d'un fichier texte
import java.io.*;

public class WriteOthello {
 private String nomFichier;

 private static final int dim = 10;
 private int[][] othello = new int[dim][dim];

 public WriteOthello(String fichierDeSauvetage) {
  nomFichier = fichierDeSauvetage;
  for (int j = 1; j < dim - 1; j++) {
   for (int i = 1; i < dim - 1; i++) {
    othello[i][j] = 0;
   }
  }
  othello[3][4] = 0; // noir joue

  othello[4][4] = 2; // noir
  othello[5][4] = 2; // noir
  othello[4][5] = 2; // noir
  othello[5][5] = 2; // blanc
 }

 public boolean sauve() {
  try {
   PrintWriter out = new PrintWriter(new FileWriter(nomFichier));
   char pion;
   StringBuffer tampon = new StringBuffer("12345678");
   for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
     pion = 'V';// vide
     if (othello[i + j][j + 1] == 2)
      pion = 'N';// noir
     tampon.setCharAt(i, pion);
    }
    out.println(tampon);
   }
   out.close();
  } catch (Exception e) {
   return false;
  }
  return true;
 }

 public static void main(String[] args) {
  String fichierDeSauvetage = "othello.txt";
  WriteOthello mon_sauvetage = new WriteOthello("othello.txt");

  if (mon_sauvetage.sauve()) {
   System.out.println("Sauvegarde effectué dans " + fichierDeSauvetage);
  }
 }
}
