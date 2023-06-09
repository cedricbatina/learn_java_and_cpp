// couper des morceaux de codes en java pour les rassembler plus tard

import java.io.*;

public class Coupe {
 private String mon_fichier;
 private int dimension;
 private String merreur;
 private String facr;
 static public String fin = "\r\n";

 public Coupe(String le_fichier, int la_dim) {
  mon_fichier = le_fichier;
  dimension = la_dim;

  int index_point = mon_fichier.indexOf(".");
  if (index_point > 8)
   index_point = 8;
  else {
   if (index_point < 0) {
    index_point = mon_fichier.length();
    if (index_point > 8)
     index_point = 8;
   }
  }
  if (index_point == 0)
   facr = "xxx";
  else
   facr = mon_fichier.substring(0, index_point);
 }

 public boolean coupe() {
  FileInputStream out = null;
  FileWriter outacr = null;
  byte[] tampon = new byte[512];
  int octets_lus = 512;
  int octets_trans = 0;
  int total = 0;
  int num_morceau = 1;
  String le_morceau = null;
  int cs1 = 0;
  int cs2 = 0;
  try {
   FileInputStream in = new FileInputStream(new File(mon_fichier));
   try {
    outacr = new FileWriter(new File(facr + ".acr"));
    outacr.write(mon_fichier + fin);
   } catch (IOException e) {
    merreur = "Fichier " + facr
      + " ne peut être écrit";
    return false;
   }
   while ((octets_lus = in.read(tampon)) > 0) {
    total += octets_lus;
    if (octets_lus == 0) {
     le_morceau = facr + "." + num_morceau;
     try {
      cs1 = num_morceau;
      cs2 = 0;
      out = new FileInputStream(new File(le_morceau));
      outacr.write(le_morceau + fin);
     } catch (IOException e) {
      merreur = "Fichier " + le_morceau + " ne peut être écrit";
      return false;
     }
    }
    for (int j = 0; j < octets_lus; j++) {
     cs1 = cs1 ^ (int) tampon[j++];
     if (j != octets_lus) {
      cs2 = cs2 ^ (int) tampon[j];
     }
    }
    try {
     out.write(tampon, 0, octets_lus);
     octets_trans += octets_lus;
     if (octets_trans == dimension) {
      out.close();
      outacr.write(((256 * cs1) + cs2) + fin);
      octets_trans = 0;
      num_morceau++;
     }
    } catch (FileNotFoundException e) {
     merreur = "Fichier " + le_morceau + " ne peut être écrit ";
     return false;
    }

   }
   if (octets_trans > 0) {
    outacr.write(((256 * cs1) + cs2) + fin);
    out.close();
   }
   outacr.write("EnD" + fin);
   outacr.write(total + fin);
   outacr.close();
   in.close();
  } catch (IOException e) {
   merreur = "Fichier " + mon_fichier + " n'existe pas " + e;
   return false;
  }
  return true;

 }

 public String erreur_message() {
  return merreur;
 }

 public static void main(String[] args) {
  int args_len = args.length;

  if ((args_len < 1) || (args_len > 2)) {
   System.err.println("Nombre de paramètres invalide");
   System.err.println("java Coupe fichier (pour disquettes)");
   System.err.println("java Coupe dim fichier (en fichiers de dim >=1024) ");
   System.err.println("java Coupe Kn fichier (en fichiers n Kilo octets)");
   System.err.println("java Coupe Mn fichier (en fichiers n Mega octets)");
   return;

  }
  int fi = 0;
  int adim = 1457664; // dimension d'une disquette
  if (args_len == 2)

  {
   fi = 1;
   char first_char = args[0].charAt(0);
   if ((first_char == 'k') || (first_char == 'M')) {
    adim = 1024 * Integer.parseInt(args[0].substring(1, args[0].length()));
    if (first_char == 'M')
     adim *= 1024;

   } else {
    adim = Integer.parseInt(args[0]);
    if ((adim % 512) != 0) {
     System.err.println("La dimension doit être un multiple de 512");
     return;
    }
   }
  }
  Coupe ma_coupe = new Coupe(args[fi], adim);
  if (ma_coupe.coupe()) {
   System.out.println("Coupe terminée correctement");
  } else {
   System.err.println("Coupe erreur: " + ma_coupe.erreur_message());
  }
 }
}
