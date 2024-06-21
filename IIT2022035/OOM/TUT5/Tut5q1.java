/*Devam Desai
IIT2022035 Tutorial 5*/

interface Animal{
    void eat();
    void sleep();
}

interface Dog{
    void bark();
    void wagTail();
}

class PuppyDog implements Animal, Dog{
    @Override
    public void eat(){
        System.out.println("Puppy is eating.");
    }

    public void sleep(){
        System.out.println("Puppy is sleeping.");
    }

    public void bark(){
        System.out.println("Puppy is barking.");
    }

    public void wagTail(){
        System.out.println("Puppy is wagging its tail.");
    }
}
/**
 *
 * @author devam
 */
public class Tut5q1{
    public static void main(String[] args){
        PuppyDog p = new PuppyDog();
        p.eat();
        p.sleep();
        p.bark();
        p.wagTail();
    }
}