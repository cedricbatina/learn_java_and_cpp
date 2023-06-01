
//lecture d'un fichier binaire
import java.io.*;

public class ChargeOthello {
 private String fichier;

 private static final int dim = 10;
 private int[][] othello = new int[dim][dim];

 public ChargeOthello(String fichier_de_sauvetage) {
  fichier = fichier_de_sauvetage;
 }

 public boolean charge() {
  File inFile = new File(fichier);
  try {
   FileInputStream in = new FileInputStream(inFile);
   for (int j = 1; j < dim - 1; j++) {
    for (int i = 1; i < dim - 1; i++) {
     othello[i][j] = in.read();
    }
   }
   in.close();
  } catch (Exception e) {

   return false;
  }
  return true;
 }

 public void test() {
  int i = 0; // position horizontale
  int j = 0; // position verticale

  for (j = 0; j < dim; j++) {
   for (i = 0; i < dim; i++) {
    if (othello[i][j] > 0)
     System.out.print(" ");

   }
   System.out.println();
  }

 }

 public static void main(String[] args) {
  ChargeOthello mon_sauvetage = new ChargeOthello("othello.bin");

  if (mon_sauvetage.charge()) {
   System.out.println("Chargement du fichier de sauvegarde réussi!");
  } else {
   System.out.println("Erreur de Chargement du fichier de sauvegarde réussi!");

  }
 }
}
