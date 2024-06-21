/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public class CoffeeMachine {
    public void dispense(Beverage b){
        try{
        b.prepare();
        }
        catch(Exception e){
        System.out.println("Wrong Beverage requested");
    }
    }
    }

