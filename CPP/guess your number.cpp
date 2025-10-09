#include <iostream>

using namespace std;
class Guess_Number{
	private:
		int guess=75;
		int askNum;
	public:
		Guess_Number():guess(75),askNum(0){
			
		}
		void Ask_Num(){
			
			cout<<"Enter your guess number"<<endl;
			cin>>askNum;
			
		}
		void comparator(){
			int i=10;
			do{
			
			if (guess < askNum){
			

                  cout << "Your estimate is less" << endl;
				  
				  }

            else if (guess > askNum){
			

                  cout << "Your estimate is more" << endl;
				  
				  }

            else if(guess==askNum){
			
			

                  cout << "Your guess is right! .Congratulations" << endl; break;
				  }
         i--;
        		cout<<"Try again you have "<<i<<" try left"<<endl;
        		Ask_Num();
        	
			
		}
			
		

       while (guess != askNum||i==0);}
       ~Guess_Number(){
	   }
       
		
		
		
};
int main(){
	Guess_Number A;
	A.Ask_Num();
	A.comparator();
	
}
