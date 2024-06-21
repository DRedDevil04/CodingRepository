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
    String name;
    int age;
    public abstract void speak();
    void eat(){
        System.out.println("Animal is Eating\n");
    }
    Animal(String name,int age){
        this.name= name;
        this.age=age;
    }
}
