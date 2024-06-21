/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package space;

/**
 *
 * @author devam
 */
public class Starship extends Spaceship {
    protected double warpSpeed;
    public Starship(String name,double fuel,int crew,double warp){
        super(name,fuel,crew);
        this.warpSpeed=warp;
    }
    public double getWarpSpeed(){
        return this.warpSpeed;
    }
}
