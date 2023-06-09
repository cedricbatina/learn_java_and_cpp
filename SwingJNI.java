import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SwingJNI {
 public void creationDesComposants(JFrame frame) {
  final JLabel label = new JLabel("Le résultat de la multiplication ou du l'addition");

  final ChampNombre entree1 = new ChampNombre(10, 5);

  final ChampNombre entree2 = new ChampNombre(20, 5);

  JButton bouton1 = new JButton("Multiplication");

  bouton1.setMnemonic(KeyEvent.VK_I);
  bouton1.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
    OperationCPP oper = new OperationCPP("Addition");
    int num1 = entree1.getValue();
    int num2 = entree2.getValue();

    label.setText("Le résultat de la multiplication: " + oper.execute(num1, num2));
   }
  });
  label.setLabelFor(bouton1);
  JButton bouton2 = new JButton("Addition");
  bouton2.setMnemonic(KeyEvent.VK_I);
  bouton2.addActionListener(new ActionListener() {
   public void actionPerformed(ActionEvent e) {
    OperationCPP oper = new OperationCPP(null);
    int num1 = entree1.getValue();
    int num2 = entree2.getValue();
    label.setText("Le résultat de l'addition: " + oper.execute(num1, num2));

   }
  });

  label.setLabelFor(bouton2);

  JPanel panneau1 = new JPanel();
  panneau1.setLayout(new FlowLayout());
  panneau1.add(entree2);
  panneau1.add(entree2);

  JPanel panneau2 = new JPanel();
  panneau2.add(bouton1);
  panneau2.add(bouton2);
  JPanel panneau3 = new JPanel();
  panneau3.add(label);

  frame.getContentPane().add(panneau1, BorderLayout.NORTH);
  frame.getContentPane().add(panneau2, BorderLayout.CENTER);
  frame.getContentPane().add(panneau3, BorderLayout.SOUTH);
  return;
 }

 public static void main(String[] args) {
  try {
   UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
  } catch (Exception e) {
   JFrame frame = new JFrame("SwingJNI");
   SwingJNI app = new SwingJNI();
   app.creationDesComposants(frame);
   frame.addWindowListener(new WindowAdapter() {
    public void windowsClosing(WindowEvent e) {
     System.exit(0);
    }
   });
   frame.pack();
   frame.setVisible(true);
  }
 }
}
