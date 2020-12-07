package Agency;

import Projet.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class AgencyImpl implements AgencyDao {

    public AgencyImpl() {
    }

    @Override
    public void addAgency(Agency ag) {
        Connection dbConnection = null;
        Statement statement = null;
        String query = "INSERT INTO company VAlUES(" + null + ",'" + ag.getName() + "','" + ag.getEmail() + "','" + ag.getPassword() + "','" + ag.getImage() + "')";

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println(" Profile created !");

        } catch (SQLException e) {
            System.out.println("couldn't create profile");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public ArrayList<Agency> getAllEmployees() {
        ArrayList<Agency> list = new ArrayList<>();
        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet rst = statement.executeQuery("SELECT * FROM company");

            while (rst.next()) {
                Agency emp = new Agency(rst.getString("name"), rst.getString("email"), rst.getString("password"), rst.getString("image"));
                list.add(emp);
            }
        } catch (SQLException e) {
            System.out.println("couldn't get all the agency");
            System.out.println(e.getMessage());
        }
        return list;
    }

    @Override
    public void update(Agency agency, int id) {
        Connection dbConnection = null;
        Statement statement = null;

        String query = "UPDATE company Set name = '" + agency.getName() + "', email = '" + agency.getEmail() + "', password = '" + agency.getPassword() + "', image = '" + agency.getImage() + "' Where id=" + id;
        

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("The agency have been updated !");

        } catch (SQLException e) {
            System.out.println("couldn't update the agency");
            System.out.println(e.getMessage());
        }
    }

    public boolean login(String email, String password) {
        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet result = statement.executeQuery("SELECT * FROM company");

            while (result.next()) {
                if (email.compareTo(result.getString("email")) == 0) {
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

    @Override
    public Agency getAgency(String email) {

        Agency emp = new Agency();
        Connection dbConnection = null;
        Statement statement = null;
        String query = "SELECT * FROM company WHERE email = '" + email + "'";

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            ResultSet result = statement.executeQuery(query);
            if (result.next()) {
                emp.setEmail(email);
                emp.setId(result.getInt("id"));
                emp.setName(result.getString("name"));
                emp.setPassword(result.getString("password"));
                emp.setImage(result.getString("image"));

            }

        } catch (SQLException e) {
            System.out.println("couldn't find the Agency employee");
            System.out.println(e.getMessage());
        }
        return emp;
    }

    @Override
    public void deleteAgency(String email) {

        Connection dbConnection = null;
        Statement statement = null;
        String query = "DELETE FROM company WHERE email=" + email;

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("Agency deleted !");

        } catch (SQLException e) {
            System.out.println("couldn't delete the Agency employee");
            System.out.println(e.getMessage());
        }
    }

    public void display(ArrayList<Agency> agencyList) {
        for (Agency jb : agencyList) {
            System.out.println("name : " + jb.getName());
            System.out.println("email : " + jb.getEmail());
            System.out.println("password : " + jb.getPassword());
        }
    }

}
