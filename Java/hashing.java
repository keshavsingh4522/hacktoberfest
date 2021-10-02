/*
 *  Implement a hash table for storing bank account information. Handle the collision using
 *  linear probing without replacement. Perform operations on it.
 */

package assign;

import java.util.*;

class Customer {//Customer class
	long id;
	String name;
	Double balance;

	public Customer(long id, String nm, Double bal) {//Parameterized Constructor
		this.id = id;
		name = nm;
		balance = bal;
	}


}

class Table {//Class for hash table
	int size;
	int hashaddress;

	Customer hashtable[] = new Customer[5];
	

	int hash(long key)//hash function
	{
		return (int)key%5;//linear probing
	}

	void insert()//Inserting element in hashtable
	{
		long ID;
		String name;
		double balance;
		Scanner sc=new Scanner(System.in);
		Scanner s=new Scanner(System.in);
			if(size==5) {//Checking if hashtable is full
				System.out.println("Table is full");
				return;
			}
			//Accepting Customer details
			System.out.println("Enter the details of the customer to be added:");
			System.out.println("Enter customer ID");
			ID=sc.nextInt();
			System.out.println("Enter the name of the customer");
			name=s.nextLine();
			System.out.println("Enter the Balance available in the account of the customer");
			balance=sc.nextInt();
			Customer temp=new Customer(ID,name,balance);
			int hashVal=hash(ID);//hashing
			while(hashtable[hashVal]!=null) {
				hashVal++;
				hashVal=hash(hashVal);//rehashing
			}
			hashtable[hashVal]=temp;
			size++;
	}
	void display()//Display function for hashtable
	{
			for(int i=0;i<5;i++) {
				if(hashtable[i]!=null) {//Display customer details
					System.out.println("The customer ID is " + hashtable[i].id + " name: "+ hashtable[i].name + " Account Balance: "+  hashtable[i].balance );			
				}
			}
	}
	void search()//searching customer
	{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter the ID of the customer you want to search");
			long key=sc.nextInt();//Accepting ID
			int hashVal=hash(key);//Hashing
			while(hashtable[hashVal]!=null) {//Checking for the object
				if(hashtable[hashVal].id==key) {//Comparison
					System.out.println("The customer with ID "+ key + " is Found!");
					System.out.println("The customer ID :" + hashtable[hashVal].id + " name: "+ hashtable[hashVal].name + " Account Balance: "+  hashtable[hashVal].balance );
					return;
				}
				hashVal++;
				hashVal=hash(hashVal);//Rehashing
			}
			System.out.println("Customer with ID "+ key + " not Found");
			return;
			
	}
	void delete()//delete from hash table
	{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter the ID of the customer to be deleted:");
			long key=sc.nextInt();
			int hashVal=hash(key);//hashing
			while(hashtable[hashVal]!=null) {//checking for element
				if(hashtable[hashVal].id==key){//comparison
					size--;
					hashtable[hashVal]=null;
					System.out.println("The customer ID "+key+" is deleted");
					return;
				}
				hashVal++;
				hashVal=hash(hashVal);//Rehashing
			}
			System.out.println("The customer Id to be deleted not found!");
			return;
	}

}

public class Hash {//Main function
	public static void main(String args[]) {
		Table t = new Table();
		Scanner co=new Scanner(System.in);
		int choice;
		do
		{
			System.out.println("1.INSERT \n2.DISPLAY\n3.SEARCH\n4.DELETE\n0.EXIT");
			System.out.println("Enter the option");
			choice=co.nextInt();
			switch(choice)
			{
			case 1: t.insert();
			break;
			case 2:t.display();
			break;
			case 3:t.search();
			break;
			case 4:t.delete();
			break;
			}
		}while(choice!=0);
	}

}
/*TIME COMPLEXITIES
hash-O(1)
insert-best case :O(1) worst case:O(n)
display-O(n)
search-best case :O(1) worst case:O(n)
delete-best case :O(1) worst case:O(n)


OUTPUT:
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
1
Enter the details of the customer to be added:
Enter customer ID
2304
Enter the name of the customer
reena
Enter the Balance available in the account of the customer
20000
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
1
Enter the details of the customer to be added:
Enter customer ID
3304				(NOT PART OF OUTPUT: INPUT FOR COLLISION)
Enter the name of the customer
sansu
Enter the Balance available in the account of the customer
40000
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
1
Enter the details of the customer to be added:
Enter customer ID
2305
Enter the name of the customer
nikhil
Enter the Balance available in the account of the customer
50000
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
1
Enter the details of the customer to be added:
Enter customer ID
2306
Enter the name of the customer
sandeep
Enter the Balance available in the account of the customer
60000
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
1
Enter the details of the customer to be added:
Enter customer ID
2307
Enter the name of the customer
ashish
Enter the Balance available in the account of the customer
80000
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
1
Table is full
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
2
The customer ID is 3304 name: sansu Account Balance: 40000.0
The customer ID is 2305 name: nikhil Account Balance: 50000.0
The customer ID is 2306 name: sandeep Account Balance: 60000.0
The customer ID is 2307 name: ashish Account Balance: 80000.0
The customer ID is 2304 name: reena Account Balance: 20000.0
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
3
Enter the ID of the customer you want to search
2304
The customer with ID 2304 is Found!
The customer ID :2304 name: reena Account Balance: 20000.0
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
4
Enter the ID of the customer to be deleted:
2304
The customer ID 2304 is deleted
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
3
Enter the ID of the customer you want to search
3305
Customer with ID 3305 not Found
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
4
Enter the ID of the customer to be deleted:
3305
The customer Id to be deleted not found!
1.INSERT 
2.DISPLAY
3.SEARCH
4.DELETE
0.EXIT
Enter the option
0
*/