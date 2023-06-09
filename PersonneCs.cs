using System

public class PersonneCs
{
 private string nom;
 private string prenom;
 private int annee;

 public PersonneCs (string lenom, string leprenom, int lannee){
  nom = lenom;
  prenom = leprenom
  annee = lannee
 }
public void Un_test() {
 Console.Out.WriteLine("Nom et prénom: " + nom + " " + prenom);
 Console.Out.WriteLine("Année: " + annee);
}
public static void Main(string[] args)
{
 PersonneCs nom1 = new PersonneCs ("Nvuluzi","Kimbangu", "1921");
 PersonneCs nom2 = new PersonneCs ("Batina", "Cedric", 1980);
 nom1.Un_test();
 nom2.Un_test();


}

}