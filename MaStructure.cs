public struct MaStructure
{
 public String Nom;
 public int Annee;

 public int Length {
  get{return ToString().Length;
  }
 }
 public override string ToString(){
  return Nom + " " + Annee;
 }
 //Surcharge de l'opérateur -
 public static System.String operator - (System.String str, MaStructure ms) {
  return str + ms.ToString().ToUpper();
 }
}
public class TestMaStructure {
 public static void Main(string[] args)
 {
  MaStructure code;
  code.Nom = "Nvuluzi Kimbangu";
  code.Annee = 1921

  System.Console.Out.WriteLine("Mon code: " + code + " de longueur " + code.Length );
  System.Console.Out.WriteLine("Mon code: " - code);
 }
}

{
 
}