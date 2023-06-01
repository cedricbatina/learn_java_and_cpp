public class TireNumero {
 private static int nombreSorti;
 private static boolean tirage[];

 public int quelNumero;

 public TireNumero() {
  if (tirage == null) {
   tirage = new boolean[10];
  }
  if (nombreSorti == 10) {
   quelNumero = 0;
  } else {
   nombreSorti++;
   for (int i = 0; i < 10; i++) {
    if (tirage[i] == false) {
     tirage[i] = true;
     quelNumero = i + 1;
     break;
    }
   }
  }
 }

 public void dispose() {
  if (quelNumero != 0) {
   nombreSorti--;
   tirage[quelNumero - 1] = false;
  }
 }

 public int getNumero() {
  return quelNumero;
 }

 static int getNumeroSorti() {
  return nombreSorti;
 }

 static void message1() {
  System.out.println("Nombre sorti: " + " " + getNumeroSorti());

 }

 void message2() {
  System.out.println("Nombre actuel: " + " " + getNumero());
 }

 public static void main(String[] args) {
  TireNumero tn1 = new TireNumero();
  TireNumero tn2 = new TireNumero();
  TireNumero tn3 = new TireNumero();

  tn1.message2();
  tn3.message2();
  TireNumero.message1();

  tn2.dispose();
  tn1 = new TireNumero();
  tn1.message2();
  message1();

  TireNumero ttn[] = new TireNumero[10];

  for (int i = 0; i < 10; i++) {
   ttn[i] = new TireNumero();
  }
  ttn[4].message2();
  message1();

  for (int i = 0; i < 10; i++) {
   ttn[i].dispose();
  }
  tn1.dispose();
  tn2.dispose(); // !!!!
  tn3.dispose();
  ttn[9].message1();
 }

}
