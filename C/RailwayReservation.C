#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*******************************************GLOBAL VARIABLES**********************************************************/
//ALl the globle variables and the composite data types will be declared here
// Global variables
char source[20], des[20], train[40];
char station[40], cla[40];
int time1, time2, a[55];
int j;

struct pd
{
	char val[20],name[20],gen[6],gender[6];
	int ag,age,d,m,year;
	double Ph_no,Phno,UID;
	int train_num;
	int num_of_seats,RID;
}passdetails,pd1;

struct billpay
{
	int bill_amt;
	int RID1;	
}bp;
 
/*******************************************FUNCTION PROTOTYPE**********************************************************/
									//function prototypes to be used	
									
void details(void); 										//main reservation function
void details1(int);										//main reservation function				
int seat(int);
int cal(int, int, int);
void bill(); 
void viewdetails(void);												//view details of all the trains
void specifictrain(void);											//print data related to specific train	
void login();
void cancel(void);	
void search(void);
int getUniqueID();  
					

/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MAIN()*************************************************/
int main()

{
	system("cls"); 
	printf("\n\n\n\n\t\t\t\t\t\t=================================================\n");
	printf("\t\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t\t|        -----------------------------          |\n");
	printf("\t\t\t\t\t\t|           TRAIN TICKET RESV. SYSTEM           |\n");
	printf("\t\t\t\t\t\t|        -----------------------------          |\n");
	printf("\t\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t\t\t\t\t|           |  	  SOUL CYNICS     |             |\n");
	printf("\t\t\t\t\t\t|                                               |\n");
	printf("\t\t\t\t\t\t=================================================\n\n\n");
		
	    
	printf(" \n\t\t\t\t Press any key to continue:");
	getch();	
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n\n\n\n\n\n \t \t \t \t \t \t=================================\n");
	printf("\t \t \t \t \t \t    TRAIN RESERVATION SYSTEM");
	printf("\n \t \t \t \t \t \t =================================");
	printf("\n \t \t \t \t \t \t 1>> Reservation Menu");
	printf("\n \t \t \t \t \t \t ------------------------");
	printf("\n \t \t \t \t \t \t 2>> Print The Bill/Receipt OF The Reservation");
	printf("\n \t \t \t \t \t \t ------------------------");
	printf("\n \t \t \t \t \t \t 3>> View Specific Train");
	printf("\n \t \t \t \t \t \t------------------------");
	printf("\n \t \t \t \t \t \t 4>> View All Available Trains");
	printf("\n \t \t \t \t \t \t ------------------------");
	printf("\n \t \t \t \t \t \t 5>> Cancel Reservation");
	printf("\n \t \t \t \t \t \t ------------------------");
	printf("\n \t \t \t \t \t \t 6>> Search For Passenger Detail");
	printf("\n \t \t \t \t \t \t ------------------------");
	printf("\n \t \t \t \t \t \t 7>> Exit");
	printf("\n \t \t \t \t \t \t------------------------");
	printf("\n\n \t \t \t \t \t \t -->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			details();		
			break;
		case 2:
			 bill();
			 break;
		case 3:
			specifictrain();
			printf("\n\n\t\t\t\t\t\tPress any key to go to Main Menu..");
			getch();
			break;
		case 4:
			viewdetails();
			printf("\n\n\t\t\t\t\t\tPress any key to go to Main Menu..");
			getch();
			break;
		case 5:
			cancel();
			printf("\n\n\t\t\t\t\t\tPress any key to go to Main Menu..");
			getch();
			break;
		case 6:
			search();
			printf("\n\n\t\t\t\t\t\tPress any key to go to Main Menu..");
			getch();
			break;
		case 7:
			printf("\t\t\t\t\t\t");
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

/*********************************************RESERVATION()*************************************************/

/*********************************************Adding Details Of The Passengers()*************************************************/


void details()
{
	FILE *fp,*fq;
	fp=fopen("Railway_Reservation.txt","a+");
	if(fp==NULL)
	{
	   puts("File cannot be opened ");
	   exit(0);
	}
	fq=fopen("Railway_Reservation1.txt","a+");
    if (fq==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	int i,ag,m,year,d;
	double Phno,UID;
	int train_num;
    int a1, a2, b, c,RID; 
	int x = 0,  e, r;
    char o, gen[6], confirm,another;
    char val[20], gender[6];
	system("cls");
	printf("\t\t\t\t\t\tEnter Number Of Passengers: ");
	fflush(stdin);
    scanf("%d", &j);
	another='y';
	while(another=='y'|| another=='Y')
	{
        printf("\n\t\t\t\t\t\tEnter the Name of Passenger: ");
        fflush(stdin);
        gets(passdetails.val);
        printf("\n\t\t\t\t\t\tEnter the Gender of Passenger(Male/Female): ");
        fflush(stdin);
        gets(passdetails.gender);
        printf("\n\t\t\t\t\t\tEnter the Age of Passenger: ");
        fflush(stdin);
        scanf("%d",&passdetails.ag);
        printf("\n\t\t\t\t\t\tEnter the Phone number of Passenger: ");
        fflush(stdin);
        scanf("%lf",&passdetails.Phno);
        printf("\n\t\t\t\t\t\tEnter the date of reservation(dd/mm/yy): ");
        fflush(stdin);
    	scanf("%d/%d/%d",&passdetails.d,&passdetails.m,&passdetails.year);
        printf("\n\t\t\t\t\t\tPlease enter Unique ID(Citizenship Number/ Passport Number) of Passenger: ");
        fflush(stdin);
        scanf("%lf", &passdetails.UID);
        printf("\n\t\t\t\t\t\tReceipt Id: ");
        fflush(stdin);
        scanf("%d",&passdetails.RID);
        fwrite(&passdetails,sizeof(passdetails),1,fp);
        printf("\n\t\t\t\t\t\tAdd another Record(y/n)-: ");
	 	another=getche();
	}
	bp.RID1 = passdetails.RID;
	printf("\n\n\t\t\t\t\t\t>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();
	label:
	printf("\n\n\t\t\t\t\t\tEnter train number:> ");
	scanf("%d",&train_num);
	do {
        switch(train_num) 
		{
        case 1001:
		 {
            
            a1 = 2099;
            a2 = 1560;
            // Calling cal() function
            // with the three argument
            // and return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d \n",d); 
        }break;
        case 1002:
		 {
            
            a1 = 2099;
            a2 = 1560;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d \n",d);
        } break;
        case 1003:
		 {
            
            a1 = 1801;
            a2 = 981;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d);
        } break;
        case 1004:
		 {
        
           	a1 = 1801;
            a2 = 981;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d);
        } break;
        case 1005:
		 {
        
            a1 = 2199;
            a2 = 1780;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d);
        } break;
        case 1006:
		 {
    
            a1 = 2199;
            a2 = 1780;
  	
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d);
        } break;
        case 1007: 
		{
            a1 = 1759;
            a2 = 1200;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d); 
        } break;
        case 1008:
		 {
            a1 = 1759;
            a2 = 1200;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d); 
        } break;
        case 1009: 
		{
            a1 = 2205;
            a2 = 1905;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d);
        } break;
        case 1010:
		 {
           	a1 = 2205;
            a2 = 1905;
  
            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            printf("\t\t\t\t\t\tTotal Bill Amount: Rs %d\n", d);
        } break;
        default:
            printf("\t\t\t\t\t\tPlease Enter The Correct Choice.....\n");
        	goto label;
        }
    } while (x);
    bp.bill_amt=d;
	//fseek(fq,0, SEEK_END);
    fwrite(&bp,sizeof(bp),1,fq);
    printf("\n\t\t\t\t\t\t*****For Booking Seats*****\n");
    // Calling seat() function with number of passenger
    seat(j);
    printf("\n\n\t\t\t\t\t\tConfirm Reservation (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("\t\t\t\t\t\t==================");
		printf("\n\t\t\t\t\t\t Reservation Done\n");
		printf("\t\t\t\t\t\t==================");
		printf("\n\t\t\t\t\t\tPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\n\t\t\t\t\t\tReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\n\t\t\t\t\t\tInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	fclose(fq);
	getch();
}


/*********************************************PRINTTICKET()*************************************************/
										// Code for printing receipt
void bill()
{
    char confirm;
    long int recsize,recsize1;
    time_t currentTime;
    time(&currentTime);
    int i,c,reID,x;
    FILE *fp,*fq;
	fp=fopen("Railway_Reservation.txt","r+");
	if(fp==NULL)
	{
	   puts("File cannot be opened ");
	   exit(0);
	}
	fq=fopen("Railway_Reservation1.txt","r+");
    if (fq==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	system("cls");
	
	recsize=sizeof(passdetails);
	
	recsize1=sizeof(bp);
	//fseek(fp,0, SEEK_END);
	//fseek(fq,0, SEEK_END);
	top5:
		
	printf("\n\n\t\t\t\t\t\tEnter the receipt ID of passenger: ");
	fflush(stdin);
	scanf("%d",&reID);
	
	rewind(fp);
	rewind(fq);
    printf("\n\n\t\t\t\t\t\t*********************** YOUR RECEIPT ****************************");
    
	while(fread(&passdetails,recsize,1,fp)>0)
	{
		if(reID == passdetails.RID)
		{
			x=1;
    		printf("\n\n\t\t\t\t\t\tPassenger Name: ");
    		puts(passdetails.val);
    		printf("\n\t\t\t\t\t\tPassenger Gender: ");
    		puts(passdetails.gender);
    		printf("\n\t\t\t\t\t\tPassenger Age: %d",passdetails.ag);
        
    		printf("\n\n\t\t\t\t\t\tPassenger Phone Number %.1lf",passdetails.Phno);
        
    		printf("\n\n\t\t\t\t\t\tPassenger Date Of Reservation %d/%d/%d",passdetails.d,passdetails.m,passdetails.year);
        
    		printf("\n\n\t\t\t\t\t\tPassenger's Unique ID(UID) is %.1lf",passdetails.UID);
 		}
	}
	while(fread(&bp,recsize1,1,fq)>0)
	{
		if(reID == bp.RID1)
		{
    		printf("\n\n\t\t\t\t\t\tReceipt Id -: %d",bp.RID1);
        
    		printf("\n\n\t\t\t\t\t\tTotal Bill amount -: Rs %d",bp.bill_amt);
		}	
	}
	if(x!=1)
	{
		printf("\n\t\t\t\t\t\tSorry there is no record of the entered Receipt ID.\n\n\t\t\t\t\t\tPlease enter a Valid Receipt ID");
		goto top5;
	}
    printf("\n\n\t\t\t\t\t\tTime : %s",ctime(&currentTime));
    printf("\n");
    
    printf("\n\n\t\t\t\t\t\tConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		printf("\t\t\t\t\t\t==================");
		printf("\n \t\t\t\t\t\tReservation Done\n");
		printf("\t\t\t\t\t\t==================");
		printf("\n\t\t\t\t\t\tPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\n\t\t\t\t\t\tReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\n\t\t\t\t\t\tInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	getch();
	fclose(fp);
	fclose(fq);
}
	
int cal(int y1, int y2, int h)
{
    int b, c, i, t, r, n;
    printf("\n\n\t\t\t\t\t\t********** The seat class available in this Railway Express is :- *********\n");
    printf("\n\t\t\t\t\t\t\t 1) Slepper Class....\n");
    printf("\n\t\t\t\t\t\t\t 2) A.C Class.......\n");
    printf("\t\n\t\t\t\t\t\tEnter your choice of class for your travel: ");
    scanf("%d", &i);
    switch (i) {
    case 1: {
        strcpy(cla,"Slepper Class");
        b = y2 * h;
        c = b + (b * 0.18);
    } break;
    case 2: {
    	printf("\n\n\t\t\t\t\t\t********** The sub classes of seat for A.C Class available are :- *********\n");
        printf("\t\t\t\t\t\t\t\t 1) 3A Class....\n");
        printf("\t\t\t\t\t\t\t\t 2) 2A Class....\n");
        printf("\t\t\t\t\t\t\t\t 3) 1st Class A.C.....\n");
        printf("\t\n\t\t\t\t\t\tEnter Your Choice of subclass: ");
        scanf("%d", &n);
        switch (n) {
        case 1: {
            strcpy(cla,"3A Class");
            b = y1 * h;
            c = b + (b * 0.18);
        } break;
        case 2: {
            strcpy(cla,"2A Class");
            b = (y1 + 1000) * h;
            c = b + (b * 0.18);
        } break;
        case 3: {
            strcpy(cla,"1st Class A.C.");
            b = (y1 + 5000) * h;
            c = b + (b * 0.18);
        } break;
        default: {
            printf("\t\t\t\t\t\t\t\tEnter Right Choice......\n");
        }
        }
    } break;
    default: {
        printf("\t\t\t\t\t\t\t\tEnter Right Choice......\n");
    }
    }
    return c;
}

/*********************************************SPECIFICTRAIN()*************************************************/

void specifictrain()
{
	system("cls");
	int train_num;
	printf("\t\t\t\t\t\tEnter specific train number(1001-1010): ");
	scanf("%d",&train_num);
	if (train_num==1001)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Mithila Lines Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Mithila to Dhangadi ");
		printf("\n\t\t\t\t\t\t Departure time: \t 09:00 am ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 11:50 am ");
	}
	if (train_num==1002)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Mithila Lines Expres ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Dhangadi to Mithila ");
		printf("\n\t\t\t\t\t\t Departure time: \t 12:00 pm ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 02:50 pm ");
	}
	if (train_num==1003)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Rajbiraj City Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Rajbiraj To Gaighat ");
		printf("\n\t\t\t\t\t\t Departure time: \t 08:00 am ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 01:00 pm ");
	}
	if (train_num==1004)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Rajbiraj City Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Gaighat To Rajbiraj ");
		printf("\n\t\t\t\t\t\t Departure time: \t 01:10 pm ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 06:10 pm ");
	}
	if (train_num==1005)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Kapilvastu City Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Kapilvastu To Jaynagar ");
		printf("\n\t\t\t\t\t\t Departure time: \t 07:00 am ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 11:00 am ");
	}
	if (train_num==1006)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Kapilvastu City Express ");
		printf("\n\t\t\t\t\t\t Destination:\t\t Jaynagar to Kapilvastu ");
		printf("\n\t\t\t\t\t\t Departure time:\t 11:05 am ");
		printf("\n\t\t\t\t\t\t Arrival time:\t\t 03:05 pm ");
	}
	if (train_num==1007)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Siraha Train Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Siraha to Lahan ");
		printf("\n\t\t\t\t\t\t Departure time: \t 01:00 pm ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 05:00 pm ");
	}
	if (train_num==1008)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Siraha Train Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Lahan to Siraha");
		printf("\n\t\t\t\t\t\t Departure time: \t 05:15 pm ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 09:15 pm ");
	}
	if (train_num==1009)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Bhagwanpur Railway Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Bhagwanpur To Ayodhyapur ");
		printf("\n\t\t\t\t\t\t Departure time: \t 03:15 pm ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 06:15 pm ");
	}
	if (train_num==1010)
	{
		printf("\n\t\t\t\t\t\t Train: \t\t Bhagwanpur Railway Express ");
		printf("\n\t\t\t\t\t\t Destination: \t\t Ayodhyapur To Bhagwanpur ");
		printf("\n\t\t\t\t\t\t Departure time: \t 06:20 am ");
		printf("\n\t\t\t\t\t\t Arrival time: \t\t 09:20 am ");
	}
}

