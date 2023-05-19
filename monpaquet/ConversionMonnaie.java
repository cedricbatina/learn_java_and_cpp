package monpaquet;

public class ConversionMonnaie {
 private String monnaie;

 public ConversionMonnaie(String laMonnaie) {
  monnaie = laMonnaie;
 }

 public double tauxConversion() {
  // Accès sur Internet ou une base de données pour obtenir le taux
  // à partir du nom de la monnaie. Sera 1 pour le dollar
  return 1.2; // valeur de test
 }
}
