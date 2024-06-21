/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;
import java.util.*;
/**
 *
 * @author devam
 */
public class ZooClass {
    private ArrayList<Animal> A1=new ArrayList<Animal>();
//    private LinkedList<Animal> A1=new LinkedList();
    public void addAnimal(Mammal a){
        A1.add(a);
    }
    public void addAnimal(Reptile a){
        A1.add(a);
    }
    public void addAnimal(Bird a){
        A1.add(a);
    }
    public void performDailyActivities(){
        for(int i=0;i<A1.size();i++){
            Animal t=A1.get(i);
            try{
                t.eat();
            }
            catch(Exception e){
                ;
            }
            try{
                t.makeSound();
            }
            catch(Exception e){
                ;
            }
        }
    }
}
