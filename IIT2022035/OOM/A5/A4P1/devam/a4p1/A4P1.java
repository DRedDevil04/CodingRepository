/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a4p1;
import Classes.*;
/**
 *
 * @author devam
 */
public class A4P1 {

    public static void main(String[] args) {
        Shape s1=new Circle(4.0);
        Shape s2=new Rectangle(7.0,9.0);
        System.out.println("Circle: Area:"+s1.area()+"\nPerimeter: "+s1.perimeter());
        System.out.println("\nRectangle: Area:"+s2.area()+"\nPerimeter: "+s2.perimeter());
    }
}
