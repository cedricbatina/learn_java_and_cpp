import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Ecole {
 public static void main(String[] args) {
  try {
   int age = 0;

   BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
   System.out.print("Entre ton âge: ");
   age = Integer.parseInt(stdin.readLine());
   System.out.println(age);
   if ((age < 17) && (age >= 6)) {
    System.out.print("Tu dois aller à l'école, petit!");

   } else {
    System.out.print("Tu peux rester à la maison");
   }
  } catch (IOException ioe) {
  }

 }

}
