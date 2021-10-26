#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nextptr;
    struct node *prevptr;

} *stnode;

void create_node_list();
void display_list();
void insert_at_beginning();
void insert_at_end();
void insert_after();
void insert_before();
void delete_at_beginning();
void delete_at_end();
void delete_after();
void delete_before();
void delete_specific();

int main()
{
    int ch;

    printf("\nCREATION OF DOUBLE LINKED LIST\n");
    create_node_list();
    printf("\nDISPLAY OF DOUBLE LINKED LIST CREATED\n");
    printf("\n Data entered in the list : \n");
    display_list();

    while(1)
	{
	   printf("\nOPERATIONS TO BE PERFORMED ON A DOUBLE LINKED LIST");
	   printf("\n1: Insert a new node at the beginning. ");
	   printf("\n2: Insert a new node at the end. ");
	   printf("\n3: Insert a new node after a given node with a specific value.");
	   printf("\n4: Insert a new node before a given node with a specific value.");
	   printf("\n5: Delete a node at the beginning. ");
	   printf("\n6: Delete a node at the end.");
	   printf("\n7: Delete a node after a node with a specific value. ");
	   printf("\n8: Delete a node before a node with a specific value. ");
       printf("\n9: Delete a node with a specific value. ");
       printf("\n10: Stop execution and exit.");

	   printf("\n\nEnter your choice: ");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	      case 1: insert_at_beginning();
		          break;
		  case 2: insert_at_end();
		          break;
		  case 3: insert_after();
		          break;
		  case 4: insert_before();
		          break;
       	  case 5: delete_at_beginning();
			      break;
		  case 6: delete_at_end();
		          break;
		  case 7: delete_after();
		          break;
   	      case 8: delete_before();
			      break;
		  case 9: delete_specific();
		          break;
		  case 10: exit(0);
		           break;
		  default: printf("Wrong choice!");
	   }
    }
    return 0;
}

void create_node_list()
{
    int n;
    printf("\nHow many nodes do you want to enter? ");
    scanf("%d", &n);
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf("Input data for node 1 : ");
        scanf("%d", &num);
        stnode->data = num;
        stnode->nextptr = NULL;
        stnode->prevptr = NULL;
        tmp = stnode;
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Input data for node %d : ", i);
                scanf(" %d", &num);

                fnNode->data = num;
                fnNode->nextptr = NULL;

                tmp->nextptr = fnNode;
                fnNode->prevptr=tmp;
                tmp = tmp->nextptr;
            }
        }
    }
}

void display_list()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp!= NULL)
        {
            printf(" %d\n", tmp->data);
            tmp = tmp->nextptr;
        }
    }
}

void insert_at_beginning()
{
    if(stnode == NULL)
    {
        printf("Node insertion at the beginning is not possible because the list is empty.");
    }
    else
    {
	   struct node *temp;
	   temp=(struct node*)malloc(sizeof(struct node));
	   printf("Enter the node data to be inserted: ");
	   scanf("%d",&temp->data);
	   temp->nextptr=stnode;
	   stnode->prevptr=temp;
	   temp->prevptr=NULL;
	   stnode=temp;
	   printf("\nThe list after insertion of node in the beginning is: \n");
	   display_list();
    }
}


void insert_at_end()
{
	if(stnode == NULL)
    {
        printf("Node insertion at the end is not possible because the list is empty.");
    }
    else
    {
        struct node *temp, *ptr;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the node data to be inserted.");
		scanf("%d",&temp->data);
		ptr=stnode;
		while(ptr->nextptr!=NULL)
		{
		    ptr=ptr->nextptr;
		}
		ptr->nextptr=temp;
		temp->nextptr=NULL;
		temp->prevptr=ptr;
		printf("\nThe list after insertion of node in the end is: \n");
	    display_list();
    }
}


void insert_after()
{
	if(stnode == NULL)
    {
        printf("Node insertion after specific node is not possible because the list is empty.");
    }
    else
    {
	    struct node *temp, *ptr;
	    int k , val;
	    printf("\nEnter the node data after which insertion is to be done: ");
	    scanf("%d",&k);
	    printf("\nEnter the new node data to be inserted: ");
	    scanf("%d",&val);
	    temp=(struct node*)malloc(sizeof(struct node));
	    temp->data=val;
	    ptr=stnode;
	    while(ptr->data!=k && ptr->nextptr!=NULL)
	    {
		     ptr=ptr->nextptr;
	    }
	    if(ptr->nextptr==NULL)
	    {
	    	if(ptr->data!=k)
	    	{
	    		printf("\nThe specified element %d could not be found in the list.\n",k);
	    	}
	    	else
	    	{
	    		ptr->nextptr=temp;
	    		temp->nextptr=NULL;
	    		temp->prevptr=ptr;
	    		printf("\nThe list after insertion of node after the specified element %d is: \n",k);
	            display_list();
	    	}
	    }
	    else
	    {
	        temp->nextptr=ptr->nextptr;
	        (ptr->nextptr)->prevptr=temp;
	        ptr->nextptr=temp;
	        temp->prevptr=ptr;
	        printf("\nThe list after insertion of node after the specified element %d is: \n",k);
	        display_list();
		}
	}
}



