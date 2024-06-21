/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a3q2;
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


class Vehicle{
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
class Car extends Vehicle{
    private int numDoors;
    private String carModel;
    public void setNumDoors(int numDoor){
        this.numDoors=numDoor;
    }
    public int getNumDoors(){
        return this.numDoors;
    }
    public void setCarModel(String model){
        this.carModel=model;
    }
    public String getCarModel(){
        return this.carModel;
    }
    public Car(String model,String fuel,int doors){
        this.carModel=model;
        this.fuelType=fuel;
        this.numDoors=doors;
    }
    void printDetails(){
        System.out.println("\nCar Model: "+this.carModel+"\nFuel-Type: "+this.fuelType+"\nDoors: "+this.numDoors);
    }
    
}
class Motorcycle extends Vehicle{
    private boolean hasSidecar;
    
    public void setSidecar(boolean sidecar){
        this.hasSidecar=sidecar;
    }
    public boolean getSidecar(){
        return this.hasSidecar;
    }
    
    public Motorcycle(String fuel,boolean sidecar){   
        this.fuelType=fuel;
        this.hasSidecar=sidecar;
    }
    void printDetails(){
        System.out.println("\nFuel-Type: "+this.fuelType+"\nSide-Car: "+((this.hasSidecar)?"YES\n":"NO\n"));
    }
}
