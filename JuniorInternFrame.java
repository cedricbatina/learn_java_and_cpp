import java.awt.*;
import java.awt.event.*;

public class JuniorInternFrame extends Frame {
 private Button bouton;
 private Label etiquette;
 private int compteur;

 public JuniorInternFrame() {
  compteur = 0;
  setLayout(new FlowLayout());

  bouton = new Button("Compteur");
  bouton.addActionListener(new EvtCompte());

  etiquette = new Label("Le compteur est  0");

  add(bouton);
  add(etiquette);
  setBackground(Color.ORANGE);
 }

 class EvtCompte implements ActionListener {
  public void actionPerformed(ActionEvent e) {
   compteur++;
   String texte = new String("Le compteur est " + compteur);
   etiquette.setText(texte);

  }
 }

 static class EvtQuit extends WindowAdapter {
  public void windowClosing(WindowEvent e) {
   System.exit(0);
  }
 }

 public static void main(String[] args) {
  JuniorInternFrame f = new JuniorInternFrame();

  f.setSize(200, 100);
  f.setVisible(true);
  f.addWindowListener(new EvtQuit());
 }
}
