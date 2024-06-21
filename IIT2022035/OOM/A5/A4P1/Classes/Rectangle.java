/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public class Rectangle implements Shape {
    double length ;
    double width;
    public double area(){
        return  length * width;
    }
    public double perimeter(){
        return 2*(length+width);
    }
    public Rectangle(double len,double wid){
        this.length=len;
        this.width=wid;
    }
    
}
