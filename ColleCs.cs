using System;
using System.IO;

public class ColleCs
{
 private string fichierAcr;
 private string merreur;

 public ColleCs(string leFichier) {
  fichierAcr = leFichier
 }
 public bool Colle() {
  string monFichier ;
   string unFichier;
   int dimTotal = 0; // dimension du fichier construit
   byte[] tampon = new byte[512];
   int octetLus = 0;
   int octetsTrans = 0; // nombre d'octets transférés
   int numMorceau + 0;
   int cs = 0;
   int cs1 = 0;
   int cs2 = 0;

try
{
 StreamReader sRdAcr = new StreamReader(fichierAcr)
 try
 {
  monFichier = sRdAcr.ReadLine();
 }
 catch (IOException)
 {
  merreur =  "Erreur de lecture du fichier .acr";
  return false;

 }
if(monFichier.Length > 50) {
 merreur = "Fichier trop long (>50) ou erreur de lecture du fichier .acr";
 return false;
}
try
{
 FileStream fsOut = new FileStream(monFichier, FileMode.Create, FileAccess.Write);
 try {
  for (;;) {
   unFichier = sRAcr.ReadLine();
   if (unFichier == null) {
    merreur = "Fichier .acr incorrect";
    return false;
   }
  }
  if (unFichier.Equals("EnD")) {
   fsOut.Close()
   dimTotal = Int32.Parse(sRAcr.ReadLine());

   if (dimTotal == octetsTrans) return true;
   else {
    merreur = "Nombre invalide de caractères transférés";
    return false;
   }
  }
  cs = Int32.Parse(sRdAcr.ReadLine())
  numMorceau++.

  cs1 = numMorceau;
  cs2 = 0;

  FileStream fsIn = new FileStream(unFichier, FileMode.Open, FileAccess.Read)
  try
  {
   for (;;) {
    octetLus = fsIn.Read(tampon,0, 512);
    if(octetsLus <= 0) break;
    for (int j=0; j < octetsLus; j++) {
     cs1 = cs1 ^(int)tampon[j++];
     if (j != octetsLus) {
      cs2 = cs2 ^(int)tampon[j];


     }
    }
    fsOut.Write(tampon, 0, octetsLus);
    octetsTrans += octetsLus;
   }
   fsIn.Close();

  }
  catch (IOException)
  {
   
   merreur = "Erreur de lecture pour " + unFichier;
   return false;
  }
 }

}
catch (IOException)
{
 
merreur = "Fichier .acr invalide";
return false;
}

}
catch (FileNotFoundException)
{
merreur = "Le fichier " + fichierAcr + " n'existe pas";
}
return false;

 }
}
public string ErreurMessage() {
 return merreur;
}
public static void Main(string[] args)
{
 if (args.Length != 1) {
  Console.Error.WriteLine("Nombre de paramètres invalides");
  Console.Error.WriteLine("ColleCs fichierAcr");
  return;
 }
 string leFichierArc = args[0];

 if ( leFichierArc.LastIndexOf(".acr") != (leFichierArc.Length - 4)) {
  Console.Error.WriteLine("Ce n'est pas un fichier .acr");
  return;
 }
 ColleCs maColle = new ColleCs(leFichierArc);
 if (maColle.Colle()) {
  Console.Out.WriteLine("Colle terminée correctement")
 }
 else {
  Console.Error.WriteLine("Colle erreur: " + maColle.ErreurMessage());
 }
}