/*********************************************VIEWDETAILS()*************************************************/

void viewdetails(void)
{
	system("cls");
	printf("------------------------------------------------------------------------------------------------------------------------");	
	printf("\n Tr.No\tName \t\t\t\t Destinations \t\t\t Departure Time \t Arrival Time \n ");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\n 1001\t Mithila Lines Express \t\t Mithila to Dhangadi \t\t 09:00 \t\t\t 11:50 ");
	printf("\n 1002\t Mithila Lines Express \t\t Dhangadi To Mithila \t\t 12:00 \t\t\t 14:50 ");
	printf("\n 1003\t Rajbiraj City Express \t\t Rajbiraj To Gaighat \t\t 08:00 \t\t\t 13:00 ");
	printf("\n 1004\t Rajbiraj City Express \t\t Gaighat To Rajbiraj \t\t 13:10 \t\t\t 18:10 ");
	printf("\n 1005\t Kapilvastu City Express \t Kapilvastu To Jaynagar \t 07:00 \t\t\t 11:00 ");
	printf("\n 1006\t Kapilvastu City Express \t Jaynagar To Kapilvastu \t 11:05 \t\t\t 15:05 ");
    printf("\n 1007\t Siraha Train Express \t\t Siraha To Lahan \t\t 13:00 \t\t\t 17:00 ");	
    printf("\n 1008\t Siraha Train Express \t\t Lahan To Siraha \t\t 17:15 \t\t\t 21:15 ");
    printf("\n 1009\t Bhagwanpur Railway Express \t Bhagwanpur To Ayodhyapur \t 15:15 \t\t\t 18:15 ");
    printf("\n 1010\t Bhagwanpur Railway Express \t Ayodhyapur To Bhagwanpur \t 18:20 \t\t\t 21:20 ");
    
}

