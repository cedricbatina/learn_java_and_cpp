package monpaquet;

public class Salaire {
 private int montant;
 private String monnaie;
 private double bonus;

 public Salaire(int leMontant, String laMonnaie) {
  montant = leMontant;
  monnaie = laMonnaie;
  bonus = 1.10; // 10% de bonus annuel
 }

 public int salaireAnnuel() {
  ConversionMonnaie conversion = new ConversionMonnaie(monnaie);
  double tauxDeChange = conversion.tauxConversion();
  return (int) (12 * tauxDeChange * montant * bonus);

 }

 public String getMonnaie() {
  return monnaie;
 }
}
