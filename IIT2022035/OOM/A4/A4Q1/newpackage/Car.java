/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package newpackage;

/**
 *
 * @author devam
 */
public class Car extends Vehicle{
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
    public void printDetails(){
        System.out.println("\nCar Model: "+this.carModel+"\nFuel-Type: "+this.fuelType+"\nDoors: "+this.numDoors);
    }
    
}
