class Animal {
    void makeSound() {
    System.out.println("Animal makes a sound");
    }
    }
     class Dog extends Animal {
    void makeSound() {
    System.out.println("Dog barks");
    }
    }
    public class q1 {
    public static void main(String[] args) {
    Animal myPet = new Dog();
    myPet.makeSound();
    }
    }
//OUTPUT: Dog barks
/* Because parent class(Animal) methods are overridden by child class (Dog ) .
 So when we are calling myPet ..output we get is of final overrridden method
 and this is the concept of polymorphism
*/