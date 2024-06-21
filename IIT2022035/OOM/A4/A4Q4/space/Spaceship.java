/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package space;

/**
 *
 * @author devam
 */
public class Spaceship extends Spacecraft {
    protected int crewSize;
    public Spaceship(String name, double fuelCapacity,int crewSize){
        super(name,fuelCapacity);
        this.crewSize=crewSize;
    }
    public int getCrewSize(){
        return this.crewSize;
    }
}
