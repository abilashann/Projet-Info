package Agency;

public class Agency {
    
    /**
     * attribut
    */
    private int id;
    private String name;
    private String email;
    private String password;
    private String image;

    /**
     * constructor
     * @param name
     * @param email
     * @param password
     * @param image 
     */
    public Agency(String name, String email, String password, String image) {
        this.name = name;
        this.email = email;
        this.password = password;
        this.image = image;
    }
    /**
     * constructor
     */
    public Agency(){
        
    }
    /**
     * getteur name
     * @return 
     */
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    
    
    
}
