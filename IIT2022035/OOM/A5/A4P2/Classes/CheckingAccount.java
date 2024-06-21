/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

import java.util.Scanner;

/**
 *
 * @author devam
 */
public class CheckingAccount implements BankAccount {
     double balance;
        double fee;
        public void deposit(double amount){
            this.balance += amount;
        }
        public void withdraw(double amount){
            this.balance -= amount;
        }
        public CheckingAccount(){
            Scanner s=new Scanner(System.in);
            System.out.println("\nEnter balance and fee: ");
            this.balance=s.nextDouble();
            this.fee=s.nextDouble();      
        }
        public void deductFees(){
             this.balance-=this.fee;
        }
        public void printDetails(){
            System.out.println("\nBalance of Checking is now: $"+ this.balance);
        }
}
