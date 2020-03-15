#include <stdio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node* create_bst(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
int main()
{
	int option, val;
	struct node *ptr;
	do
	{
		printf("\n ******MAIN MENU******* \n");
		printf("\n 1. Insert Element");
		printf("\n 2. Preorder Traversal");
		printf("\n 3. Inorder Traversal");
		printf("\n 4. Postorder Traversal");
		printf("\n 5. Exit");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
					printf("\n Enter the value of the new node : ");
					scanf("%d", &val);
					root = create_bst(root, val);
					break;
			case 2:
					printf("\n Preorder Traversal : ");
					preorderTraversal(root);
					break;
			case 3:
					printf("\n Inorder Traversal : ");
					inorderTraversal(root);
					break;
			case 4:
					printf("\n Postorder Traversal : ");
					postorderTraversal(root);
					break;
			
		}
	}while(option!=5);

	return 0;
}

struct node* create_bst(struct node *root, int val)
{
	struct node *new_node;
	if(root==NULL)
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node->data = val;
		new_node->left = NULL;
		new_node->right = NULL;
		root=new_node;
	}
	else{
		if (val < root->data)
			root->left = create_bst(root->left, val);
		else
			root->right = create_bst(root->right, val);
	}
	return root;
}
void preorderTraversal(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
void inorderTraversal(struct node *root)
{
	if(root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}
void postorderTraversal(struct node *root)
{
	if(root != NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ", root->data);
	}
}