/*********************************************SEATDETAILS()*************************************************/

// Function for chosing seats
int seat(int p)
{
    int i,a[50],k[50];
    printf("\t\t\t\t\t\t\t           -:SEAT MATRIX:-        \n");
    printf("\t\t\t\t\t\t\t(U)    (M)        (L)    (L)    "
           "    (U)\n\n");
    printf("\t\t\t\t\t\t\t01    02        03\t04        "
           "05\n\n");
    printf("\t\t\t\t\t\t\t06    07        08\t09        "
           "10\n");
    printf("\t\t\t\t\t\t\t11    12        13\t14        "
           "15\n\n");
    printf("\t\t\t\t\t\t\t16    17        18\t19        "
           "20\n");
    printf("\t\t\t\t\t\t\t21    22        23\t24        "
           "25\n\n");
    printf("\t\t\t\t\t\t\t26    27        28\t29        "
           "30\n");
    printf("\t\t\t\t\t\t\t31    32        33\t34        "
           "35\n\n");
    printf("\t\t\t\t\t\t\t36    37        38\t39        "
           "40\n");
    printf("\t\t\t\t\t\t\t41    42        43\t44        "
           "45\n\n");
    printf("\t\t\t\t\t\t\t46    47        48\t49        "
           "50\n");
    printf("\t\t\t\t\t\t\t51    52        53\t54        "
           "55\n\n");
    printf("\t\t\t\t\t\t\t56    57        58\t59        "
           "60\n");
    top2:
    printf("\n\n\t\t\t\t\t\t\tEnter Seat Numbers: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a[i]);
        if(k[i]==a[i])
        {
        	printf("\t\t\t\t\t\tSorry, The seat is already taken");
        	goto top2;
		}
        k[i]=a[i];
    }
}
/*********************************************Function for Cancel Menu()*************************************************/
void cancel(void)
{
	int recpID,status;
	float cancelp;
	long int recsize1;
	FILE *fq;
	fq=fopen("Railway_Reservation1.txt","r+");
    if (fq==NULL)
    {
       fq=fopen("Railway_Reservation1.txt","w+");

       if (fq==NULL)
	{
	   puts("File cannot be opened ");
	   exit(0);
	}
	}
	recsize1= sizeof(bp);
	system("cls");
	top:
	printf("\n\n\t\t\t\t\t\tEnter the receipt id to cancel the ticket: "); 
	fflush(stdin);
	scanf("%d",&recpID); 

	rewind(fq);
	
	printf("\n\n\t\t\t\t\t\t---------Cancel a Ticket----------\n"); 
	
   	while(fread(&bp,recsize1,1,fq)>0)
   	{
   		if(recpID == bp.RID1)
   		{
   			status=0;
   			printf("\n\n\t\t\t\t\t\tYour Total Bill Amount is :- Rs %d",bp.bill_amt);
   			cancelp= bp.bill_amt - bp.bill_amt * 0.15 ;
   			printf("\n\n\t\t\t\t\t\tThe amount you get after cancellation charge is -: Rs %.2f",cancelp);
   		}
	}
	if (status != 0)
   		{
   			printf("\n\n\t\t\t\t\t\tPlease enter a valid receipt ID");
   			goto top;
		}
	if(status == 0) 
	{
		printf("\n\n\t\t\t\t\t\tYour reservation is cancelled successfully.");
	}
	getch();
	fclose(fq);
}

