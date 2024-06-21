/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a4q4;
import space.*;
/**
 *
 * @author devam
 */
public class A4Q4 {

    public static void main(String[] args) {
            Starship s1=new Starship("Pegasus",10000.0,10,30000.0);
            System.out.println("Name : "+ s1.getName()+"\nFuel: "+s1.getFuelCapacity()+"\nCrew-Size: "+s1.getCrewSize()+"\nWarp Speed: "+s1.getWarpSpeed());
            
    }
}
