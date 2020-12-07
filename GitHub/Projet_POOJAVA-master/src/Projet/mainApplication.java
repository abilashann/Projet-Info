package Projet;

import Agency.Agency;
import Job.JobImpl;
import Agency.AgencyImpl;
import Employee.Employee;
import Employee.EmployeeImpl;
import Job.Job;
import JobSeeker.*;
import java.util.ArrayList;
import java.util.Scanner;

public class mainApplication {

    Scanner scan = new Scanner(System.in);
    JobImpl jobimpl = new JobImpl();

    boolean login;
    int choix;

    ArrayList<Job> jobList;
    ArrayList<Employee> EmployeeList;
    ArrayList<Agency> AgencyList;
    ArrayList<JobSeeker> JobSeekerList;

    public mainApplication() {
        this.login = false;
        jobList = new ArrayList();
        EmployeeList = new ArrayList();
        AgencyList = new ArrayList();
        JobSeekerList = new ArrayList();

    }

    public void test() {
        System.out.println("liste des jobs \n");
        jobList = jobimpl.getAllJobs();
        for (Job jb : jobList) {
            System.out.println("\n\n\n");
            System.out.println(" id : " + jb.getId());
            System.out.println(" title : " + jb.getTitle());
            System.out.println(" description : " + jb.getDescription());
            System.out.println(" type : " + jb.getType());
            System.out.println(" popularity " + jb.getPopularity());
            System.out.println(" image :  " + jb.getImage());
            System.out.println(" skills " + jb.getSkills());
            System.out.println(" startDate " + jb.getStartDate());
            System.out.println(" id employee " + jb.getEmployerId());
        }

    }

