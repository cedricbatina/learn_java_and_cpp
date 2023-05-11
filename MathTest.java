public class MathTest {
 public static void main(String[] args) {
  double a = 2.0;
  double b = 3.0;
  double c = a * b;

  System.out.println("Multiplication: " + c);

  c = Math.sin(a) * Math.cos(b) + Math.sin(b) * Math.cos(a); // sin(a +b)
  System.out.println("Sinus (a + b): " + c);
  c = Math.pow(a, b);

  System.out.println("a à la puissance b: " + c);
 }
}
