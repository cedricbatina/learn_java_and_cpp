import java.io.*;

public class Colle {
 private String fichier_acr;
 private String merreur;

 public Colle(String le_fichier) {
  fichier_acr = le_fichier;
 }

 public boolean Colle() {
  String mon_fichier;
  String un_fichier;
  int dim_total = 0;
  byte[] tampon = new byte[512];
  int octets_lus = 0;
  int octets_trans = 0;
  int num_morceau = 0;
  int cs = 0;
  int cs1 = 0;
  int cs2 = 0;

  try {
   BufferedReader inacr = new BufferedReader(new FileReader(fichier_acr));
   try {
    mon_fichier = inacr.readLine(); // le fichier final
   } catch (IOException ioe) {
    merreur = " Erreur de lecture du fichier .acr";
    return false;
   }
   if (mon_fichier.length() > 50) {
    merreur = "Fichier trop long (>50 ) ou erreur de lecture du fichier .acr";
    return false;
   }
   try {
    FileOutputStream out = new FileOutputStream(new File(mon_fichier));
    try {
     for (;;) {
      un_fichier = inacr.readLine();
      if (un_fichier == null) {
       merreur = "Fichier .acr incorrect";
       return false;
      }
      if (un_fichier.equals("EnD")) {
       out.close();
       dim_total = Integer.parseInt(inacr.readLine());

       if (dim_total == octets_trans)
        return true;
       else {
        merreur = "Nombre invalide de caractères transférés";
        return false;
       }
      }
      cs = Integer.parseInt(inacr.readLine());
      num_morceau++;

      cs1 = num_morceau;
      cs2 = 0;

      FileInputStream in = new FileInputStream(un_fichier);
      try {
       for (;;) {
        octets_lus = in.read(tampon);
        if (octets_lus <= 0)
         break;
        for (int j = 0; j < octets_lus; j++) {
         cs1 = cs1 ^ (int) tampon[j++];
         if (j != octets_lus) {
          cs2 = cs2 ^ (int) tampon[j];
         }
        }
        out.write(tampon, 0, octets_lus);
        octets_trans += octets_lus;
       }
       in.close();
      } catch (IOException ioe) {
       merreur = "Erreur de lecture pour " + un_fichier;
       return false;
      }
      if (cs != ((256 * cs1) + cs2)) {
       merreur = "Acr invalide pour le fichier " + un_fichier;
       return false;
      }
     }
    } catch (IOException ioe) {
     merreur = "Fichier .acr invalide";
     return false;
    }
   } catch (FileNotFoundException e) {
    merreur = "Le fichier " + mon_fichier + " ne peut être écrit";
    return false;
   }

  } catch (Exception e) {
   merreur = "Le fichier " + fichier_acr + " n'existe pas!";
   return false;
  }
 }

 public String erreur_message() {
  return merreur;
 }

 public static void main(String[] args) {
  int args_len = args.length;

  if (args_len != 1) {
   System.err.println("Nombre de paramètres invalides");
   System.err.println("java Colle fichier_acr");
   return;
  }
  String le_fichier_acr = args[0];
  if (le_fichier_acr.lastIndexOf(".acr") != (le_fichier_acr.length() - 4)) {
   System.err.println("Ce n'est pas un fichier .acr");
   return;
  }
  Colle ma_colle = new Colle(le_fichier_acr);
  if (ma_colle.Colle()) {
   System.out.println("Colle erreur: " + ma_colle.erreur_message());
  } else {
   System.err.println("Colle erreur: " + ma_colle.erreur_message());
  }
 }
}
