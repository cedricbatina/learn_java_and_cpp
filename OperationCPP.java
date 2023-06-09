public class OperationCPP {
 private String lOperation;

 public native String operation(String loper, int num1, int num2);

 static {
  System.out.println("Java: chargement de la bibliothèque opération.dll");
  System.loadLibrary("operation");
 }

 public OperationCPP(String loper) {
  lOperation = loper;
 }

 public String execute(int num1, int num2) {
  return operation(lOperation, num1, num2);
 }

}
