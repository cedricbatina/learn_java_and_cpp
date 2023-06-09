import java.awt.*;
import java.awt.event.*;

public class JuniorFrame extends Frame {
 private Button bouton;
 private Label etiquette;
 private int compteur;

 public JuniorFrame() {
  compteur = 0;
  setLayout(new BorderLayout());

  bouton = new Button("Compteur");
  bouton.addActionListener(new EvtCompte());
  bouton.addMouseListener(new EvtMouse());

  etiquette = new Label("Le compteur est 0");
  etiquette.setAlignment(Label.CENTER);

  add(bouton, BorderLayout.CENTER);
  add(etiquette, BorderLayout.SOUTH);
  setBackground(Color.GREEN);
 }

 private void nouveauTexte(String texte) {
  etiquette.setText(texte);
 }

 class EvtCompte implements ActionListener {
  public void actionPerformed(ActionEvent e) {
   compteur++;
   nouveauTexte("Le compteur est " + compteur);
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
  JuniorFrame f = new JuniorFrame();

  f.setSize(300, 100);
  f.setVisible(true);
  f.addWindowListener(new WindowAdapter() {
   public void windowClosing(WindowEvent e) {
    System.exit(0);
   }
  });
 }
}
