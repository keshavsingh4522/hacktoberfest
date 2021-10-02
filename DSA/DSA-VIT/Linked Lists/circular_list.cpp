#include<iostream>
using namespace std;

//initialization
class node{
public:
	int data;
	node*next;
	node(int d)
	{
		d=data;
		next=NULL;
	}
};

void insert(node*&head,int data)
{
	//create a new node
	node*n=new node(data);
	node*temp=head;
	n->next=head;
	if(temp!=NULL)
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=n;
	}

	//applying self loop
	else
		n->next=n;
	head=n;
}

void print(node*&head)
{
	node*temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<" ->";
		temp=temp->next;
	}
}

node* search(node*head,int data)
{
	node*temp=head;
	while(temp->next!=head)
	{
		if(temp->data==data)
			return temp;
		temp=temp->next;
	}
	//checking for last node
	if(temp->data==data)
		return temp;
	return NULL;
}

void deleteNode(node*&head,int data)
{
	node* del=search(head,data);
	if(del==NULL)
		return;

	if(head==del)
		head=head->next;

	node*temp=head;
	while(temp->next!=del)
	{
		temp=temp->next;
	}
	temp->next=del->next;
	delete del;
}

int main()
{
	node*head=NULL;
	insert(head,10);
	insert(head,20);
	insert(head,30);
	insert(head,40);
	print(head);
	deleteNode(head,20);
	print(head);
	return 0;
}