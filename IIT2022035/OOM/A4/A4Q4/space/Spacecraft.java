/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package space;

/**
 *
 * @author devam
 */
public class Spacecraft {
    protected String name;
    protected double fuelCapacity;
    public Spacecraft(String nam,double fuel){
        this.name=nam;
        this.fuelCapacity=fuel;
    }
    public String getName(){
        return this.name;
    }
    public double getFuelCapacity(){
        return this.fuelCapacity;
    }
}
