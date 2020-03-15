#include<stdio.h>
#define MAX 5 
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int elem);
int dequeue();
int peek();
void display();
void main()
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
		printf("\n Enter your option :");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\n Enter the number to be inserted in the queue :");
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2:
				val = dequeue();
				if (val != -1)
					printf("\n The number deleted is : %d", val);
				break;
			case 3:
				val = peek();
				if (val != -1)
					printf("\n The first value in queue is : %d", val);
				break;
			case 4:
				display();
				break;
		}
	}while(option != 5);

}

void enqueue(int elem)
{
	
	if(rear == MAX-1)
		printf("\n OVERFLOW");
	else if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = elem;
	}
		
	else
	{
		rear = rear + 1;
		queue[rear] = elem;
	}
}
int dequeue()
{
	int val;
	if(front == -1 && rear == -1 || front>rear)
	{
		printf("\n UNDERFLOW");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		return val;
	}
}
int peek()
{
	if(front==-1 && rear == -1 || front>rear)
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
	if(front == -1 && rear == -1 || front > rear)
		printf("\n QUEUE IS EMPTY");
	else
	{
		for(i = front;i <= rear;i++)
			printf("%d \t", queue[i]);
		
	}
}