/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a4p2;
import Classes.*;
import java.util.*;
/**
 *
 * @author devam
 */
public class A4P2 {

    public static void main(String[] args) {
        SavingsAccount sa=new SavingsAccount();
        CheckingAccount ca=new CheckingAccount();
        
        sa.deposit(10.0);
        sa.calculateInterest();
        sa.printDetails();
        ca.deposit(15.0);
        ca.deductFees();
        ca.printDetails();
        
        
    }
}
