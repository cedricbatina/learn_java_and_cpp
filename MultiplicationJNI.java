public class MultiplicationJNI {
 public static void main(String[] args) {
  OperationCPP maMult = new OperationCPP("Multiplication");
  System.out.println("Résultat: " + maMult.execute(12, 13));
 }
}
