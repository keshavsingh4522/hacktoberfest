#include <iostream>
using namespace std;

class rational{
    public: int num,den;
    public:
    rational(int num=0, int den=0){
        this-> num=num;
        this-> den=den;
    }
    friend rational operator+(rational r1, rational r2);
};
rational operator+(rational r1, rational r2){
    rational r3;
    r3.num= (r2.den * r1.num) + (r2.num *r1.den);
    r3.den= r2.den *r1.den ;
    return r3;
}

int main(){
    rational r1(1,2), r2(1,4),r3;
    r3 = r1+r2;
    cout<<"Addition of fractions is : "<<r3.num <<"/"<<r3.den<<endl;
return 0;

}