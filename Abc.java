public class Abc {
 public static void main(String[] args) {
  String abc = "";

  for (int i = 0; i < 3; i++) {
   abc += (char) ('a' + i);
  }
  int j = 3;
  while (j != 0) {
   abc += (char) ('d' - j--);

  }

  char lettre = 'a';
  do {
   abc += lettre;
   lettre++;
  } while (lettre != 'd');
  System.out.println(abc);

 }

}
