//IIT2022035 Devam Desai 
//DAA Assignment Q5



#include<bits/stdc++.h>
using namespace std;


bool isPythagorean(int a, int b, int c) {
    int d=max(a,max(b,c));
    if(d==a) return (b*b + c*c == a*a);
    if(d==b) return (c*c + a*a == b*b);
    if(d==c) return (a*a + b*b == c*c);
    
}

bool isNearlyPythagorean(int a, int b, int c) {
    int d=max(a,max(b,c));
    if(d==a) return abs(b*b + c*c - a*a) <=1;
    if(d==b) return abs(c*c + a*a - b*b) <=1;
    if(d==c) return abs(a*a + b*b - c*c) <=1;

}


int main(){
    int nums=81517;
    bool flag=false;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            if(i==3 && j==2) continue;
            int a = nums / int(pow(10, 5 - i));
            int b = (nums / int(pow(10, 5 - i - j))) % (int(pow(10,j)));
            int c = nums % int(pow(10, 5 - i - j));
            cout<<"The Partition Formed Is"<<endl;
            cout << a << " " << b << " " << c << endl;

    
            
            if (isPythagorean(a, b, c)) { 
                cout << "Pythagorean triplet found: " << a << ", " << b << ", " << c << endl;
                cout<<endl;
                flag=true;
            }
            else if (isNearlyPythagorean(a, b, c))  {
               cout << "Nearly Pythagorean triplet found: " << a << ", " << b << ", " << c << endl;
               cout<<endl;
                flag=true;
            }
        }
    }

    if(!flag) cout << "No Pythagorean OR Nearly Pythagorean triplets found" << endl;
    


    return 0;
}