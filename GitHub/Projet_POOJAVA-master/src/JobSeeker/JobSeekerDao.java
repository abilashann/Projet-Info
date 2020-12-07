package JobSeeker;

import java.util.ArrayList;
import java.util.List;

public interface JobSeekerDao {

    public void affichage();

    public void addJobSeeker(JobSeeker js);

    public ArrayList<JobSeeker> getAllJobSeekers();

    public void update(JobSeeker js, int id);

    public boolean login(String firstName, String password);
    
    public void deleteJobSeeker(String email);

}
