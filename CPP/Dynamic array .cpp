
 #include<bits/stdc++.h>
 using namespace std;
 #define MOD 1000000007
 typedef long long ll;

 class dynamicArray{
   int *data;
   int nextIndex;
   int capacity; //total size
 public:
   dynamicArray()
   {
     data= new int[5];//initial size
     nextIndex=0;
     capacity=5;
   }
   dynamicArray(dynamicArray const &d)
   {
     this->data=new int [d.capacity]; //deep copy
     for(int i=0;i<d.nextIndex;i++)//new array
     {
       this->data[i]=d.data[i];
     }
     this->nextIndex=d.nextIndex;
     this->capacity=d.capacity;

   }

  void operator=(dynamicArray const &d)
  {
    this->data=new int [d.capacity]; //deep copy
    for(int i=0;i<d.nextIndex;i++)//new array
    {
      this->data[i]=d.data[i];
    }
    this->nextIndex=d.nextIndex;
    this->capacity=d.capacity;

  }

   void add(int element)
   {
     if(nextIndex==capacity)
     {
       int *newData=new int[2*capacity];
       for(int i=0;i<capacity;i++)
       {
         newData[i]=data[i];
       }
       delete []data;
       data=newData;//poiting to new array
       capacity*=2;
     }
     data[nextIndex]=element;
     nextIndex++;
   }

   int get(int i) const
   {
     if(i<nextIndex)
     return data[i];
     else
     return -1;
     }

     void add(int i, int element)
     {
        if(i< nextIndex)
       data[i]=element;
       else if(i==nextIndex)
       {
         add(element);
       }
       else
       return;

     }
     void print() const
     {
       for(int i=0;i<nextIndex;i++)
       cout<<data[i]<<" ";
       cout<<endl;
     }

 };
 int main()
 {
   dynamicArray d1;
   d1.add(10);
   d1.add(20);
   d1.add(30);
   d1.add(40);
   d1.add(50);
   d1.add(60);

   d1.print();
   dynamicArray d2(d1);// copy const shallow copy
   d2.print();


   dynamicArray d3;
   d3=d1;// deep  copy we have used operator overloadng
    d1.add(0,100);
    d3.print();


   return 0;
 }
