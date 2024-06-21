/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package peopleclasses2;

/**
 *
 * @author devam
 */
public class Faculty extends Person {
    int employeeID;
    String department;
    public void displayInfo(){
        System.out.println("NAME: "+this.name+", AGE: "+this.age+", ID: "+this.employeeID+", Department: "+this.department);
    }
    public int getAge(){
        return this.age;
    }
}
