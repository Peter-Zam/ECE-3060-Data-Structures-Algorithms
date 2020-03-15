#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node* create_ll();

void main() {
	int option;
	do
	{
		printf("\n\n*****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: start = create_ll();
					printf("\n LINKED LIST CREATED");
					break;
			
			
		}
	}while(option != 2);
	

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

