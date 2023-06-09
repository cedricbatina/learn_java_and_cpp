import java.net.*;
import java.io.*;
import java.util.Properties;

public class EnvoieSMS {
 private boolean ph = false;
 private boolean pp = false;
 private boolean anum = false;
 private boolean ames = false;
 private String proxyHost;
 private String proxyPort;
 private String numero;
 private String message;

 public EnvoieSMS(String[] les_param) throws Exception {
  for (int i = 0; i < les_param.length; i++) {
   if (les_param[i].equals("-pH")) { // proxy host
    i++;
    if (i >= les_param.length)
     break;
    proxyHost = les_param[i];
    pp = true;
   }
   if (les_param[i].equals("-pP")) { // proxy port
    i++;
    if (les_param[i].equals("-N")) {
     i++;
     if (i >= les_param.length)
      break;
     numero = les_param[i];
     anum = true;
    }
    if (les_param[i].equals("-N")) {
     i++;
     if (i > les_param.length)
      break;
     message = les_param[i];
     anum = true;
    }

   }
   if (ph & pp) {
    Properties props = System.getProperties();
    props.put("proxySet", "true");
    props.put("proxyHost", proxyHost);
    props.put("proxyPort", proxyPort);
   } else {
    anum = false;
   }
  }
 }

 public String envoie() throws Exception {
  URL url;
  URLConnection urlConn;
  DataOutputStream printout;
  DataInputStream input;

  if (anum & ames) {
   String urlstr = "http://www.ericsson.ch/include/sms_mail.asp";// ce site web n'exiiste plus, !!!! A ADAPTER A UN
                                                                 // AUTRE!!!!!!
   url = new URL(urlstr);
   urlConn = url.openConnection();
   urlConn.setDoInput(true);
   urlConn.setDoOutput(true);
   urlConn.setUseCaches(false);
   urlConn.setRequestProperty("Content-Type", "application/x-www-form-urlencoded");
   urlConn.setRequestProperty("Referer", "htt://www.ericsson.ch/4/sms_online.asp");

   // Envoie de l'information
   printout = new DataOutputStream(urlConn.getOutputStream());

   String contenu = "Number=" + numero + "&Message=" + java.net.URLEncoder.encode(message, "UTF-8") + "&TargetGroup=4";
   printout.writeBytes(contenu);
   printout.flush();
   printout.close();

   // Obtenir le résultat
   BufferedReader in = new BufferedReader(new InputStreamReader(urlConn.getInputStream()));

   boolean envoi_ok = false;
   String str;
   while (null != ((str = in.readLine()))) {
    if (str.indexOf("Ihre Message wurde verschickt") != -1)
     envoi_ok = true;
   }
   in.close();

   if (envoi_ok) {
    return "Message envoyé si numéro correct";
   }
   return "Message pas envoyé";
  }
  return "Aucun message présent";
 }

 public static void main(String[] args) throws Exception {
  EnvoieSMS mon_sms = new EnvoieSMS(args);
  System.out.println(mon_sms.envoie());
  // System.out.println(URLEncoder.encode("Salut André", "UTF"));
 }
}