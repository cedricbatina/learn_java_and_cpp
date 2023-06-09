import java.awt.*;
import java.awt.event.*;

public class JuniorAnonymFrame extends Frame {
 private Button bouton;
 private Label etiquette;
 private int compteur;

 public JuniorAnonymFrame() {
  super("Note compteur");
  compteur = 0;
  setLayout(new FlowLayout());

  bouton = new Button("Compteur");
  bouton.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
    compteur++;
    String texte = new String("Le compteur est " + compteur);
    etiquette.setText(texte);
   }
  });
  etiquette = new Label("Le compteur est 0 ");
  add(bouton);
  add(etiquette);
 }

 public static void main(String[] args) {
  JuniorAnonymFrame f = new JuniorAnonymFrame();

  f.setSize(200, 100);
  f.setVisible(true);
  f.addWindowListener(new WindowAdapter() {
   public void windowClosing(WindowEvent e) {
    System.exit(0);
   }
  });
 }
}
