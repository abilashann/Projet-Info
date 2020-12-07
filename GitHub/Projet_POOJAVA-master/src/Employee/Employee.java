package Employee;

public class Employee {

    private int id;
    private String name;
    private String email;
    private String phone;
    private String password;
    private int member;
    private int micro;
    private int price;
    private String image;

    public Employee(int id, String name, String email, String password, String phone, int micro, String image) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.password = password;
        this.member = member;
        this.micro = micro;
        this.price = 50;
        this.image = image;
        if (this.member == 1) {

            this.price -= this.price * 10 / 100;
            if (this.micro == 1) {
                this.price -= this.price * 20 / 100;
            } else {
                if (this.micro == 1) {
                    this.price -= this.price * 20 / 100;
                }

            }
        }
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Employee() {
        this.member = 0;
    }

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

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public int getMember() {
        return member;
    }

    public void setMember(int member) {
        this.member = member;
    }

    public int getMicro() {
        return micro;
    }

    public void setMicro(int micro) {
        this.micro = micro;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
        if (this.member == 1) {

            this.price -= this.price * 10 / 100;
            if (this.micro == 1) {
                this.price -= this.price * 20 / 100;
            } else {
                if (this.micro == 1) {
                    this.price -= this.price * 20 / 100;
                }

            }
        }
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

}
