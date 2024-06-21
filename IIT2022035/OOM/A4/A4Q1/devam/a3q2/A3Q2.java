/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a3q2;
import newpackage.*;
import java.util.*;
/**
 *
 * @author devam
 */
public class A3Q2 {

    public static void main(String[] args) {
       Car c1=new Car("Safari","Diesel",4);
       Motorcycle m1=new Motorcycle("Petrol",false);
       
       c1.printDetails();
       m1.printDetails();
       System.out.println("After changing : \n");
       m1.setSidecar(true);
       c1.setCarModel("Safari Storme");
       c1.setNumDoors(5);
       c1.printDetails();
       m1.printDetails();
       System.out.println("\nGetting name of car: "+ c1.getCarModel());
       
    }
}


