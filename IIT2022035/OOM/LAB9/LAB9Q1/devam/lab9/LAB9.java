/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.lab9;

/**
 *
 * @author devam
 */
class Animal{
void eat(){
System.out.println("Animals Eat");
} }
class herbivores extends Animal{
void eat()
{ System.out.println("Herbivores Eat Plants");
} }
class omnivores extends Animal{
void eat(){
System.out.println("Omnivores Eat Plants and meat"); } }
class carnivores extends Animal{
void eat(){
System.out.println("Carnivores Eat meat"); } }
public class LAB9{ public static void main(String args[])
{
Animal a1= new Animal();
Animal a2= new herbivores();
Animal a3= new omnivores();
Animal a4= new carnivores();
a1.eat();
a2.eat();
a3.eat();
a4.eat();

} }