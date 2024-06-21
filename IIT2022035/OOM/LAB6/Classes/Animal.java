/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public abstract class Animal {
    String name ;
    int age;
    String gender;
    public Animal(String name,int age,String gender){
        this.name=name;
        this.age=age;
        this.gender=gender;
    }
    
    
    
    
    public void eat(){};
    public  void  makeSound(){};
}
