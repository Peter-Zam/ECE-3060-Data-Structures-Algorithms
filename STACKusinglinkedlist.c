#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}STACKNODE;

STACKNODE *top = NULL;
STACKNODE* push(int);
void display();
STACKNODE* pop();
int peek();

int main() 
{
	int val, option;
	do
	{
		printf("\n *****MAIN MENU*****");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
					printf("\n Enter the number to be pushed on stack: ");
					scanf("%d", &val);
					top = push(val);
					break;
			case 2:
					top = pop();
					break;
			case 3:
					val = peek();
					if (val != -1)
						printf("\n The value at the top of stack is: %d", val);
					else
						printf("\n STACK IS EMPTY");
					break;
			case 4:
					display();
					break;
		}
	}while(option != 5);
	return 0;
}
STACKNODE* push(int val)
{
	STACKNODE *new_node;
	new_node = (STACKNODE*)malloc(sizeof(STACKNODE));
	new_node -> data = val;
	if(top == NULL)
	{
		new_node -> next = NULL;
		top = new_node;
	}
	else
	{
		new_node -> next = top;
		top = new_node;
	}
	return top;
}
void display()
{
	STACKNODE *ptr;
	ptr = top;
	if(top == NULL)
		printf("\n STACK IS EMPTY");
	else
	{
		while(ptr != NULL)
		{
			printf("\n %d", ptr -> data);
			ptr = ptr -> next;
		}
	}
	
}
STACKNODE *pop()
{
	STACKNODE *ptr;
	ptr = top;
	if(top == NULL)
		printf("\n STACK UNDERFLOW");
	else
	{
		top = top -> next;
		printf("\n The value being deleted is: %d", ptr -> data);
		free(ptr);
	}
	return top;
}
int peek()
{
	if(top == NULL)
		return -1;
	else
		return top -> data;
}