/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package newpackage;

/**
 *
 * @author devam
 */
public class Vehicle {
        String fuelType;
        
        
        public void printFuelType(){
            System.out.println("The fuel type of this vehicle is "+ this.fuelType);
        }
        public void setFuelType(String fuel){
        this.fuelType=fuel;
    }
    public String getFuelType(){
        return this.fuelType;
    }
}
