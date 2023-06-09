import javax.swing.*;
import javax.swing.text.*;

import java.awt.Toolkit;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.Locale;

public class ChampNombre extends JTextField {
 private Toolkit toolkit;
 private NumberFormat integerFormatter;

 public ChampNombre(int value, int columns) {
  super(columns);
  toolkit = Toolkit.getDefaultToolkit();
  integerFormatter = NumberFormat.getNumberInstance(Locale.FRANCE);
  integerFormatter.setParseIntegerOnly(true);
  setValue(value);
 }

 public int getValue() {
  int retVal = 0;
  try {
   retVal = integerFormatter.parse(getText()).intValue();
  } catch (ParseException e) {
   toolkit.beep();
  }
  return retVal;
 }

 public void setValue(int value) {
  setText(integerFormatter.format(value));
 }

 protected Document createDefaultModel() {
  return new DocumentNombre();
 }

 protected class DocumentNombre extends PlainDocument {
  public void insertString(int pos, String str, AttributeSet as) throws BadLocationException {
   char[] source = str.toCharArray();
   char[] resultat = new char[source.length];
   int j = 0;

   for (int i = 0; i < resultat.length; i++) {
    if (Character.isDigit(source[i])) {
     resultat[j++] = source[i];

    } else {
     toolkit.beep();
    }
   }
   super.insertString(pos, new String(resultat, 0, j), as);
  }
 }
}