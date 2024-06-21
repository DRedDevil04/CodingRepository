/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.ques2;

/**
 *
 * @author devam
 */

class Parent {
// TODO: Add the appropriate access modifier for the following field
private int age;
// TODO: Add the appropriate access modifier for the constructor
public Parent(int age) {
this.age = age;
}
// TODO: Add the appropriate access modifier for the method
protected void displayInfo() {

System.out.println("Age: " + this.getAge());
}
protected int getAge(){
    return this.age;
}

}
public class Ques2 {
public static void main(String[] args) {
Parent parent = new Parent(35);
parent.displayInfo();
}
}
