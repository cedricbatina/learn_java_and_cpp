public class Euromillions {
 public static void main(String[] args) {
  int[] tirage = { 3, 7, 13, 23, 32, 1, 2 };
  for (int i = 0; i < tirage.length; i++) {
   System.out.print(tirage[i] + " ");

  }
  System.out.println();
  for (int numero : tirage) {
   System.out.print(numero + " ");
  }
  System.out.println();
 }

}
