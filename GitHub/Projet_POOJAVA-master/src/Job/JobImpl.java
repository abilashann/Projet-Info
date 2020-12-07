package Job;

import Employee.Employee;
import JobSeeker.JobSeeker;
import Projet.DataSource;
import java.sql.*;
import java.util.ArrayList;

public class JobImpl implements JobDao {

    public JobImpl() {

    }

    @Override
    public void addJob(Job job, Employee emp) {

        Connection dbConnection = null;
        Statement statement = null;
        System.out.println("la");
        String query = "INSERT INTO job VAlUES(" + "null" + ",'" + job.getTitle() + "','" + job.getDescription() + "','" + job.getType() + "','" + job.getPopularity() + "','" + job.getImage() + "','" + job.getSkills() + "','" + job.getStartDate() + "','" + emp.getId() + "')";

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println(" Job added !");

        } catch (SQLException e) {
            System.out.println("couldn't add the Job");
            System.out.println(e.getMessage());
        }
    }

    // public void deleteJob() {
    //    jobDao.delete(7);
    //    jobList.clear();
    //    addJobDB();
    //}
    @Override
    public void deleteJob(int id) {

        Connection dbConnection = null;
        Statement statement = null;
        String query = "DELETE FROM job WHERE id=" + id;

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("Produit bien supprimé");

        } catch (SQLException e) {
            System.out.println("couldn't delete the Job");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public Job getJob(int id) {

        Job job = new Job();
        Connection dbConnection = null;
        Statement statement = null;
        String query = "SELECT * FROM job WHERE id = '" + id + "'";

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            ResultSet result = statement.executeQuery(query);
            if (result.next()) {
                job.setId(id);
                job.setTitle(result.getString("title"));
                job.setDescription(result.getString("description"));
                job.setType(result.getString("type"));
                job.setPopularity(result.getInt("popularity"));
                job.setImage(result.getString("image"));
                job.setType(result.getString("skills"));
                job.setStartDate(result.getString("startDate"));
                job.setEmployerId(result.getInt("id_employee"));
            }

        } catch (SQLException e) {
            System.out.println("couldn't find the job");
            System.out.println(e.getMessage());
        }
        return job;
    }

    
    @Override
    public ArrayList<Job> getEmployerJobs(Employee emp) {

        ArrayList<Job> list = new ArrayList<>();
        Connection dbConnection = null;
        Statement statement = null;
        String query = "SELECT * FROM job WHERE id_employee = '" + emp.getId() + "'";

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            ResultSet rst = statement.executeQuery(query);
            while (rst.next()) {
                Job job = new Job(rst.getInt("id"),rst.getString("title"), rst.getString("description"), rst.getString("type"), rst.getInt("popularity"), rst.getString("image"), rst.getString("skills"), rst.getString("startDate"),rst.getInt("id_employee"));
                list.add(job);
            }

        } catch (SQLException e) {
            System.out.println("couldn't find the job");
            System.out.println(e.getMessage());
        }
        return list;
    }
    
    @Override
    public void updatePopularity(int id, int popu) {

        Connection dbConnection = null;
        Statement statement = null;
        String query = "UPDATE job Set popularity = " + popu + " Where id = " + id;
        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("The job have been updated !");

        } catch (SQLException e) {
            System.out.println("couldn't update the job");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void update(Job job, int id) {

        Connection dbConnection = null;
        Statement statement = null;

        String query = "UPDATE job Set title = '" + job.getTitle() + "', description = '" + job.getDescription() + "', type = '" + job.getType() + "', image = '" + job.getImage() + "' Where id=" + id;
        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println("The job have been updated !");

        } catch (SQLException e) {
            System.out.println("couldn't update the job");
            System.out.println(e.getMessage());
        }
    }

    @Override
    public ArrayList<Job> sortbyPopularity(int i) {
        ArrayList<Job> list = new ArrayList<>();
        String query = null;
        Connection dbConnection = null;
        Statement statement = null;
        if (i == 1) {
            query = "SELECT id, title, description, type, popularity FROM job ORDER BY popularity ASC";
            System.out.println("sorting by popularity... ");
        } else if (i == 2) {
            query = "SELECT id, title, description, type, popularity FROM job ORDER BY popularity DESC";
        }
        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            ResultSet rst = statement.executeQuery(query);

            while (rst.next()) {
                Job job = new Job(rst.getInt("id"),rst.getString("title"), rst.getString("description"), rst.getString("type"), rst.getInt("popularity"), rst.getString("image"), rst.getString("skills"), rst.getString("startDate"),rst.getInt("id_employee"));
                list.add(job);
            }
        } catch (SQLException e) {
            System.out.println("couldn't sort the jobs");
            System.out.println(e.getMessage());
        }
        return list;
    }

    public ArrayList<Job> sortbyName(int i) {
        ArrayList<Job> list = new ArrayList<>();
        String query = null;
        Connection dbConnection = null;
        Statement statement = null;
        if (i == 1) {
            query = "SELECT id, title, description, type, popularity FROM job ORDER BY title ASC";
            System.out.println("sorting by names ascendantly... ");
        } else if (i == 2) {
            query = "SELECT id, title, description, type, popularity FROM job ORDER BY title DESC";
            System.out.println("sorting by names descendently... ");
        }
        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            ResultSet rst = statement.executeQuery(query);

            while (rst.next()) {
                Job job = new Job(rst.getInt("id"),rst.getString("title"), rst.getString("description"), rst.getString("type"), rst.getInt("popularity"), rst.getString("image"), rst.getString("skills"), rst.getString("startDate"),rst.getInt("id_employee"));
                list.add(job);
            }
        } catch (SQLException e) {
            System.out.println("couldn't sort the jobs");
            System.out.println(e.getMessage());
        }
        return list;
    }

    @Override
    public ArrayList<Job> getAllJobs() {
        ArrayList<Job> list = new ArrayList<>();
        Connection dbConnection = null;
        Statement statement = null;

        try {
            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();

            ResultSet rst = statement.executeQuery("SELECT * FROM job");

            while (rst.next()) {
                Job job = new Job(rst.getInt("id"),rst.getString("title"), rst.getString("description"), rst.getString("type"), rst.getInt("popularity"), rst.getString("image"), rst.getString("skills"), rst.getString("startDate"),rst.getInt("id_employee"));
                list.add(job);
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return list;
    }
    
    @Override
    public void applyJob(Job job, JobSeeker js) {

        Connection dbConnection = null;
        Statement statement = null;
        String query = "INSERT INTO register VAlUES(" + "null" + ",'" + job.getEmployerId() + "','" + js.getId() + "','" + job.getId() + "')";

        try {

            DataSource dataSource = new DataSource();
            dbConnection = dataSource.createConnection();
            statement = dbConnection.createStatement();
            statement.executeUpdate(query);
            System.out.println(" Applied !");

        } catch (SQLException e) {
            System.out.println("couldn't apply for the Job");
            System.out.println(e.getMessage());
        }
    }
    

    public void display(ArrayList<Job> jobList) {
        for (Job jb : jobList) {
            System.out.println(" id : " + jb.getId());
            System.out.println(" title : " + jb.getTitle());
            System.out.println(" description : " + jb.getDescription());
            System.out.println("type : " + jb.getType());
            System.out.println("popularity " + jb.getPopularity());
            System.out.println("");
        }
    }

}
