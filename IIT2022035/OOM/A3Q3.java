/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a3q3;

/**
 *
 * @author devam
 */
public class A3Q3 {

    public static void main(String[] args) {
        MountainBike mb1=new MountainBike(3,30,30);
        System.out.println("\nGear: "+mb1.gear+"\nSpeed: "+mb1.speed+"\nSeat Height: "+mb1.getSeatHeight());
        mb1.incrementSpeed(5);
        mb1.setSeatHeight(70);
        System.out.println("\n\nAfter Changing : \n");
        System.out.println("\nGear: "+mb1.gear+"\nSpeed: "+mb1.speed+"\nSeat Height: "+mb1.getSeatHeight());
    }
}
class Bicycle{
    int gear;
    int speed;
    Bicycle(int g,int v){
        this.gear=g;
        this.speed=v;
    }
    void incrementSpeed(int diff){
        //accepts =ve and -ve vals
        this.speed+=diff;
    }
    void decrementSpeed(int diff){
        //accepts =ve and -ve vals
        this.speed-=diff;
    }
}

class MountainBike extends Bicycle {
    private int seatHeight;

    public MountainBike(int g, int v,int sh) {
        super(g, v);
        this.seatHeight=sh;
    }
    void setSeatHeight(int sh){
        this.seatHeight=sh;
            
    }
    int getSeatHeight(){
        return this.seatHeight;
    }
    
    
}
