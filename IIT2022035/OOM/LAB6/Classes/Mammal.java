/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public class Mammal extends Animal implements Eater,SoundMaker  {
    String furColor;
    @Override
    public void eat() {
        System.out.println("I am a mammal eating my food");
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
        
    }

    @Override
    public void makeSound() {
            System.out.println("I am a mammal making sound");
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
            
    }
    public Mammal(String name,int age,String gender,String furColor){
        super(name,age,gender);
        this.furColor=furColor;
    }
    
}
