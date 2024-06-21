/* Devam Desai
IIT2022035 tutorial 5*/

class Student{
int rollNo;
String name;
static String college = "SIET";
static void change(){
college = "IIITA";
}
/**
 *
 * @author devam
 */
Student(int rollNo, String name){
this.rollNo = rollNo;
this.name = name;
}
void display (){
System.out.println(rollNo+" "+name+" "+college);
}
public static void main(String args[]){
Student s1 = new Student (111,"NAME1");
Student s2 = new Student (222,"NAME2");
Student s3 = new Student (333,"NAME3");
Student.change();
// s1.change();
s1.display();
s2.display();
s3.display();
}
}


// static methods are called by the class only. once the student class calls the change method, it is executed for all the objects of student class.
// thus the output is:
//            111 NAME1 IIITA
//            222 NAME2 IIITA
//            333 NAME3 IIITA
