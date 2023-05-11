import java.io.*;

public class Cin {
 public static void main(String[] args) {
  try {
   String texte = "";
   int nombre = 0;

   BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));

   System.out.print("Entre un texte: ");
   texte = stdin.readLine();
   System.out.print("\nLe texte: " + texte);

   System.out.print("\nEntre un nombre: ");
   nombre = Integer.parseInt(stdin.readLine());
   System.out.println("\nLe nombre: " + nombre);

  } catch (IOException ioe) {
  }
 }

}
