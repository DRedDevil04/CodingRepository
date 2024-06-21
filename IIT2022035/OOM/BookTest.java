/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.BookTest;

/**
 *
 * @author devam
 */
public class BookTest {

    public static void main(String[] args) {
        Book b1=new Book();
        Book b2=new Book("Game of Thrones","GRR Martin",1996,500);
        System.out.println("Book 1 : \n");
        b1.displayDetails();
        System.out.println("Book 2 : \n");
        b2.displayDetails();
    }
}
class Book{
    String title;
    String author;
    int yearPublished;
    double price;
    
    
    public Book(){
        this.title="GOAT";
        this.author="Devam Desai";
        this.yearPublished=2020;
        this.price=300;
    }
    public Book(String title,String author, int yearPublished,double price){
        this.title=title;
        this.author=author;
        this.yearPublished=yearPublished;
        this.price=price;
    }
    public void displayDetails(){
        System.out.println("\nThe book is "+this.title+" written by "+this.author+". It was published in "+this.yearPublished+ " and it costs Rs."+this.price);
    }
     
}
