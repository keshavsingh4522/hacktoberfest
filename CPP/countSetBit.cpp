// This program is used to count the number of set bits(i.e number of occurence of 1 in binary representation of given decimal number)

#include<iostream>
using namespace std;

int main()
{
    int num, original, count = 0;
    cout<<"Enter the decimal number: ";
    cin>>num;
    original = num;
    while(num)
    {
        num = num & (num - 1);
        count++;
    }
    cout<<"Number of set bits in "<<original<<" is: "<<count;
}