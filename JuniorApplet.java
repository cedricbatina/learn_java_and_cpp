import java.applet.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.Action;

public class JuniorApplet extends Applet {
 private Button bouton;
 private Label etiquette;
 private int compteur;

 public void init() {
  compteur = 0;
  setLayout(new FlowLayout());
  setFont(new Font("Courrier New", Font.BOLD, 18));

  bouton = new Button("Compteur");
  bouton.addActionListener(new EvtCompte());
  bouton.addMouseListener(new EvtMouse());

  etiquette = new Label("Clique sur le bouton pour augmenter le compteur");
  etiquette.setAlignment(Label.CENTER);

  add(bouton);
  add(etiquette);
  setBackground(Color.ORANGE);

 }

 private void nouveauTexte(String texte) {
  etiquette.setText(texte);
 }

 class EvtCompte implements ActionListener {
  public void actionPerformed(ActionEvent e) {
   compteur++;
   nouveauTexte("Clique sur le bouton pour augmenter le compteur");

  }

 }

 class EvtMouse implements MouseListener {
  public void mouseEntered(MouseEvent e) {
   nouveauTexte("Clique sur le bouton pour augmenter le compteur");
  }

  public void mouseExited(MouseEvent e) {
   nouveauTexte("Le compteur est " + compteur + " ");

  }

  public void mouseClicked(MouseEvent e) {

  }

  public void mousePressed(MouseEvent e) {
  }

  public void mouseReleased(MouseEvent e) {
  }
 }

 public static void main(String[] args) {
  JuniorApplet applet = new JuniorApplet();
  Frame f = new Frame("JuniorApplet");
  f.addWindowListener(new WindowAdapter() {
   public void windowClosing(WindowEvent e) {
    System.exit(0);
   }
  });
  f.setSize(500, 120);
  f.add(applet);
  applet.init();
  applet.start();
  f.setVisible(true);
 }
}
