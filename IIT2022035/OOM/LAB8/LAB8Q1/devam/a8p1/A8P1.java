/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a8p1;
import java.util.*;
import Classes.*;
/**
 *
 * @author devam
 */
public class A8P1 {

    public static void main(String[] args) {
        Car c1=new Car();
        Vehicle v1=new Vehicle();
        Vehicle v2=new Car();
        System.out.println("For Car ref and car instance: ");
        c1.start_engine();
        System.out.println("For Vehicle ref and vehicle instance: ");
        v1.start_engine();
        System.out.println("For vehicle ref and car instance: ");
        v2.start_engine();
        
    }
}
