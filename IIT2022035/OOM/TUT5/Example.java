/*

Devam Desai
IIT2022035 Tutorial 5


*/



class Bike{
int val=5;
void run(){System.out.println("running");}
}
class Splendor extends Bike{
int val = 10;
void run(){System.out.println("running safely with 60km");}
}
/**
 *
 * @author devam
 */
class Example {
public static void main(String args[]){
Bike a = new Bike();
Bike b = new Splendor();
Splendor c = new Splendor();
a.run();
System.out.println(a.val);
b.run();
System.out.println(b.val);
c.run();
System.out.println(c.val);
}
}
// the attributes are not overridden but the methods are.