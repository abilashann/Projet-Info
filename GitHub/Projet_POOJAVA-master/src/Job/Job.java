package Job;

public class Job implements Comparable<Job> {

    private int id;
    private String title;
    private String description;
    private String type;
    private int popularity;
    private String image;
    private String skills;
    private String startDate;
    private int employerId;
    

    public Job(int id, String title, String description, String type, int popularity, String image, String skills, String startDate, int id_emp) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.type = type;
        this.popularity = 0;
        this.image = image;
        this.skills = skills;
        this.startDate = startDate;
        this.employerId = id_emp;
    }
    
    public Job(){}

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    
    public int getEmployerId() {
        return employerId;
    }

    public void setEmployerId(int id) {
        this.employerId = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getPopularity() {
        return popularity;
    }
    
    public void setPopularity(int popularity) {
        this.popularity = popularity;
    }
    
    public void setImage(String img) {
        this.image = img;
    }
    
    public String getImage() {
        return image;
    }
    
    public void setSkills(String skills) {
        this.skills = skills;
    }
    
    public String getSkills() {
        return skills;
    }
    
    public String getStartDate() {
        return startDate;
    }

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }

    @Override
    public int compareTo(Job t) {

        return type.compareTo(t.getType());
    }
}
