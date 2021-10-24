/*
                   ---Backtracking problem---
The winner of a television show contest was awarded the opportunity
to spend a large amount of money on a list of items from a selection
of products in one of the stores of a hypermarket chain. However,
the contest rules impose that a maximum of one item of each product and,
in total, at least M items are selected.
To make the best possible use of the prize, the lucky winner decided to assess
how many ways she could choose the items using the prize value and set to the laborious
task of browsing the stores to collect the prices of all the products available.

---INPUT ESPECIFICATION---
The input consists of several test cases corresponding to the survey of several stores
The first line of input contains an integer K corresponding to the number of cases, followed by a blank line.
Then we have the cases, each case in the following format:
L
P[0] P[1] ... P[L-1]
M Q
//Blank space
Where
L = number of items available 0 <L <31
P[j] = price of item j
M = smallest number of items that can be chosen
Q = maximum amount that can be spent

---OUTPUT ESPECIFICATION---
For each case C=0,...,K-1, a line must be printed in the form
case C:R
Where

R = total number of possible ways to form a purchase at the maximum value Q of the prize,
choosing at least M items, with a maximum of one unit of each type, among the available items.
*/


//SOLUTION ==>
#include <iostream>
#define TAM_MAX 33

using namespace std;



void backtrack(int aux, int accumulates);

int P[TAM_MAX], combinations=0, product=0, L, M, Q;

int main(){
    int K; 
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>L;
        for(int j=0;j<L;j++){
            cin>>P[j];
        }
        cin>>M;
        if(M==0){
            combinations++;
        }
        cin>>Q;
        backtrack(0, 0);
        product=0;
        cout<<"case "<<i<<": "<<combinations<<endl;

        combinations=0; 
    }

    return 0;
}

void backtrack(int aux, int accumulates){
    if(L!=aux){
        if(accumulates + P[aux]<=Q){
            product++;
            if(product>=M){
                combinations++;
            }    
            backtrack(aux+1, accumulates+P[aux]);product--;    
        }
    }
    else{
        return;
    }
    backtrack(aux+1, accumulates);
}