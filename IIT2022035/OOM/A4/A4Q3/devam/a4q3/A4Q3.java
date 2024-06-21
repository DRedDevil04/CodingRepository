/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a4q3;
import java.util.*;
/**
 *
 * @author devam
 */
public class A4Q3 {

    public static void main(String[] args) {
        StudentDatabase db=new StudentDatabase();
        db.addStudent(new Student(35,"Devam","Desai"));
        db.addStudent(new Student(16,"Prernendu","Bhagat"));
        db.printStudent(35);
        db.removeStudent(35);
        db.printStudent(16);
    }
}
class Student {
    int studentID;
    String firstName;
    String lastName;
    Student(int id,String first,String last){
        this.studentID=id;
        this.firstName=first;
        this.lastName=last;
    }
    public void displayDetails()
    {
        System.out.println("\nThe roll number of the student is : " + studentID);
        System.out.println("\nThe name of the student is : " + firstName+" "+lastName);
    }
    public int getID(){
        return this.studentID;
    }
    public void setID(int id){
        this.studentID=id;
    }
    public void setFirstName(String first){
        this.firstName=first;
    }
    public void setLastName(String last){
        this.lastName=last;
    }
}
class StudentDatabase{
    private ArrayList<Student> data=new ArrayList<>();
    public void addStudent(Student s){
        data.add(s);
    }
    public void removeStudent(int id){
        for(int i=0;i<data.size();i++){
            if(id==data.get(i).getID()){
                data.remove(i);
                break;
            }
        }
    }
    public void printStudent(int id){
        for(int i=0;i<data.size();i++){
            if(id==data.get(i).getID()){
                data.get(i).displayDetails();
                break;
            }
        }
    }
    
}
