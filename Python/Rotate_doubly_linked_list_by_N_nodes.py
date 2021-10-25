class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.previous = None;    
        self.next = None;    
            
class RotateList:    
    #Represent the head and tail of the doubly linked list    
    def __init__(self):    
        self.head = None;    
        self.tail = None;    
        self.size = 0;    
            
    #addNode() will add a node to the list    
    def addNode(self, data):    
        #Create a new node    
        newNode = Node(data);    
            
        #If list is empty    
        if(self.head == None):    
            #Both head and tail will point to newNode    
            self.head = self.tail = newNode;    
            #head's previous will point to None    
            self.head.previous = None;    
            #tail's next will point to None, as it is the last node of the list    
            self.tail.next = None;    
        else:    
            #newNode will be added after tail such that tail's next will point to newNode    
            self.tail.next = newNode;    
            #newNode's previous will point to tail    
            newNode.previous = self.tail;    
            #newNode will become new tail    
            self.tail = newNode;    
            #As it is last node, tail's next will point to None    
            self.tail.next = None;    
        #Size will count the number of nodes present in the list    
        self.size = self.size + 1;    
            
    #rotateList() will rotate the list by given n nodes    
    def rotateList(self, n):    
        #Initially, current will point to head    
        current = self.head;    
            
        #n should not be 0 or greater than or equal to number of nodes present in the list    
        if(n == 0 or n >= self.size):    
            return;    
        else:    
            #Traverse through the list till current point to nth node    
            #after this loop, current will point to nth node    
            for i in range(1, n):    
                current = current.next;    
                    
            #Now to move entire list from head to nth node and add it after tail    
            self.tail.next = self.head;    
            #Node next to nth node will be new head    
            self.head = current.next;    
            #Previous node to head should be None    
            self.head.previous = None;    
            #nth node will become new tail of the list    
            self.tail = current;    
            #tail's next will point to None    
            self.tail.next = None;    
                
    #display() will print out the nodes of the list    
    def display(self):    
        #Node current will point to head    
        current = self.head;    
        if(self.head == None):    
            print("List is empty");    
            return;    
                
        while(current != None):    
            #Prints each node by incrementing pointer.    
            print(current.data),    
            current = current.next;    
        print();    
            
dList = RotateList();    
#Add nodes to the list    
dList.addNode(1);    
dList.addNode(2);    
dList.addNode(3);    
dList.addNode(4);    
dList.addNode(5);    
     
print("Original List: ");    
dList.display();    
     
#Rotates list by 3 nodes    
dList.rotateList(3);    
     
print("Updated List: ");    
dList.display();   