    public void turn() {
        do {
            System.out.println("choose what you want to do \n");
            System.out.println("1) job"); ///
            System.out.println("2) jobseeker");
            System.out.println("3) employer"); ///
            System.out.println("4) agency"); ///
            choix = scan.nextInt();

        } while (choix < 1 || choix > 4);

        if (choix == 1) {
            do {
                System.out.println(" JOB ");
                System.out.println("1) ajouter job");
                System.out.println("2) supprimer job");
                System.out.println("3) modifier job");
                choix = scan.nextInt();

            } while (choix < 1 || choix > 3);

            if (choix == 1) {
                jobList.clear();
                jobList = jobimpl.getAllJobs();

                System.out.println("\n ajouter un job \n");
                Job job = new Job();
                System.out.print("what is the title : ");
                job.setTitle(scan.next());
                System.out.print("what is the description : ");
                job.setDescription(scan.next());
                System.out.print("what is the type of job : ");
                job.setType(scan.next());

                job.setPopularity(0);

                jobList.add(job);
                jobList = jobimpl.getAllJobs();

            } else if (choix == 2) {
                jobList.clear();
                jobList = jobimpl.getAllJobs();

                for (Job jb : jobList) {
                    System.out.println("\n\n");
                    System.out.println(" id : " + jb.getId());
                    System.out.println(" title : " + jb.getTitle());
                    System.out.println(" description : " + jb.getDescription());
                }

                System.out.println("\n delete a job \n ");
                System.out.println("quel id suprimer");
                choix = scan.nextInt();
                jobimpl.deleteJob(choix);
            } else if (choix == 3) {
                Job jb = new Job();
                System.out.println("\n modif a job \n ");
                System.out.println("quel id à modifier");
                choix = scan.nextInt();

                System.out.print("what is the new title : ");
                jb.setTitle(scan.next());
                System.out.print("what is the new description : ");
                jb.setDescription(scan.next());
                System.out.print("what is the new type of job : ");
                jb.setType(scan.next());

                jobimpl.update(jb, choix);
            }

        } else if (choix == 2) {
            do {
                JobSeekerImpl jbimpl = new JobSeekerImpl();
                JobSeeker js = new JobSeeker();

                System.out.println(" JOB SEEKER ");
                System.out.println("1) ajouter jobseeker");
                System.out.println("2) supprimer jobseeker");
                System.out.println("3) modifier jobseeker");
                choix = scan.nextInt();

                if (choix == 1) {

                    System.out.println("Tell me a little bite more about you ? ");
                    System.out.print(" What is your first name : ");
                    js.setFirstName(scan.next());
                    System.out.print(" what is your last Name : ");
                    js.setLastName(scan.next());
                    System.out.print(" what is your password : ");
                    js.setPassword(scan.next());
                    System.out.print(" what is your email : ");
                    js.setEmail(scan.next());
                    System.out.print(" what is you phone number : ");
                    js.setPhone(scan.next());
                    System.out.print(" what is your actual status : ");
                    js.setStatus(scan.next());
                    System.out.print(" when can you start to work ( format : YYYY/MM/DD : ");
                    js.setStartDate(scan.next());
                    js.setImage("null");
                    jbimpl.addJobSeeker(js);

                } else if (choix == 2) {
                    System.out.println(" DELETE jobSEEKER");
                    JobSeekerList.clear();
                    JobSeekerList = jbimpl.getAllJobSeekers();

                    for (JobSeeker jb : JobSeekerList) {
                        System.out.println("\n\n");
                        System.out.println(" id : " + jb.getId());
                        System.out.println(" fisrtname : " + jb.getFirstName());
                        System.out.println(" lastName : " + jb.getLastName());
                        System.out.println(" mail : " + jb.getEmail());
                        System.out.println(" phone : " + jb.getPhone());
                        System.out.println(" startdate : " + jb.getStartDate());
                        System.out.println(" status : " + jb.getStatus());

                    }
                    System.out.println("what is the id of the jobseeker you want to delete");
                    choix = scan.nextInt();
                    System.out.println(JobSeekerList.get(choix - 1).getEmail());
                    jbimpl.deleteJobSeeker(JobSeekerList.get(choix - 1).getEmail());

                } else if (choix == 3) {
                    System.out.println(" modify jobSeeker");

                    JobSeekerList.clear();
                    JobSeekerList = jbimpl.getAllJobSeekers();

                    for (JobSeeker jb : JobSeekerList) {
                        System.out.println("\n\n");
                        System.out.println(" id : " + jb.getId());
                        System.out.println(" fisrtname : " + jb.getFirstName());
                        System.out.println(" lastName : " + jb.getLastName());
                        System.out.println(" mail : " + jb.getEmail());
                        System.out.println(" phone : " + jb.getPhone());
                        System.out.println(" startdate : " + jb.getStartDate());
                        System.out.println(" status : " + jb.getStatus());

                    }

                    System.out.println("what is the id of the jobseeker you want to modify");
                    choix = scan.nextInt();

                    System.out.print("firstName ? ");
                    js.setFirstName(scan.next());
                    System.out.print("LastName ? ");
                    js.setLastName(scan.next());
                    System.out.print(" mail? ");
                    js.setEmail(scan.next());
                    System.out.print("password ? ");
                    js.setPassword(scan.next());
                    System.out.print("phone ? ");
                    js.setPhone(scan.next());
                    System.out.print(" status? ");
                    js.setStatus(scan.next());
                    System.out.print(" startdate? ");
                    js.setStartDate(scan.next());

                    js.setImage("null");

                    jbimpl.update(js, choix);

                } else {
                    choix = 4;
                }

            } while (choix < 1 || choix > 3);

        } else if (choix == 3) {

            EmployeeImpl employerimpl = new EmployeeImpl();
            Employee employer = new Employee();
            EmployeeList = employerimpl.getAllEmployees();
            do {
                System.out.println(" EMPLOYER ");
                System.out.println("1) ajouter employer");
                System.out.println("2) supprimer employer");
                System.out.println("3) modifier employer");
                choix = scan.nextInt();

                if (choix == 1) {

                    System.out.println("\n add a employer");
                    EmployeeList.clear();
                    EmployeeList = employerimpl.getAllEmployees();
                    System.out.print("name ? ");
                    employer.setName(scan.next());
                    System.out.print("email ? ");
                    employer.setEmail(scan.next());
                    System.out.print(" password? ");
                    employer.setPassword(scan.next());
                    System.out.print(" phone ? ");
                    employer.setPhone(scan.next());
                    System.out.print(" micro ? ");
                    employer.setMember(scan.nextInt());
                    employer.setMicro(0);
                    employer.setPrice(50);
                    employer.setImage(null);
                    employerimpl.addEmployee(employer);

                } else if (choix == 2) {

                    System.out.println("\n delete a employer");
                    EmployeeList.clear();
                    EmployeeList = employerimpl.getAllEmployees();

                    for (Employee jb : EmployeeList) {
                        System.out.println("\n\n");
                        System.out.println(" id : " + jb.getId());
                        System.out.println(" name : " + jb.getName());
                        System.out.println(" email : " + jb.getEmail());
                        System.out.println(" password : " + jb.getPassword());
                        System.out.println(" phone : " + jb.getPhone());

                    }

                    System.out.println(" quel employee voulez vous supprimer ");
                    choix = scan.nextInt();
                    employerimpl.deleteEmployee(EmployeeList.get(choix - 1).getEmail());

                } else if (choix == 3) {
                    System.out.println("\n modify a employer");
                    EmployeeList.clear();
                    EmployeeList = employerimpl.getAllEmployees();

                    for (Employee jb : EmployeeList) {
                        System.out.println("\n\n");
                        System.out.println(" id : " + jb.getId());
                        System.out.println(" name : " + jb.getName());
                        System.out.println(" email : " + jb.getEmail());
                        System.out.println(" password : " + jb.getPassword());
                        System.out.println(" phone : " + jb.getPhone());

                    }

                    System.out.println("what is the id of the jobseeker you want to modify");
                    choix = scan.nextInt();

                    System.out.print("name ? ");
                    employer.setName(scan.next());
                    System.out.print("mail ? ");
                    employer.setEmail(scan.next());
                    System.out.print("password ? ");
                    employer.setPassword(scan.next());
                    System.out.print("phone ? ");
                    employer.setPhone(scan.next());

                    employer.setImage("null");

                    employerimpl.update(employer, choix);

                    System.out.println(" quel employee voulez vous modifier ");
                    choix = scan.nextInt();
                    employerimpl.update(employer, choix);

                } else {
                    choix = 4;
                }

            } while (choix < 1 || choix > 3);

        } else {
            AgencyImpl agency = new AgencyImpl();
            Agency agence = new Agency();
            do {
                System.out.println(" AGENCY ");
                System.out.println("1) modifier agency");
                choix = scan.nextInt();

                if (choix == 1) {
                    System.out.println("\n update a employer");
                    AgencyList = agency.getAllEmployees();

                    for (Agency jb : AgencyList) {
                        System.out.println("\n\n");
                        System.out.println(" id : " + jb.getId());
                        System.out.println(" name : " + jb.getName());
                        System.out.println(" email : " + jb.getEmail());
                        System.out.println(" password : " + jb.getPassword());

                    }
                    System.out.println(" quel agency voulez vous modifier ");
                    choix = scan.nextInt();

                    System.out.print("name ? ");
                    agence.setName(scan.next());
                    System.out.print("email ? ");
                    agence.setEmail(scan.next());
                    System.out.print(" password? ");
                    agence.setPassword(scan.next());
                    agence.setImage("null");

                    agency.update(agence, choix);

                } else {

                    choix = 4;
                }

            } while (choix < 1 || choix > 2);

        }

    }

