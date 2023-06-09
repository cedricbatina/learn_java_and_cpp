import java.io.*;
//import java.io.Serializable;*.;

public class PersonneSerial implements Serializable {
 private String nom;
 private String prenom;
 private int annee;

 private static final long serialVersionUID = 6526472292623776149L;

 public PersonneSerial(String lenom, String leprenom, String lannee) {
  nom = lenom;
  prenom = leprenom;
  annee = Integer.parseInt(lannee);
 }

 public void unTest() {
  System.out.print("Nom et prenom: " + nom + " " + prenom);
  System.out.println(" : " + annee);
 }

 public static void main(String[] args) {
  PersonneSerial nom = new PersonneSerial("Nvuluzi", "Kimbangu", "1921");
  nom.unTest();

  try {
   ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("kimbangu.dat"));
   out.writeObject(nom);
   out.close();
   ObjectInputStream in = new ObjectInputStream(new FileInputStream("kimbangu.dat"));
   PersonneSerial nomlu = (PersonneSerial) in.readObject();
   in.close();

  } catch (Exception e) {
   System.out.println("L'objet de la classe Personne ne peut être sauvegardé");
   ;
   System.out.println(" ou récupéré du fichier haddock.dat ");
   return;
  }
 }
}
