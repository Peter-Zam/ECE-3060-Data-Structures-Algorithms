#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node* create_ll();
void display();
struct node* delete_beg();
struct node* delete_end();
struct node* delete_node();
struct node* delete_after();
struct node* delete_list();

int main() {
	int option;
	do
	{
		printf("\n*****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Delete a node from the beginning");
		printf("\n 4: Delete a node from the end");
		printf("\n 5: Delete a given node");
		printf("\n 6: Delete a node after a given node");
		printf("\n 7: Delete the entire list");
		printf("\n 8: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: start = create_ll();
					printf("\n LINKED LIST CREATED");
					break;
			case 2: display();
					break;
			case 3: start = delete_beg();
					break;
			case 4: start = delete_end();
					break;
			case 5: start = delete_node();
					break;
			case 6: start = delete_after();
					break;
			case 7: start = delete_list();
					printf("\n LINKED LIST DELETED");
					break;
		}
	}while(option != 8);
	
	return 0;
}
struct node* create_ll()
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter -1 to end");
	printf("\n Enter the data : ");
	scanf("%d", &num);
	while(num!=-1)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data=num;
		if(start==NULL)
		{
			new_node -> next = NULL;
			start = new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next = new_node;
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
	ptr = start;
	while(ptr != NULL)
	{
		printf("%d \t", ptr -> data);
		ptr = ptr -> next;
	}
	return start;
}
struct node* delete_beg()
{
	struct node *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	return start;
}
struct node* delete_end()
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != NULL)
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = NULL;
	free(ptr);
	return start;
}
struct node* delete_node()
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value of the node which has to be deleted : ");
	scanf("%d", &val);
	ptr = start;
	if(ptr -> data == val)
	{
		start = delete_beg();
		return start;
	}
	else
	{
		while(ptr -> data != val)
		{
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}
struct node* delete_after()
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value after which the node has to deleted : ");
	scanf("%d", &val);
	ptr = start;
	preptr = ptr;
	if (preptr -> data == val)
	{
		ptr = ptr -> next;
		preptr -> next = ptr -> next;
		free (ptr);
	}
	else 
	{
		while(preptr -> data != val)
		{
			preptr = ptr;
			ptr = ptr -> next;
		}
		if (ptr != NULL)
		{
			preptr -> next=ptr -> next;
			if (preptr == start)
				start = ptr -> next;
			free(ptr);
		}
		else
		{
			printf("\n The value after the node has to deleted is the last node.");
		}
	}
	return start;
}
struct node* delete_list()
{
	struct node *ptr; 
	if(start!=NULL)
	{
		ptr=start;
		while(ptr != NULL)
		{
			printf("\n %d is to be deleted", ptr -> data);
			start = delete_beg();
			ptr = start;
		}
	}
	return start;
}