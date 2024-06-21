/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package devam.a4q2;

/**
 *
 * @author devam
 */
public class A4Q2
{
    
    public static double calculateAverageHeight(Student[] students) {
        if (students.length == 0) {
            return 0.0;
        }

        double totalHeight = 0.0;
        for (Student student : students) {
            totalHeight += student.height;
        }
        return totalHeight / students.length;
    }

    public static void main(String[] args) {
        Student[] students = new Student[3];
        students[0] = new Student(035, 182.5);
        students[1] = new Student(036, 185.0);
        students[2] = new Student(033, 190.0);

        System.out.println("Student Details:");
        for (Student student : students) {
            student.displayDetails();
            System.out.println();
        }

        double averageHeight = calculateAverageHeight(students);
        System.out.println("Average Height of Students: " + averageHeight + " cm");
    }
}
class Student{
    int rollno;
    double height;

    public Student(int rollno, double height)
    {
        this.rollno = rollno;
        this.height = height;
    }

    public void displayDetails()
    {
        System.out.println("The roll number of the student is : " + rollno);
        System.out.println("The height of the student is : " + height);
    }

}

