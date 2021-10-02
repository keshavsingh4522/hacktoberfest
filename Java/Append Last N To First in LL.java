/*import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class LinkedListNode<T> {
    T data;
    LinkedListNode<T> next;
    
    public LinkedListNode(T data) {
        this.data = data;
    }
}

public class Runner {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static LinkedListNode<Integer> takeInput() throws IOException {
        LinkedListNode<Integer> head = null, tail = null;

        String[] datas = br.readLine().trim().split("\\s");

        int i = 0;
        while (i < datas.length && !datas[i].equals("-1")) {
            int data = Integer.parseInt(datas[i]);
            LinkedListNode<Integer> newNode = new LinkedListNode<Integer>(data);
            if(head == null) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail.next = newNode;
                tail = newNode;
            }
            i += 1;
        }

        return head;
    }
    
    public static void print(LinkedListNode<Integer> head){
        while(head != null) {
            System.out.print(head.data + " ");
            head = head.next;
        }
        
        System.out.println();
    }
    
    public static void main(String[] args) throws NumberFormatException, IOException {
        int t = Integer.parseInt(br.readLine().trim());

        while (t > 0) {
            
            LinkedListNode<Integer> head = takeInput(); 

            int n = Integer.parseInt(br.readLine().trim());
            head = Solution.appendLastNToFirst(head, n);
            print(head);

            t -= 1;
        }
        
    }
}*/
public class Solution {

	public static LinkedListNode<Integer> appendLastNToFirst(LinkedListNode<Integer> head, int n) {
		//Your code goes here
        LinkedListNode<Integer> temp = head;
        LinkedListNode<Integer> temp2 = head;
        LinkedListNode<Integer> newNode = head;
        if(head==null)
            return head;
        
        int j=0;
        while(temp2.next!=null)
        {
            temp2=temp2.next;
            
            j++;
        }
        temp2.next=newNode;
        j++;
        int i=0;
        while(i<j-n-1)
        {
            head=head.next;
            i++;
        }
        temp=head.next;
        head.next=null;
        return temp;
	}

}
