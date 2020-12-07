package Job;


import Employee.Employee;
import JobSeeker.JobSeeker;
import java.util.ArrayList;

/**
 *
 * @author julie
 */
public interface JobDao {

    public void addJob(Job job, Employee emp);
    
    public Job getJob(int id);
    
    public ArrayList<Job> getEmployerJobs(Employee emp);
    
    public void update(Job job, int id);
    
    public ArrayList<Job> getAllJobs();
    
    public void deleteJob(int id);
    
    public void updatePopularity(int id, int popu);
    
    public ArrayList<Job> sortbyPopularity(int i);
    
    public void applyJob(Job job, JobSeeker js);
}
