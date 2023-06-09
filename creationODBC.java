
//création d'une table db en java
import java.sql.*;

public class creationODBC {

 public static void main(String[] args) {
  String url = "jdbc:odbc:ODBC-java-test";

  Connection con;
  Statement stmt;

  try {
   Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
  } catch (java.lang.ClassNotFoundException e) {
   System.err.print("ClassNotFoundException: ");
   System.err.println(e.getMessage());
   return;
  }
  try {
   System.out.println("Connexion avec ODBC-Java-Test");
   con = DriverManager.getConnection(url, "", "");
   stmt = con.createStatement();

   System.out.println("Création de la table Telephone");
   stmt.executeUpdate("CREATE TABLE Telephone (Nom VARCHAR, Prenom VARCHAR, NumTel VARCHAR)");

   System.out.println("Insertion d'objets dans la table Telephone");
   stmt.executeUpdate("INSERT INTO Telephone (Nom, Prenom, NumTel) VALUES ('Nvuluzi', 'Kimbangu','0748484902')");
   stmt.executeUpdate("INSERT INTO Telephone (Nom, Prenom) VALUES ('Batina', 'Cedric')");

   System.out.println("Modifie un enregistrement dans la table Telephone");
   stmt.executeUpdate("UPDATE Telephone SET NumTel = '0780845004' WHERE Nom = 'Batina'");

   System.out.println("Exécute la requête");
   ResultSet rs = stmt.executeQuery("SELECT Nom, Prenom, NumTel FROM Telephone");

   System.out.println("Les entrées dans notre table Telephone: ");
   while (rs.next()) {
    String nom = rs.getString(1);
    String prenom = rs.getString(2);
    String numTel = rs.getString(3);

    System.out.println("Enregistrement: " + nom + " " + prenom + " : " + numTel);
   }
   stmt.close();
   con.close();

  } catch (SQLException ex) {
   System.err.println("SQLException: " + ex.getMessage());
  }
 }
}