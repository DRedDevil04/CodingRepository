class Vehicle {
void start() {
System.out.println("Vehicle starting...");
}
void stop() {
System.out.println("Vehicle stopping...");
}

}
class Car extends Vehicle {
void start() {
System.out.println("Car starting...");
}
void stop() {
System.out.println("Car stopping...");
}
void drift() {
System.out.println("Car drifting...");
}
}
class Motorcycle extends Vehicle {
void start() {
System.out.println("Motorcycle starting...");
}
void stop() {
System.out.println("Motorcycle stopping...");
}
void wheelie() {
System.out.println("Motorcycle doing a wheelie...");
}
}
public class q2 {
public static void main(String[] args) {
Vehicle vehicle1 = new Car();
Vehicle vehicle2 = new Motorcycle();
vehicle1.start();
vehicle1.stop();
vehicle2.start();
vehicle2.stop();
}
}
/* Because parent class(Vehicle) methods are overridden by child class (Car and Motorcycle ) .
 So when we are calling vehicle1 and vehicle2 ..output we get is of final overrridden method
 and this is the concept of polymorphism
*/
/*  Output is :Car starting...
Car stopping...
Motorcycle starting...
Motorcycle stopping... */ 

// We cannot call drift and wheelie method because here the object is of vechile 
// class pointing to car and motorcycle resp. To call these methods without any error , we have to create 
// object of class car and motorcycle resp.