    public void jobSeeker() {
        int choix;
        JobSeekerImpl jsi = new JobSeekerImpl();
        boolean deco = false;

        do {
            System.out.println(" add you email and your password to login");
            System.out.print("email : ");
            String firstName = scan.next();
            System.out.print("password : ");
            String password = scan.next();
            login = jsi.login(firstName, password);

        } while (login == false);

        jobList = jobimpl.getAllJobs();
        System.out.println("\nYou're well connected !\n\n");
        do {
            do {
                System.out.println("1. See jobs");
                System.out.println("2. Sort");

                choix = scan.nextInt();

            } while (choix < 0 || choix > 3);

            if (choix == 1) {

                System.out.println(" There are all our available job");
                int k = 0;
                for (Job jb : jobList) {
                    k++;
                    System.out.println(k + " : " + jb.getTitle() + "\n");
                }

                System.out.println("Please select the job you want to have detail");
                jobList = jobimpl.getAllJobs();
                for (int i = 0; i < jobList.size(); i++) {
                    System.out.println((i + 1) + " : " + jobList.get(i).getTitle());
                }

                choix = scan.nextInt();

                System.out.println(" id : " + jobList.get((choix - 1)).getId());
                System.out.println(" title : " + jobList.get((choix - 1)).getTitle());
                System.out.println(" description : " + jobList.get((choix - 1)).getDescription());
                System.out.println(" type : " + jobList.get((choix - 1)).getType());
                System.out.println(" popularity : " + jobList.get((choix - 1)).getPopularity());
                System.out.println("");

                // GET POPULAR
                int pop = jobimpl.getJob(choix).getPopularity();
                jobimpl.updatePopularity(choix, (pop + 1));

            } else if (choix == 2) {
                System.out.println("\nVous allez trier vos trucs");
                System.out.print("voulez vous trie par (1) nom ou par (2) popularité : ");
                int tri = scan.nextInt();
                System.out.print("voulez vous trie par (1) ordre croissant ou par (2) ordre decroissant : ");
                int ordre = scan.nextInt();
                if (tri == 2) {
                    jobimpl.display(jobimpl.sortbyPopularity(ordre));
                }
                if (tri == 1) {
                    jobimpl.display(jobimpl.sortbyName(ordre));
                }

            }
        } while (deco == false);

    }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    public void company() {
        int choix;
        AgencyImpl ai = new AgencyImpl();

        do {
            System.out.println(" Add you mail and your password to login");
            System.out.print("mail : ");
            String firstName = scan.next();
            System.out.print("password : ");
            String password = scan.next();
            login = ai.login(firstName, password);

        } while (login == false);

    }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    public void employee() {
        EmployeeImpl ei = new EmployeeImpl();
        do {
            System.out.println(" add you id and your password to login");
            System.out.print("mail : ");
            String mail = scan.next();
            System.out.print("password : ");
            String password = scan.next();
            login = ei.login(mail, password);

        } while (login == false);
    }

}
