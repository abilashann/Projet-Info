package JobSeeker;

public class JobSeeker {

    private int id;
    private String firstName;
    private String lastName;
    private String password;
    private String Email;   
    private String Phone;
    private String Status;
    private String startDate;
    private String image;
     

    public JobSeeker(int id, String firstName, String lastName, String password, String Email, String Phone, String Status, String startDate, String image) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.password = password;
        this.Email = Email;
        this.Phone = Phone;
        this.Status = Status;
        this.startDate = startDate;
        this.image = image;
    }
    
    public JobSeeker()
    {
        
    }
        
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return Email;
    }

    public void setEmail(String Email) {
        this.Email = Email;
    }

    public String getPhone() {
        return Phone;
    }

    public void setPhone(String Phone) {
        this.Phone = Phone;
    }

    public String getStatus() {
        return Status;
    }

    public void setStatus(String Status) {
        this.Status = Status;
    }

    public String getStartDate() {
        return startDate;
    }

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }
    
    public void setImage(String img) {
        this.image = img;
    }
    
    public String getImage() {
        return image;
    }
    
}


