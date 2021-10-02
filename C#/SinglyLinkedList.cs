using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SinglyLinkedList
{
    class Node
    {
        public int data;
        public Node next;

        public Node(int value)
        {
            data = value;
            next = null;
        }
    }

    class LinkedList
    {
        private Node head;
        public int length;

        public void AddNodeToFront(int value)
        {
            Node nodeToAdd = new Node(value);
            nodeToAdd.next = head;
            head = nodeToAdd;
            length++;
        }

        public void AppendToLast(int value)
        {
            if (head == null)
            {
                head = new Node(value);
                head.next = null;
                length++;
            }
            else 
            {
                Node nodeToAdd = new Node(value);
                Node current = head;

                while (current.next != null)
                {
                    current = current.next;
                }
                current.next = nodeToAdd;
                length++;
            }
        }

        public void Insert(int index, int value)
        {
            if (index == 0)
            {
                AddNodeToFront(value);
            }
            else if (index >= length)
            {
                AppendToLast(value);
            }
            else
            {
                int counter = 0;
                Node newNode = new Node(value);
                Node pointer = head;
                Node temp;
                length++;

                while(pointer != null)
                {
                    if (counter == index - 1)
                    {
                        temp = pointer.next;
                        pointer.next = newNode;
                        newNode.next = temp;
                        break;
                    }
                    else
                    {
                        pointer = pointer.next;
                        counter++;
                    }
                }
            }           
        }

        public void Remove(int index)
        {
            if (index == 0)
            {
                Node current = head.next;
                head.next = null;
                head = current;
                length--;
            }
            else
            {
                if (index >= length)
                    index = length - 1;

                Node current = head;
                int counter = 0;
                Node temp;

                while (current != null)
                {
                    if (counter == index - 1)
                    {
                        temp = current.next;
                        current.next = temp.next;
                        length--;
                        break;
                    }
                    else
                    {
                        current = current.next;
                        counter++;
                    }
                }
            }
        }

        public void Reverse()
        {
            if (length > 1)
            {
                Node first = head;
                Node second = first.next;
                Node temp;

                while (second != null)
                {
                    temp = second.next;
                    second.next = first;
                    first = second;
                    second = temp;
                }

                head.next = null;
                head = first;
            }
        }

        public void PrintAllNodes()
        {
            Node point = head;

            while (point != null)
            {
                Console.WriteLine(point.data);
                point = point.next;
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            LinkedList myLinkedList = new LinkedList();
            myLinkedList.AddNodeToFront(8);
            myLinkedList.AppendToLast(7);
            myLinkedList.AppendToLast(6);
            myLinkedList.Insert(2, 4);
            myLinkedList.Insert(3, 12);
            myLinkedList.Remove(1);
            Console.WriteLine("Linked list before reversal:");
            myLinkedList.PrintAllNodes();
            myLinkedList.Reverse();
            Console.WriteLine("Linked list after reversal:");
            myLinkedList.PrintAllNodes();
            Console.WriteLine("Length of the linked list: {0}", myLinkedList.length);

            Console.Read();
        }
    }
}
