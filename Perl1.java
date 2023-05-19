
public class Perl1 {
 public void splice(StringBuffer str, int pos, int longueur) {
  int posfin = pos + longueur;
  int dimension = str.length();

  if ((pos < 0) || (longueur <= 0) || (pos >= dimension))
   return;
  if ((longueur + pos) > dimension)
   posfin = dimension;
  str.delete(pos, posfin);
 }

 public static void main(String[] args) {
  Perl1 myperl = new Perl1();
  StringBuffer str = new StringBuffer("0123456789");
  System.out.println(str);

  if (args.length > 0) {
   int pos = Integer.parseInt(args[0]);
   int larg = Integer.parseInt(args[1]);
   myperl.splice(str, pos, larg);
   System.out.println(str);
  } else {
   myperl.splice(str, 3, 2);
   System.out.println(str);
   myperl.splice(str, 3, 100);
   System.out.println(str);

  }

 }
}
