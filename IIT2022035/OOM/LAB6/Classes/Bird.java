/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public class Bird extends Animal implements Eater,SoundMaker {
    double wingSpan;

    @Override
    public void eat() {
        System.out.println("I am a bird eating my food");
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    @Override
    public void makeSound() {
        System.out.println("I am a bird making sound");
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
    public Bird(String name, int age,String gender,double wingspan){
        super (name,age,gender);
        this.wingSpan=wingspan;
    }
    
}
