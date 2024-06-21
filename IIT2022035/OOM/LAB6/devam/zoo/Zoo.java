/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.zoo;
import Classes.*;
/**
 *
 * @author devam
 */
public class Zoo {

    public static void main(String[] args) {
       ZooClass Z=new ZooClass();
       Bird b=new Bird("Devam",18,"Male",5);
       Reptile r=new Reptile("Rishi",19,"Male","Brown");
       Mammal m=new Mammal("Nijval",19,"Female","Black");
       Z.addAnimal(b);
       Z.addAnimal(m);
       Z.addAnimal(r);
       Z.performDailyActivities();
    }
}
