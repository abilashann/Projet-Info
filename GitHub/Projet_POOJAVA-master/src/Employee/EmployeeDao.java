package Employee;

import java.util.ArrayList;

public interface EmployeeDao {

    public void addEmployee(Employee employee);

    public Employee getEmployee(String email);

    public void update(Employee employee, int id);
    
    public void updateMDP(String password, int id);

    public ArrayList<Employee> getAllEmployees();

    public void deleteEmployee(String email);

}
