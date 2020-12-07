package Projet;

/*
    pour faire fonctionner le machin
        Envoi env = new Envoi();
        env.sendMail();
 */
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.*;

public class Mail {

    protected String destinataire = "julie.trochon@gmail.com";
    protected String auteur = "jobfindor@gmail.com";
    protected String objet = " CONGRATS FDP ";
    protected String password = "projetJAVA2020";

    protected String corps = "FUCKING MESSAGE DU MAIL";

    /**
     * Objet session JavaMail.
     */
    protected Session session;
    /**
     * Objet message JavaMail.
     */
    protected Message mesg;

    public void sendMail() {

        Properties props = new Properties();
        /**
         * propriétée
         */
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.starttls.enable", "true");
        props.put("mail.smtp.host", "smtp.gmail.com");
        props.put("mail.smtp.port", "587");
        props.put("mail.smtp.ssl.trust", "smtp.gmail.com");

        Session session = Session.getInstance(props, new javax.mail.Authenticator() {
            protected PasswordAuthentication getPasswordAuthentication() {
                return new PasswordAuthentication(auteur, password);
            }
        });

        try {

            Message message = new MimeMessage(session);
            message.setFrom(new InternetAddress(auteur));
            message.setRecipients(Message.RecipientType.TO,
                    InternetAddress.parse(destinataire));
            message.setSubject(objet);
            message.setText(corps);

            Transport.send(message);

        } catch (MessagingException ex) {
            System.out.println(" ah non you can't send nudes, oh wait ... :  " + ex.getMessage());

        }

    }
}
