public class MonThread2 implements Runnable {
 public void depart() {
  Thread t1 = new Thread(this, "Processus 1");
  t1.start();
  System.out.println("TEST 1");

  Thread t2 = new Thread(this, "Processus 2");
  t2.start();
  System.out.println("Test 2");
 }

 public void run() {
  System.out.println("Commence pour " + Thread.currentThread().getName());
  try {
   Thread.sleep(1000);
  } catch (InterruptedException ie) {
   System.out.println("Termine pour " + Thread.currentThread().getName());
   ;
  }

 }

 public static void main(String[] args) {
  MonThread2 mt = new MonThread2();
  mt.depart();
 }
}
