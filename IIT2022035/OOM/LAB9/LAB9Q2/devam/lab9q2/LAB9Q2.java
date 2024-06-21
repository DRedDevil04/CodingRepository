/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.lab9q2;
import Classes.*;
/**
 *
 * @author devam
 */
public class LAB9Q2 {

    public static void main(String[] args) {
        Beverage b1=new Coffee();
        Beverage b2=new Tea();
        Beverage b3=new LemonTea();
        CoffeeMachine c1=new CoffeeMachine();
        c1.dispense(b1);
        c1.dispense(b2);
        c1.dispense(b3);
        
        
    }
}
