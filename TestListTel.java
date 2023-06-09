// liste de numéros de téléphone avec HashMap

import java.util.*;

class TestListTel {
 private Map telListe = new HashMap<>();

 public void ajoute(String nom, String numTel) {
  if (telListe.put(nom, numTel) != null) {
   telListe.remove(nom);
   telListe.put(nom, numTel);

  }

 }

 public String getNumero(String nom) {
  String resultat = (String) telListe.get(nom);
  if (resultat == null)
   return "Inconnu";
  return resultat;
 }

 public String getNom(String numero) {
  String clef;
  String resultat = "";
  int nombre = 0;

  for (Iterator it = (telListe.keySet()).iterator(); it.hasNext();) {
   clef = (String) it.next();

   if ((String) telListe.get(clef) == numero) {
    nombre++;
    resultat += clef + "\n";
   }
  }
  if (nombre == 0)
   return "Aucune";
  return resultat;
 }

 public String toString() {
  String resultat = "Liste des numéros de téléphone: \n";
  String clef;
  int i;

  for (Iterator it = (telListe.keySet()).iterator(); it.hasNext();) {
   clef = (String) it.next();
   resultat += clef;

   for (i = clef.length(); i < 30; i++) {
    resultat += " ";
   }
   resultat += (String) telListe.get(clef) + "\n";

  }
  return resultat;
 }

 public static void main(String[] args) {
  String sankara = "Sankara Thomas";
  String numBatina = "0748484902";

  TestListTel ttl = new TestListTel();
  ttl.ajoute("Sékou Touré", "0601020304");
  ttl.ajoute(sankara, "0784858689");
  ttl.ajoute("Nvuluzi Kimbangu", "0192101959");
  ttl.ajoute("Elijah Batina", numBatina);
  ttl.ajoute("Patrice Lumumba", "0243196360");
  System.out.println(ttl);
  System.out.println("Le numéro de " + sankara + " est " + ttl.getNumero(sankara));
  System.out.println("Le numéro  " + numBatina + " appartient  à :\n" + ttl.getNom(numBatina));
 }

}