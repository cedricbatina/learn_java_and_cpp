import java.sql.*;

public class PersonnesODBC {
 public static void main(String[] args) {
  String url = "jdbc:odbc:ODBC-java-test";

  Connection con;
  Statement stmt;
  String requete = "select Nom, Prenom, Annee FROM Personnes";
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

   System.out.println("Exécute la requête");
   ResultSet rs = stmt.executeQuery(requete);
   System.out.println("Les entrées dans notre base de données: ");
   while (rs.next()) {
    String nom = rs.getString("Nom");
    String prenom = rs.getString("Prenom");
    int annee = rs.getInt("Annee");

    System.out.println(nom + " " + prenom + " est né en " + annee);
   }

   stmt.close();
   con.close();
  }

  catch (SQLException ex) {
   System.err.println(("SQLException: " + ex.getMessage()));
  }
 }
}