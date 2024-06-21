/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package peopleclasses;

/**
 *
 * @author devam
 */
public class Principal extends Person{
    int principalID;
    int yearsOfExperience;
    public void displayInfo(){
        System.out.println("NAME: "+this.name+", AGE: "+this.age+", GENDER: "+this.gender+", ID: "+this.principalID+", EXPERIENCE: "+this.yearsOfExperience);
    }
    public void displayExperience(){
        System.out.println("Experience IS "+this.yearsOfExperience+" years");
    }
}
