/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

/**
 *
 * @author devam
 */
public class Circle implements Shape {
    double radius ;
    public double area(){
        return Math.PI * radius * radius;
    }
    public double perimeter(){
        return 2*Math.PI* radius;
    }
    public Circle(double r){
        this.radius=r;
    }
}
