/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package peopleclasses2;

/**
 *
 * @author devam
 */
public class Student extends Person {
    int studentID;
    int batch;
    public void displayStudInfo(){
        System.out.println("NAME: "+this.name+", AGE: "+this.age+", ID: "+this.studentID+", Batch: "+this.batch);
    }
    public int getAge(){
        return this.age;
    }
}
