/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package newpackage;

/**
 *
 * @author devam
 */
public class Motorcycle extends Vehicle{
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
    public void printDetails(){
        System.out.println("\nFuel-Type: "+this.fuelType+"\nSide-Car: "+((this.hasSidecar)?"YES\n":"NO\n"));
    }
}

