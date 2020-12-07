package JobSeeker;

import Projet.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.ArrayList;

public class JobSeekerImpl implements JobSeekerDao {

    public JobSeekerImpl() {

    }

    @Override
    public void addJobSeeker(JobSeeker js) {

        Connection dbConnection = null;
        Statement statement = null;
        java.util.Date date = new java.util.Date();
        SimpleDateFormat sdf = new SimpleDateFormat(js.getStartDate());
        String query = "INSERT INTO jobseekers VAlUES(" + null + ",'" + js.getFirstName() + "','" + js.getLastName() + "','" + js.getPassword() + "','" + js.getEmail() + "','" + js.getPhone() + "','" + js.getStatus() + "','" + sdf.format(date) + "','" + "/ressources/images/basicProfilPicture.png" + "')";

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println(" Jobseeker profile created !");

        } catch (SQLException e) {
            System.out.println("couldn't add your profile");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void update(JobSeeker js, int id) {

        Connection dbConnection = null;
        Statement statement = null;
        //String qutery = "UPDATE jobSeekers Set firstName = '" + js.getFirstName() + "', lastName = '" + js.getLastName() + "', password = '" + js.getPassword() + "', email = '" + js.getEmail() + "', phone = '" + js.getPhone() + "', status = '" + js.getStatus() + "', startDate = '" + js.getStartDate() + "', image = '" + js.getImage() + "'Where id=" + id;

        String query = "UPDATE jobseekers SET ";
        if (null != js.getFirstName()) {
            query += " firstName = '" + js.getFirstName() + "',";
        }
        if (null != js.getLastName()) {
            query += " lastName = '" + js.getLastName() + "',";
        }
        if (null != js.getEmail()) {
            query += " Email = '" + js.getEmail() + "',";
        }
        if (null != js.getPhone()) {
            query += " phone = '" + js.getPhone() + "',";
        }
        if (null != js.getStatus()) {
            query += " status = '" + js.getStatus() + "',";
        }
        if (null != js.getStartDate()) {
            query += " startDate = '" + js.getStartDate() + "',";
        }
        if (null != js.getImage()) {
            query += " image = '" + js.getImage() + "',";
        }

        query += " WHERE id=" + id;

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("The jobseeker have been updated !");

        } catch (SQLException e) {
            System.out.println("couldn't update the jobseeker");
            System.out.println(e.getMessage());
        }
    }

    public void updateMDP(String password, int id) {
        Connection dbConnection = null;
        Statement statement = null;

        String query = "UPDATE  jobseekers SET password = '" + password + "' WHERE id=" + id;

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("The password have been updated !");

        } catch (SQLException e) {
            System.out.println("couldn't update the password");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void deleteJobSeeker(String email) {
        Connection dbConnection = null;
        Statement statement = null;
        String query = "DELETE FROM jobSeekers WHERE Email = '" + email + "'";
        System.out.println(query);

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("jobseeker deleted !");

        } catch (SQLException e) {
            System.out.println("couldn't delete the jobseeker");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void affichage() {

        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet result = statement.executeQuery("SELECT * FROM jobseekers");

            while (result.next()) {

                System.out.print(result.getInt("id") + "\t");
                System.out.print(result.getString("firstName") + "\t");
                System.out.print(result.getString("lastName") + "\t");
                System.out.print(result.getString("password") + "\t");
                System.out.print(result.getString("email") + "\t");
                System.out.print(result.getString("phone") + "\t");
                System.out.print(result.getString("status") + "\t");
                System.out.print(result.getDate("startDate") + "\t\t");
                System.out.println("");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public boolean login(String Name, String password) {

        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet result = statement.executeQuery("SELECT * FROM jobseekers");

            while (result.next()) {
                if (Name.compareTo(result.getString("email")) == 0) {
                    if (password.compareTo(result.getString("password")) == 0) {
                        return true;
                    }
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return false;
    }

    public JobSeeker getJobSeeker(String email) {

        JobSeeker jbsk = new JobSeeker();
        Connection dbConnection = null;
        Statement statement = null;
        String query = "SELECT * FROM jobseekers WHERE email = '" + email + "'";

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            ResultSet result = statement.executeQuery(query);
            if (result.next()) {
                jbsk.setEmail(email);
                jbsk.setId(result.getInt("id"));
                jbsk.setFirstName(result.getString("firstName"));
                jbsk.setLastName(result.getString("lastName"));
                jbsk.setPassword(result.getString("password"));
                jbsk.setPhone(result.getString("phone"));
                jbsk.setStatus(result.getString("status"));
                jbsk.setStartDate(result.getString("startDate"));
                jbsk.setImage(result.getString("image"));
            }

        } catch (SQLException e) {
            System.out.println("couldn't find the JobSeeker");
            System.out.println(e.getMessage());
        }
        return jbsk;
    }

    @Override
    public ArrayList<JobSeeker> getAllJobSeekers() {

        ArrayList<JobSeeker> list = new ArrayList<>();

        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet rst = statement.executeQuery("SELECT * FROM jobseekers");

            while (rst.next()) {
                JobSeeker js = new JobSeeker(rst.getInt("id"), rst.getString("firstName"), rst.getString("lastName"), rst.getString("password"),
                        rst.getString("email"), rst.getString("phone"), rst.getString("status"), rst.getString("startDate"), rst.getString("image"));
                list.add(js);
            }
        } catch (SQLException e) {
             System.out.println("couldn't get all the JobSeekers");
            System.out.println(e.getMessage());
        }
        return list;
    }

}
