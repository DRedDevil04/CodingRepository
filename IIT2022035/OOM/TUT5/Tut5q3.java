/*Devam Desai
IIT2022035 Tutorial 5*/
import java.util.*;

abstract class Shape {
    abstract double area();
    abstract double perimeter();
}

class Circle{
    double radius;
    String color;

    Circle(double radius, String color){
        this.radius = radius;
        this.color = color;
    }

    double area(){
        return Math.PI*radius*radius;
    }

    double perimeter(){
        return 2*Math.PI*radius;
    }
}

class Rectangle extends Shape{
    double length;
    double breadth;
    String color;

    public Rectangle(double length, double breadth, String color){
        this.length = length;
        this.breadth = breadth;
        this.color = color;
    }

    public double area(){
        return length*breadth;
    }

    public double perimeter(){
        return 2*(length+breadth);
    }
}

class Square extends Shape{
    double side;
    String color;

    public Square(double side, String color){
        this.side = side;
        this.color = color;
    }

    public double area(){
        return side*side;
    }

    public double perimeter(){
        return 4*side;
    }
}
/**
 *
 * @author devam
 */
public class Tut5q3{
    public static void main(String[] args){
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter color of circle: ");
        String color = sc.nextLine();
        System.out.println("Enter radius: ");
        double radius = sc.nextDouble();
        
        Circle c = new Circle(radius, color);
        System.out.println("Circle Color: " + c.color);
        System.out.println("Circle area: " + c.area());
        System.out.println("Circle perimeter: " + c.perimeter());

        System.out.println("Enter color of rectangle: ");
        color = sc.nextLine();
        color = sc.nextLine();
        System.out.println("Enter length and breadth of rectangle: ");
        double length = sc.nextDouble();
        double breadth = sc.nextDouble();
        Rectangle r = new Rectangle(length, breadth, color);
        System.out.println("Rectangle Color: " + r.color);
        System.out.println("Rectangle area: " + r.area());
        System.out.println("Rectangle perimeter: " + r.perimeter());

        System.out.println("Enter color of square: ");
        color = sc.nextLine();
        color = sc.nextLine();
        System.out.println("Enter side of square: ");
        double side = sc.nextDouble();
        Square s = new Square(side, color);
        System.out.println("Rectangle Color: " + s.color);
        System.out.println("Square area: " + s.area());
        System.out.println("Square perimeter: " + s.perimeter());

        sc.close();
    }
}


