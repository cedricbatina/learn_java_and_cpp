public class Perl2 {
 public String splice(String str, int pos, int longueur) {
  int posend = pos + longueur;
  int dimension = str.length();

  if ((pos < 0) || (longueur <= 0) || (pos >= dimension))
   return str;

  if ((longueur + pos) > dimension)
   return str.substring(pos, dimension);
  return str.substring(0, pos) + str.substring(posend, dimension);
 }

 public static void main(String[] args) {
  Perl2 myperl = new Perl2();
  String str = new String("0123456789");
  System.out.println(str);

  if (args.length > 0) {
   int pos = Integer.parseInt(args[0]);
   int larg = Integer.parseInt(args[1]);
   System.out.println(myperl.splice(str, pos, larg));
  } else {
   System.out.println(myperl.splice(str, 3, 2));
   System.out.println(myperl.splice(str, 0, 2));
   System.out.println(myperl.splice(str, 3, 100));
  }
 }
}
