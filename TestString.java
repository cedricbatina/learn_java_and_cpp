public class TestString {
 public static void main(String[] args) {
  String texte1 = "  abcd1234abcd5678abcd  ";
  System.out.println("[" + texte1 + "]");
  texte1 = texte1.trim();
  System.out.println("[" + texte1 + "]");

  int index = texte1.indexOf("bcd", texte1.indexOf("abc") + 3);
  String texte2 = texte1.substring(0, index) + texte1.substring(index + 3).toUpperCase();
  System.out.println("[" + texte2 + " ]");
 }
}
