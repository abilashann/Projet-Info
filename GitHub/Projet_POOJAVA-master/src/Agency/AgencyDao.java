package Agency;

import java.util.ArrayList;


public interface AgencyDao {

    public void addAgency(Agency employee);
    
    public Agency getAgency(String email);
    
    public void deleteAgency(String email);
    
    public void update(Agency agency, int id);
    
    public ArrayList<Agency> getAllEmployees();
    
    public boolean login(String email, String password);

}
