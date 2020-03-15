#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}QUEUENODE;

QUEUENODE *rear=NULL;
QUEUENODE *front=NULL;
QUEUENODE* enqueue(int);
QUEUENODE* dequeue();
int peek();
void display();

int main()
{
	int val, option;
	do
	{
		printf("\n *****MAIN MENU*****");
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\n Enter the number to insert in the queue:");
				scanf("%d", &val);
				front = enqueue(val);
				break;
			case 2:
				front = dequeue();
				break;
			case 3:
				val = peek();
				if(val != -1)
					printf("\n The value at front of queue is : %d", val);
				else 
					printf("\n QUEUE IS EMPTY");
				break;
			case 4:
				display();
				break;
		}
	}while(option != 5);
	return 0;
}
QUEUENODE* enqueue(int val)
{
	QUEUENODE *new_node;
	new_node = (QUEUENODE*)malloc(sizeof(QUEUENODE));
	new_node -> data = val;
	if(front == NULL && rear == NULL)
	{
		front = new_node;
		rear = new_node;
		front -> next = rear -> next = NULL;
	}
	else
	{
		rear -> next = new_node;
		rear = new_node;
		rear -> next = NULL;
	}
	return front;
}
void display()
{
	QUEUENODE *ptr;
	ptr = front;
	if(ptr == NULL)
		printf("\n QUEUE IS EMPTY");
	else
	{
		printf("\n");
		while(ptr!=NULL)
		{
			printf("%d\t", ptr -> data);
			ptr = ptr -> next;
		}
		//printf("%d\t", ptr -> data);
	}
	
}
QUEUENODE* dequeue()
{
	QUEUENODE *ptr;
	ptr = front;
	if(front == NULL)
		printf("\n UNDERFLOW");
	else
	{
		front = front -> next;
		printf("\n The value being deleted is : %d", ptr -> data);
		free(ptr);
	}
	return front;
}
int peek()
{
	if(front==NULL)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
		return front->data;
}