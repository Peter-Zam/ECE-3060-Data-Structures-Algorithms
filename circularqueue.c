#include <stdio.h>
#define MAX 5 
int queue[MAX];
int front = -1, rear = -1;
void insert_element(int elem);
int delete_element();
int peek();
void display();
int main()
{
	int option, val;
	do
	{
		printf("\n ***** MAIN MENU *****");
		printf("\n 1. Insert an element");
		printf("\n 2. Delete an element");
		printf("\n 3. Peek");
		printf("\n 4. Display the queue");
		printf("\n 5. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\n Enter the number to be inserted in the queue : ");
				scanf("%d", &val);
				insert_element(val);
				break;
			case 2:
				val = delete_element();
				if(val != -1)
					printf("\n The number deleted is : %d", val);
				break;
			case 3:
				val = peek();
				if(val != -1)
					printf("\n The first value in queue is : %d", val);
				break;
			case 4:
				display();
				break;
		}
	}while(option!=5);
	return 0;
}
void insert_element(int elem)
{
	if(front == 0 && rear == MAX-1 || front == rear +1 )
		printf("\n OVERFLOW");
	
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=elem;
	}
	else if(rear==MAX-1 && front != 0)
	{
		rear=0;
		queue[rear]=elem;
	}
	else
	{
		rear++;
		queue[rear]=elem;
	}
	
}
int delete_element()
{
	int val;
	if(front==-1 && rear==-1)
	{
		printf("\n UNDERFLOW");
		return -1;
	}
	val = queue[front];
	if(front==rear)
		front=rear=-1;
	else if(front==MAX-1)
		front=0;
	else
		front++;
	
	return val;
}
int peek()
{
	if(front==-1 && rear==-1)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		return queue[front];
	}
}
void display()
{
	int i;
	printf("\n");
	if (front == -1 && rear == -1)
		printf ("\n QUEUE IS EMPTY");
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
				printf("%d \t", queue[i]);
		}
		else
		{
			for(i=front;i<MAX;i++)
				printf("%d \t", queue[i]);
			for(i=0;i<=rear;i++)
				printf("%d \t", queue[i]);
		}
	}
}