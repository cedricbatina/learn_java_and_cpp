//java & c++ main dans la main grâce au JNI
//utilisation d'une biblithèque c++ à partir d'un profgramme java
class SalutCPP {
 public native void salutations(); // native indique que la méthode salutations sera disponible dans une
                                   // bibliothèque

 static {
  System.out.println("Java: chargement de la bibliothèque salut.dll");
  System.loadLibrary("salut");
 }
}

class MonPremierJNI {
 public static void main(String[] args) {
  System.out.println("Java: création d'une instance de SalutCPP");
  SalutCPP monSalut = new SalutCPP();
  System.out.println("Java: appel de la méthode native salutations()");
  monSalut.salutations();
  System.out.println("Java: fin de programme");
 }
}