#include <iostream>
using namespace std;

void move(int disks,char first,char second,char third)
{
    if(disks==0)
    return;

    if(disks==1)
      cout<<"shift disk "<<disks<<" from "<<first<<" to "<<third<<endl;

    //move n-1 disks from A to B
    move(disks-1,first,third,second);

    cout<<"shift disk "<<disks<<" from "<<first<<" to "<<second<<endl;

    //move n-1 disks from B to C
    move(disks-1,second,first,third);
    //cout<<"shift disk"<<disks<<"from"<<second<<"to"<<third<<endl;
    
}

int main() {
  int disks;
  cin>>disks;

  move(disks,'A','B','C');
}
