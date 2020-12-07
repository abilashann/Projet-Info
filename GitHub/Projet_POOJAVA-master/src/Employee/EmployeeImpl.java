package Employee;

import Job.Job;
import JobSeeker.JobSeeker;
import Projet.DataSource;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

public class EmployeeImpl {

    public EmployeeImpl() {

    }

    public void addEmployee(Employee emp) {
        Connection dbConnection = null;
        Statement statement = null;

        String query = "INSERT INTO employer VAlUES(" + null + ",'" + emp.getName() + "','" + emp.getEmail() + "','" + emp.getPassword() + "','" + emp.getPhone() + "'," + emp.getMember() + "," + emp.getMicro() + "," + emp.getPrice() + ",'" + "/ressources/images/basicProfilPicture.png" + "')";

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

    public void update(Employee employee, int id) {

        Connection dbConnection = null;
        Statement statement = null;

        String query = "UPDATE employer SET ";
        if (null != employee.getName()) {
            query += " name = '" + employee.getName() + "',";
        }
        if (null != employee.getEmail()) {
            query += " email = '" + employee.getEmail() + "',";
        }
        if (null != employee.getPhone()) {
            query += " phone = '" + employee.getPhone() + "',";
        }
        if (employee.getMicro() != 0) {
            query += " micro = '" + employee.getMicro() + "',";
        }
        if (employee.getPrice() != 0) {
            query += " price = '" + employee.getPrice() + "',";
        }
        if (null != employee.getImage()) {
            query += " image = '" + employee.getImage() + "',";
        }

        query += " members = '" + employee.getMember() + "'";
        query += " WHERE id=" + id;

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("The employer have been updated !");

        } catch (SQLException e) {
            System.out.println("couldn't update the employer");
            System.out.println(e.getMessage());
        }
    }

    public void updateMDP(String password, int id) {
        Connection dbConnection = null;
        Statement statement = null;

        String query = "UPDATE employer SET password = '" + password + "' WHERE id=" + id;

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

    public boolean login(String email, String password) {
        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet result = statement.executeQuery("SELECT * FROM employer");

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

    public Employee getEmployee(String email) {

        Employee emp = new Employee();
        Connection dbConnection = null;
        Statement statement = null;
        String query = "SELECT * FROM employer WHERE email = '" + email + "'";

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
                emp.setPhone(result.getString("phone"));
                emp.setMember(result.getInt("members"));
                emp.setMicro(result.getInt("micro"));
                emp.setPrice(result.getInt("price"));
                emp.setImage(result.getString("image"));
            }

        } catch (SQLException e) {
            System.out.println("couldn't find the Employer");
            System.out.println(e.getMessage());
        }
        return emp;
    }

    public ArrayList<Employee> getAllEmployees() {
        ArrayList<Employee> list = new ArrayList<>();
        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet rst = statement.executeQuery("SELECT * FROM employer");

            while (rst.next()) {
                Employee emp = new Employee(rst.getInt("id"), rst.getString("name"), rst.getString("email"), rst.getString("password"), rst.getString("phone"), rst.getInt("micro"), rst.getString("image"));
                list.add(emp);
            }
        } catch (SQLException e) {
            System.out.println("couldn't get all the Employer");
            System.out.println(e.getMessage());
        }
        return list;
    }

    public ArrayList<JobSeeker> getApplicants(Job job) {

        ArrayList<JobSeeker> list = new ArrayList<>();
        Connection dbConnection = null;
        Statement statement = null;
        String query = "SELECT * FROM register WHERE id_job = '" + job.getId() + "'";

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet result = statement.executeQuery(query);

            while (result.next()) {
                JobSeeker js = new JobSeeker();
                js.setId(result.getInt("id"));
                js.setFirstName(result.getString("firstName"));
                js.setLastName(result.getString("lastName"));
                js.setPassword(result.getString("password"));
                js.setEmail(result.getString("email"));
                js.setPhone(result.getString("phone"));
                js.setStatus(result.getString("status"));
                js.setStartDate(result.getString("startDate"));
                js.setImage(result.getString("image"));
                list.add(js);
            }
        } catch (SQLException e) {
            System.out.println("couldn't get all the applicants");
            System.out.println(e.getMessage());
        }
        return list;
    }

    public void deleteEmployee(String email) {

        Connection dbConnection = null;
        Statement statement = null;
        String query = "DELETE FROM employer WHERE email = '" + email + "'";
        System.out.println(query);

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("Employer deleted !");

        } catch (SQLException e) {
            System.out.println("couldn't delete the Employer");
            System.out.println(e.getMessage());
        }
    }

}
