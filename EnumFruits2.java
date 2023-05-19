public class EnumFruits2 {
 public enum Fruits {
  kiwi, safou, avocat;

  public String toString() {
   switch (this) {
    case kiwi:
     return "Kiwi ";
    case safou:
     return "Safou ";
    case avocat:
     return "Avocat ";
   }
   return "Fruit inconnu";
  }

 }

 public static void main(String[] args) {
  for (Fruits unFruit : Fruits.values()) {
   System.out.print(unFruit);
  }
  System.out.println(" --> Nous avons bien du safou en stock");
 }
}