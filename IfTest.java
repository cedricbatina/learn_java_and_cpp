import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class IfTest {
 public static void main(String[] args) {
  try {
   int nombre1 = 0;
   int nombre2 = 0;

   BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
   System.out.print("Ente un premier nombre: ");
   nombre1 = Integer.parseInt(stdin.readLine());
   System.out.println(nombre1);
   System.out.print("Entre un second nombre: ");
   nombre2 = Integer.parseInt(stdin.readLine());
   System.out.println(nombre2);
   if (nombre1 > nombre2) {
    System.out.print(nombre1 + " est plus grand que " + nombre2);
   } else {
    if (nombre1 < nombre2) {
     System.out.print(nombre1 + " est plus petit que " + nombre2);

    } else {
     System.out.print(nombre1 + " est égal à " + nombre2);
    }
   }

  } catch (IOException ioe) {

  }
 }

}
