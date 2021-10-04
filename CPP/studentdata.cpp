// Student Data Mangament
#include<iostream>
#include<conio.h>

class college {

    public :
    int clgcode;
    char cname[50];
    public :

    int getcollege(){

      std::cout<<"Enter the College name :";
      std::cin>>"cname";
      std::cout<<"Enter the college code :";
      std::cin>>clgcode;

      return 0 ;
    }
};



class student : public college
{

 int rollno;
 char name [50];
 public:
 int  getdata()
 {std::cout<<"Enter the name of student : ";
     std::cin>>name;

     std::cout<<"Enter your rollno : ";

     std::cin>>"rollno";

return 0;
     }

 int display()
  {
      std::cout<<"\nDetails of Student";
       std::cout<<"\nCollege name:"<<cname;
       std::cout<<"\ncollege code :"<<clgcode;

      std::cout<<"\nroll no : "<<rollno;
      std::cout<<"\nName : "<<name;

return 0;
  }
};

int main(int argc, char const *argv[])
{

student a;
a.getcollege();
a.getdata();
system("cls");
a.display();
getch();
return 0;
}
