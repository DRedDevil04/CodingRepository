/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public class Reptile extends Animal implements Eater {
    String scaleColor;

    @Override
    public void eat() {
            System.out.println("I am a reptile eating my food");
//        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
    public Reptile(String name,int age,String gender,String scaleColor){
        super(name,age,gender);
        this.scaleColor=scaleColor;
    }
    
    
    
}
