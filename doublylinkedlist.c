#include <stdio.h>
#include <malloc.h>
struct node
{
	struct node *next;
	int data;
	struct node *prev;
};
struct node *start = NULL;
struct node *create_dll();
void display();
struct node *insert_beg();
struct node *insert_end();
struct node *insert_before();
struct node *insert_after();
struct node *delete_beg();
struct node *delete_end();
struct node *delete_before();
struct node *delete_after();

int main()
{
	int option;
	do
	{
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");
		printf("\n 5: Add a node before a given node");
		printf("\n 6: Add a node after a given node");
		printf("\n 7: Delete a node from the beginning");
		printf("\n 8: Delete a node from the end");
		printf("\n 9: Delete a node before a given node");
		printf("\n 10: Delete a node after a given node");
		printf("\n 11: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: start = create_dll();
					printf("\n DOUBLY LINKED LIST CREATED");
					break;
			case 2: display();
					break;
			case 3: start = insert_beg();
					break;
			case 4: start = insert_end();
					break;
			case 5: start = insert_before();
					break;
			case 6: start = insert_after();
					break;
			case 7: start = delete_beg();
					break;
			case 8: start = delete_end();
					break;
			case 9: start = delete_before();
					break;
			case 10: start = delete_after();
					break;
			
		}
	}while(option != 11);

	return 0;
}
struct node *create_dll()
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter –1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num != -1)
	{
		if(start == NULL)
		{
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> prev = NULL;
			new_node -> data = num;
			new_node -> next = NULL;
			start = new_node;
		}
		else
		{
			ptr=start;
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node -> data=num;
			while(ptr -> next!=NULL)
				ptr = ptr -> next;
			ptr -> next = new_node;
			new_node->prev=ptr;
			new_node->next=NULL;
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
	printf("%d",ptr->data);
	while(ptr->next!=NULL)
	{
		ptr = ptr -> next;
		printf(" <=> %d", ptr -> data);
	}
	
}
struct node *insert_beg()
{
	struct node *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	start -> prev = new_node;
	new_node -> next = start;
	new_node -> prev = NULL;
	start = new_node;
	return start;
}
struct node *insert_end()
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr=start;
	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node;
	new_node -> prev = ptr;
	new_node -> next = NULL;
	return start;
}
struct node *insert_before()
{
	struct node *new_node, *ptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value before which the data has to be inserted:");
	scanf("%d", &val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> data != val)
		ptr = ptr -> next;
	ptr -> prev -> next = new_node;
	new_node -> next = ptr;
	ptr -> prev = new_node;
	new_node -> prev = ptr-> prev;
	return start;
}
struct node *insert_after()
{
	struct node *new_node, *ptr;
	int num, val;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	printf("\n Enter the value after which the data has to be inserted:");
	scanf("%d", &val);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr = start;
	while(ptr -> data != val)
		ptr = ptr -> next;
	ptr -> next -> prev = new_node;
	new_node -> next = ptr -> next;
	ptr -> next = new_node;
	new_node -> prev = ptr;
	return start;
}
struct node *delete_beg()
{
	struct node *ptr;
	ptr = start;
	start = start -> next;
	start -> prev = NULL;
	free(ptr);
	return start;
}
struct node *delete_end()
{
	struct node *ptr;
	ptr = start;
	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> prev -> next = NULL;
	free(ptr);
	return start;
}
struct node *delete_after()
{
	struct node *ptr, *temp;
	int val;
	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	while(ptr -> data != val)
		ptr = ptr -> next;
	temp = ptr -> next;
	ptr -> next = temp -> next;
	temp -> next -> prev = ptr;
	free(temp);
	return start;
}
struct node *delete_before()
{
	struct node *ptr, *temp;
	int val;
	printf("\n Enter the value before which the node has to deleted:");
	scanf("%d", &val);
	ptr = start;
	while(ptr -> data != val)
		ptr = ptr -> next;
	temp = ptr -> prev;
	if(temp == start)
	{
		start = delete_beg(start);
	}
	else
	{
		ptr -> prev = temp -> prev;
		temp -> prev -> next = ptr;
	}
	free(temp);
	return start;
}

