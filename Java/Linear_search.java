import java.util.*;
public class linearsearch{	
	public static int lisearch(int key,int numbers[]){
		for(int i=0; i<=numbers.length ;i++){
			if (numbers[i]==key){
				return i;
			}
			
		}
		
		return -1;
	}
	
	public static void main(String args[]){
		int numbers[] ={2,4,6,8,10,12,14,16};
		Scanner s = new Scanner(System.in);
		System.out.println("enter the key:");
		int key = s.nextInt();
		int index = lisearch(key , numbers);
		if(index==-1){
			System.out.println("index not found");
	}
		else{
			System.out.println("index at key " + key +" is : " + index);
		}
	}
	}