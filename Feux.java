public class Feux {
 public static void main(String[] args) {
  byte feux = 0x03;// 00000011
  System.out.println("Feux1: " + Integer.toBinaryString(feux));
  feux <<= 2; // 00001100
  System.out.println("Feux2: " + Integer.toBinaryString(feux));
  feux <<= 4; // 01000000 + négatif
  System.out.println("Feux3: " + Integer.toBinaryString(feux));
  feux <<= 6; // 00000001 + négatif
  System.out.println("Feux4: " + Integer.toBinaryString(feux));

  int ifeux = 0x03; // 00000011
  ifeux >>= 1;// 00000001
  System.out.println("IFeux: " + Integer.toBinaryString(ifeux));

 }

}
