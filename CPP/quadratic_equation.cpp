// c++ program to solve quadratic equation using quadratic formuula

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string Firststring = "\n\nEnter the values for quadratic equation\n"
"Format: Ax^2 + Bx + C = 0\n"
"(Note: If the number on RHS of '=' is not 0, subtract it from the C constant on the LHS\n"
"Ex: BEFORE: 1x^2 + 2x + 3 = 4\n"
    "AFTER : 1x^2 + 2x + (3-4) = 0\n"
            "1x^2 + 2x - 1 = 0\n"
            
                "\nOR"
        "(IF NEGATIVE NUMBER)\n\n"
                
  "BEFORE: 1x^2 + 2x + 3 = -4 \n"
    "AFTER : 1x^2 + 2x + (3-(-4) = 0\n"
            "1x^2 + 2x + 7 = 0\n\n"
            
    "Enter the values of A, B, C\n"
    "0 if not present in equation\n\n";

int main() {

    int a, b, c, d;
    float x, y;

    cout<<Firststring<<endl;

    cout<<"A = "<<endl;
    cin>>a;

    cout<<"B = "<<endl;
    cin>>b;

    cout<<"C = "<<endl;
    cin>>c;

    d = b*b - 4*a*c;

    if(d == 0) cout << "The discriminant of the equation is 0, the roots of the equation are real and equal"<<endl;
    else if (d > 0) cout << "The discriminant of the equation is "<< d << ", hence the roots of the equation are real and unequal"<<endl;
    else {
        cout<<"The discriminant of the equation is "<< d << ", hence the roots of the equation are imaginary and do not exist"<<endl;
        return 0;
    }

    float sqrtd = sqrt(d);

    x = (float)(-b + sqrtd)/(2*a);

    y = (float)(-b - sqrtd)/(2*a);

    cout<<"The roots of the equation are "<< x << "and "<< y << endl;
    
    return 0;
}