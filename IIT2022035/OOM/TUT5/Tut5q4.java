/*Devam Desai 
IIT2022035 Tutorial 5*/


class Animal {

    public void announce() {
        System.out.println("Class Animal has been called");
    }

}

class Dog extends Animal {

    public void announce() {
        System.out.println("Class dog has been called");
    }

}

class PuppyDog extends Dog {
    PuppyDog() {
    }
}
/**
 *
 * @author devam
 */
public class Tut5q4 {
    public static void main(String[] args) {
        PuppyDog p = new PuppyDog();
        p.announce();
    }

    /* the method announce had been overridden in the Dog class, thats why the announce method of Dog class is displayed as output.*/
}