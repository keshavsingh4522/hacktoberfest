{
    float a,b,c,disc,root1,root2,real,img;
    printf("Enter the value of a,b,c:\n");
    scanf("%f%f%f",&a,&b,&c);
    if((a==0)&&(b==0)){
        printf("Roots cannot be determined\n");
    }else if(a==0){
        printf("Linear equation\n");
        root1=-c/b;
        printf("Root 1 = %f",root1);
    }
    else{
        disc=(b*b)-(4*a*c);
        if (disc==0){
            printf("The roots are real and equal\n");
            root1=root2=-b/(2*a);
            printf("Root 1 = %f\n Root2 = %f\n",root1,root2);
        }else if(disc>0){
            printf("The roots are real and distinct\n");
            root1=(-b+sqrt(disc))/2*a;
            root2=(-b-sqrt(disc))/2*a;
            printf("Root 1 = %.3f\n Root2 = %.3f\n",root1,root2);
        }else{
            printf("The roots are imaginary");
            real=-b/(2*a);
            img =sqrt(fabs(disc))/(2*a);
            printf("Root 1 = %.3f + %.3fi\n Root 2 = %.3f+ %.3fi\n",real,img,real,img);
        }
    }
}