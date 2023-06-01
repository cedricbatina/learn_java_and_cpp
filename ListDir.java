import java.io.*;
import java.util.Date;
import java.util.List;

class MonFileFilter implements FilenameFilter {
 public boolean accept(File dir, String name) {
  String tempname = name.toLowerCase();
  return (tempname.endsWith("doc") || tempname.endsWith("txt"));
 }
}

public class ListDir {
 private String repertoire;

 public static void main(String[] args) {
  if (args.length != 0) {
   ListDir dr2 = new ListDir(args[0]);
  } else {
   ListDir dr2 = new ListDir("E:\\Mes Documents");

  }
 }

 public ListDir(String leRepertoire) {
  repertoire = leRepertoire;
  if (leRepertoire.charAt(leRepertoire.length() - 1) != File.separatorChar) {
   repertoire += File.separatorChar;

  }
  File monRep = new File(repertoire);

  if (monRep.exists()) {
   String lesFichiers[] = monRep.list(new MonFileFilter());
   int nombre = lesFichiers.length();
   System.out.println("Nombre de fichiers: " + lesFichiers.length);

   for (int i = 0; i < nombre; i++) {
    File leFichier = new File(repertoire + lesFichiers[i]);
    Date dernModif = new Date(leFichier.lastModified());
    System.out.println(lesFichiers[i] + " " + dernModif);
   }
  } else {
   System.out.println("Le répertoire " + repertoire + " n'existe pas!");
  }
 }
}
