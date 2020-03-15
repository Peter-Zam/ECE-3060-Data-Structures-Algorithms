#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node* create_cll();
void display();
struct node* insert_beg();
struct node* insert_end();
struct node* delete_beg();
struct node* delete_end();

int main()
{
	int option;
	do
	{
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");
		printf("\n 5: Delete a node from the beginning");
		printf("\n 6: Delete a node from the end");
		printf("\n 7: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: start = create_cll();
					printf("\n CIRCULAR LINKED LIST CREATED");
					break;
			case 2: display();
					break;
			case 3: start = insert_beg();
					break;
			case 4: start = insert_end();
					break;
			case 5: start = delete_beg();
					break;
			case 6: start = delete_end();
					break;
		}
	}while(option !=7);
	return 0;
}
struct node* create_cll()
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter –1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num != -1)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = num;
		if(start == NULL)
		{
			new_node -> next = new_node;
			start = new_node;
		}
		else
		{ 
			ptr = start;
			while(ptr -> next != start)
				ptr = ptr -> next;
			ptr -> next = new_node;
			new_node -> next = start;
		}
		printf("\n Enter the data : ");
		scanf("%d", &num);
	}
	return start;
}
void display()
{
	struct node *ptr;
	ptr=start;
	while(ptr -> next != start)
	{
		printf("%d -> ", ptr -> data);
		ptr = ptr -> next;
	}
	printf("%d", ptr -> data);
	
}
struct node* insert_beg()
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = start;
	start = new_node;
	return start;
}
struct node* insert_end()
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> next = start;
	return start;
}
struct node* delete_beg()
{
	struct node *ptr, *temp;
	ptr = start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	temp = start;
	start = start -> next;
	temp -> next = NULL;
	ptr -> next = start;
	free(temp);
	return start;
}
struct node* delete_end()
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != start)
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	ptr -> next = NULL;
	free(ptr);
	return start;
}
