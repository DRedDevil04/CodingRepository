class devam {
    public static void main(String[] args) {
        String s=new String("Devam");
        Employee emp1=new Employee(s,3,47,7,60,7000,10,1000);
        System.out.println("Salary is "+(emp1.findSalary()));
    }
}
class Employee{
        String name=new String();
        int type;
        int work_hours;
        int overtime;
        int sales;
        int base;
        int perc;
        int overpay;


public Employee(String nam,int typ,int work_hours,int overtime,int sales,int base,int perc,int overpay){
        this.name=nam;
        this.type=typ;
        this.work_hours=work_hours;
        this.overtime=overtime;
        this.sales=sales;
        this.base=base;
        this.perc=perc;
        this.overpay=overpay;

}
int findSalary(){
        int sal=0;
        switch(type){

        case 1:
                sal=sal+base;
                break;
        case 2:
             sal=sal+base;
                sal=sal+((overpay)*(overtime));
                break;
        case 3:
                sal=sal+((perc*sales)/100);
                break;
        case 4:
                sal=sal+((perc*sales)/100);
                sal=sal+(base);
                break;
        default:  
                return 0;
}
        return sal; 

}

        
        
        
}
        
        
        

