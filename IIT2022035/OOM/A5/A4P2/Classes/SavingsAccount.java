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
public class SavingsAccount implements BankAccount {
        double balance;
        double roi;
        public void deposit(double amount){
            this.balance += amount;
        }
        public void withdraw(double amount){
            this.balance -= amount;
        }
        public SavingsAccount(){
            Scanner s=new Scanner(System.in);
            System.out.println("Enter balance and interest rate: ");
            this.balance=s.nextDouble();
            this.roi=s.nextDouble();      
        }
        public void calculateInterest(){
             this.balance+=(this.roi * this.balance)/100;
        }
        public void printDetails(){
            System.out.println("\nBalance of Savings is now: $"+ this.balance);
        }
}
