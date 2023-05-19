package monpaquet;

public class TestMonPaquet {
 public static void main(String[] args) {
  Personne unePersonne = new Personne("Batina", "Cédric", "1980");
  unePersonne.setSalaire(5000, "Euros");
  unePersonne.un_test();

  Salaire salaire = new Salaire(8000, "Euros");
  System.out.println("Salaire annuel: " + salaire.salaireAnnuel() + " " + salaire.getMonnaie());
 }

}
