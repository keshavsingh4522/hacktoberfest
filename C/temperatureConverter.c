//temperature converter from celsius to fahrenheit and kelvin

#include<stdio.h>

int main()   
{   
float fahrenheit, celsius,kelvin;  
celsius = 24;  
fahrenheit =( (celsius*9)/5)+32;
kelvin = celsius + 273.15 ;
printf("Temperature in fahrenheit is:  %f\n",fahrenheit);  
printf("Temperature in kelvin     is:  %f",kelvin); 
return (0); 
} 
