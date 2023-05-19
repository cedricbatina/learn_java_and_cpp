
public class Othello1 {
 static final int dim = 10;

 int[][] othello = new int[dim][dim];

 public Othello1() {
  int i = 0; // position horizontale
  int j = 0; // position verticale

  for (i = 0; i < dim; i++) { // bord à -1

   othello[i][0] = -1;
   othello[i][dim - 1] = -1;
   othello[0][i] = -1;
   othello[dim - 1][i] = -1;

   /*
    * //
    * othello[0][i] = -1;
    * othello[dim - 1][i] = -1;
    * othello[i][0] = -1;
    * othello[i][dim - 1] = -1;
    * 
    * //
    */
  }
  for (j = 1; j < dim - 1; j++) // intérieur vide
  {
   for (i = 1; i < dim - 1; i++) {
    othello[i][j] = 0;
   }
  }
  othello[4][5] = 1; // blanc
  othello[5][4] = 1; // blanc
  othello[4][4] = 2; // noir
  othello[5][5] = 2; // noir
 }

 public void test1() {
  int i = 0; // position horizontale
  int j = 0; // position verticale
  for (j = 0; j < dim; j++) {
   for (i = 0; i < dim; i++) {
    if (othello[i][j] >= 0) {
     System.out.print(" ");
    }
    System.out.print(othello[i][j]);

   }
  }
  System.out.println();

 }

 public static void main(String[] args) {
  Othello1 monjeu = new Othello1();
  monjeu.test1();
 }
}