//import java.util.*;

public class Cmd {
 public static void main(String[] args) {
  for (int i = 0; i < args.length; i++) {
   if (args[i].charAt(0) != '-') {
    System.err.println("Caractère - du paramètre manquant!");
    return;
   } else {
    if (args[i].length() != 2) {
     System.err.println("Paramètre invalide");
     return;
    }
    switch (args[i].charAt(1)) {
     case 'l':
      System.out.println("Le paramètre 'l' est présent");

      break;
     case 'g':
      System.out.println("Le paramètre 'g' est présent");
      break;
     case 's':
      System.out.println("Le paramètre 's' est présent");
      break;

     default:
      System.err.println("Paramètre invalide");
      break;
    }
   }
  }
 }
}
