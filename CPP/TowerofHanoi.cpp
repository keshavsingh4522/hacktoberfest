#include <iostream>
using namespace std;
void toh(int n, char src, char dest, char helper){
    if(n==0){
        return;
 }

    toh(n-1,src,helper,dest);
    cout<<"Moving "<<n<<" frm "<<src<<" to "<<dest<<endl;
    toh(n-1,helper,dest,src);

}

int main(){
int n=3;
char d,s,h;
d='C';
s='A';
h='B';
toh(n,s,d,h);


}