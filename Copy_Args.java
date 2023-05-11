public class Copy_Args {
 /**
  * @param args
  */
 public static void main(String[] args) {
  if (args.length != 2) {
   System.err.println("Nombre invalide de paramètres ");
   return;
  }
  System.out.println("args[0]: " + args[0]);
  System.out.println("args[1]: " + args[1]);
  /* System.out.print("\n"); */
 }
}