void insert_before()
{
  if(stnode == NULL)
  {
      printf("Node insertion at before the specified element is not possible because the list is empty.");
  }
  else
  {
      struct node *temp , *ptr, *preptr;
      int k;
      printf("Enter the node data before which insertion is to be done:");
      scanf("%d",&k);
      temp=(struct node*)malloc(sizeof(struct node));
      printf("Enter the new node data to be inserted:");
      scanf("%d",&temp->data);
      ptr=stnode;
      if(stnode->data==k)
      {
          ptr->prevptr=temp;
          temp->nextptr=ptr;
          temp->prevptr=NULL;
          stnode=temp;
          printf("\nThe list after insertion of node before the specified element %d is: \n",k);
	      display_list();
      }
      else
      {
          while(ptr->data!=k && ptr->nextptr!=NULL)
          {
	           preptr=ptr;
      	       ptr=ptr->nextptr;
          }

          if(ptr->nextptr==NULL && ptr->data!=k)
          {
               printf("\nThe specified element %d could not be found in the list.\n",k);
          }
          else
          {
	      preptr->nextptr=temp;
	      temp->prevptr=preptr;
          temp->nextptr=ptr;
          ptr->prevptr=temp;
          printf("\nThe list after insertion of node before the specified element %d is: \n",k);
	      display_list();
          }
       }
  }
}


void delete_at_beginning()
{
if(stnode == NULL)
    {
        printf("Node deletion at the beginning is not possible because the list is empty.");
    }
    else
    {
	    struct node *temp;
		temp=stnode;
		stnode=stnode->nextptr;
		stnode->prevptr=NULL;
		free(temp);
		printf("\nThe list after deletion of node at the beginning is: \n");
	    display_list();
	}
}


void delete_at_end()
{
	if(stnode == NULL)
    {
        printf("Node insertion at the end is not possible because the list is empty.");
    }
    else
    {
    	struct node *ptr, *preptr;
    	ptr=stnode;
		while(ptr->nextptr!=NULL)
		{
		    preptr=ptr;
		    ptr=ptr->nextptr;
		}
		preptr->nextptr=NULL;
		free(ptr);
		printf("\nThe list after deletion of node at the end is: \n");
	    display_list();
	}
}


void delete_after()
{
	if(stnode == NULL)
    {
        printf("Node insertion after the specified element is not possible because the list is empty.");
    }
    else
    {
    	struct node *temp, *ptr;
	    int k , val;
	    printf("\nEnter the node data after which deletion is to be done: ");
	    scanf("%d",&k);
	    ptr=stnode;
	    while(ptr->data!=k && ptr->nextptr!=NULL)
	    {
		     ptr=ptr->nextptr;
	    }
	    if((ptr->nextptr)->nextptr==NULL)
        {
            temp=ptr->nextptr;
	        ptr->nextptr=NULL;
	        free(temp);
	    	printf("\nThe list after deletion of node after the specified element %d is: \n",k);
	        display_list();
        }
	    else if(ptr->nextptr==NULL)
	    {
	    	if(ptr->data!=k)
	    	{
	    		printf("\nThe specified element %d could not be found in the list.\n",k);
	    	}
	    	else
	    	{
	    	    printf("\nNo element exists after the specified element %d in the list.\n",k);
	        }
	    }
	    else
	    {
	        temp=ptr->nextptr;
	        ptr->nextptr=temp->nextptr;
	        (temp->nextptr)->prevptr=ptr;
	        free(temp);
	    	printf("\nThe list after deletion of node after the specified element %d is: \n",k);
	        display_list();
	    }
    }
}


void delete_before()
{
  if(stnode == NULL)
  {
      printf("Node insertion before the specified element is not possible because the list is empty.");
  }
  else
  {
      struct node *temp , *ptr, *preptr;
      int k;
      printf("Enter the node data before which deletion is to be done:");
      scanf("%d",&k);
      ptr=stnode;
      if(stnode->data==k)
           printf("\nDeletion before the specified element is not possible because it is the first element of the list.\n");
      else
      {
           while(ptr->data!=k && ptr->nextptr!=NULL)
           {
	             preptr=ptr;
      	         ptr=ptr->nextptr;
           }
           if(ptr->nextptr==NULL)
           {
                 if(ptr->data!=k)
	                     printf("\nThe specified element %d could not be found in the list.\n",k);
                 else
                 {
                         preptr->data=ptr->data;
	                     preptr->nextptr=NULL;
	                     free(ptr);
                         printf("\nThe list after deletion of node before the specified element %d is: \n",k);
	                     display_list();
                 }
           }
            else
           {
	             preptr->data=ptr->data;
	             preptr->nextptr=ptr->nextptr;
	             (ptr->nextptr)->prevptr=ptr->prevptr;
	             free(ptr);
                 printf("\nThe list after deletion of node before the specified element %d is: \n",k);
	             display_list();
           }
      }
  }
}

void delete_specific()
{
	if(stnode == NULL)
    {
        printf("Specific node deletion is not possible because the list is empty.");
    }
    else
    {
    	struct node *temp, *ptr, *preptr;
	    int k , val;
	    printf("\nEnter the node data which is to be deleted: ");
	    scanf("%d",&k);
	    ptr=stnode;
	    if(ptr->data==k)
        {
          stnode=ptr->nextptr;
          stnode->prevptr=NULL;
          free(ptr);
          printf("\nThe list after deletion of specific node is: \n");
          display_list();
        }
        else
        {
	        while(ptr->data!=k && ptr->nextptr!=NULL)
	        {
	             preptr=ptr;
                 ptr=ptr->nextptr;
            }
	        if(ptr->nextptr==NULL)
	        {
	    	     if(ptr->data!=k)
	    	     {
	    		       printf("\nThe specified element %d could not be found in the list.\n",k);
	    	     }
	    	     else
	    	     {
	    	           temp=ptr;
	                   preptr->nextptr=NULL;
	                   free(temp);
	    	           printf("\nThe list after deletion of specific node is: \n");
	                   display_list();
	            }
            }
	        else
	        {
	            temp=ptr;
	            preptr->nextptr=ptr->nextptr;
                (ptr->nextptr)->prevptr=ptr->prevptr;
	            free(temp);
	    	    printf("\nThe list after deletion of specific node is: \n");
	            display_list();
	        }
        }
    }
}



