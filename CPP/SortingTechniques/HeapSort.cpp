#include <iostream>
using namespace std;
class heap1{
public:
	void accept();
	void MAX_HEAPIFY(int a[],int,int);
	void BUILD_MAX_HEAP(int a[],int);
	void HEAPSORT(int a[],int);
	void display(int a[],int );
};
void heap1 :: MAX_HEAPIFY(int a[], int i, int n)
{
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
       largest=l;
    else
       largest=i;
    if((r<=n)&&(a[r]>a[largest]))
       largest=r;
    if(largest!=i)
    {
         loc=a[i];
         a[i]=a[largest];
         a[largest]=loc;
         MAX_HEAPIFY(a, largest,n);
    }
}
void heap1 :: BUILD_MAX_HEAP(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        MAX_HEAPIFY(a, k, n);
    }
}
void heap1 :: HEAPSORT(int a[], int n)
{

    BUILD_MAX_HEAP(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MAX_HEAPIFY(a, 1, i - 1);
    }
}

void heap1::accept(){
	int n;
	    cout<<"Enter the number of students"<<endl;
	    cin>>n;
	    int a[n];
	    cout<<"Enter the marks of the students "<<endl;
	    for (int i = 1; i <= n; i++)
	    {
	        cin>>a[i];
	    }
	    HEAPSORT(a, n);
	    display(a,n);
}
void heap1::display(int a[],int n){

      cout<<":::::::SORTED MARKS::::::"<<endl;

	    for (int i = 1; i <= n; i++)
	    {
	        cout<<a[i]<<endl;
	    }
	cout<<"Minimum marks obtained are:"<<a[1];
	cout<<"\nMaximum marks obtained are:"<<a[n];

}
int main()
{
   	heap1 h;
	h.accept();
	return 0;
}
