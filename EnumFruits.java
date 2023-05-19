public class EnumFruits {
 public enum Fruits {
  poire, pomme, fraise, safou, avocat
 };

 public static void main(String[] args) {
  for (Fruits unFruit : Fruits.values()) {
   System.out.println(unFruit);
  }
  System.out.println();
  System.out.println(Fruits.pomme);
 }

}