/*********************************************Function for Search Menu()*************************************************/

void search()
{
	system("cls");
	int i,j,recID,x;
	long int resize,resize1;
	FILE *fp,*fq;
	fp=fopen("Railway_Reservation.txt","r+");
    if (fp==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	fq=fopen("Railway_Reservation1.txt","r+");
    if (fq==NULL)
    {
	   puts("File cannot be opened ");
	   exit(0);
	}
	
	resize=sizeof(passdetails);
	
	resize1=sizeof(bp);
	
	flag5:
		
	printf("\n\n\t\t\t\t\t\tEnter the receipt ID of the passenger: ");
	fflush(stdin);
	scanf("%d",&recID);
	
	rewind(fp);
	rewind(fq);
	printf("\n\n\t\t\t\t\t\t*********************** YOUR SEARCH DETAILS ****************************");
	
	while(fread(&passdetails,resize,1,fp)>0)
	{
		if(recID == passdetails.RID)
		{
			x=1;
    		printf("\n\n\t\t\t\t\t\tPassenger Name: ");
    		puts(passdetails.val);
    		printf("\n\t\t\t\t\t\tPassenger Gender: ");
    		puts(passdetails.gender);
    		printf("\n\t\t\t\t\t\tPassenger Age: %d",passdetails.ag);
        
    		printf("\n\n\t\t\t\t\t\tPassenger Phone Number %.1lf",passdetails.Phno);
        
    		printf("\n\n\t\t\t\t\t\tPassenger Date Of Reservation %d/%d/%d",passdetails.d,passdetails.m,passdetails.year);
        
    		printf("\n\n\t\t\t\t\t\tPassenger's Unique ID(UID) is %.1lf",passdetails.UID);
 		}
	}
	if(x!=1)
	{
		printf("\n\t\t\t\t\t\tSorry there is no record of the entered Receipt ID.\n\nPlease enter a Valid Receipt ID");
		goto flag5;
	}
	while(fread(&bp,resize1,1,fq)>0)
	{
		if(recID == bp.RID1)
		{
    		printf("\n\n\t\t\t\t\t\tReceipt Id -: %d",bp.RID1);
        
    		printf("\n\n\t\t\t\t\t\tTotal Bill amount -: Rs %d",bp.bill_amt);
		}	
	}
	getch();
	fclose(fp);
	fclose(fq);
	
}
/*********************************************Function for Login Menu()*************************************************/
void login()
{
	int a=0,i=0;
    char uname[10],c=' '; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n \n \n \n \n \n \t \t \t \t \t \t =======================  LOGIN FORM  =======================\n  ");
    printf(" \n \t \t \t \t \t \t                  ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n \t \t \t \t \t \t                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n \t \t \t \t \t \t      WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t \t \t \t \t \t PRESS ANY KEY TO CONTINUE...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n \n \n  \t \t \t \t \t \t     SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();//holds the screen
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
		
	}
		system("cls");	
}


              

