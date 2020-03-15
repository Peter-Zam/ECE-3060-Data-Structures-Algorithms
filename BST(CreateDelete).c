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
void inorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
int main()
{
	int option, val, dval, count=0;
	struct node *ptr;
	do
	{
		printf("\n ******MAIN MENU******* \n");
		printf("\n 1. Insert Element");
		printf("\n 2. Inorder Traversal");
		printf("\n 3. Find the smallest element");
		printf("\n 4. Find the largest element");
		printf("\n 5. Delete an element");
		printf("\n 6. Exit");
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
					printf("\n Inorder Traversal : ");
					inorderTraversal(root);
					break;
			case 3:
					ptr = findSmallestElement(root);
					if (ptr != NULL)
						printf("\n Smallest element is : %d",ptr->data);
					break;
			case 4:
					ptr = findLargestElement(root);
					if (ptr != NULL)
						printf("\n Largest element is : %d", ptr->data);
					break;
			case 5:
					printf("\n Enter the element to be deleted : ");
					scanf("%d", &dval);
					root = deleteElement(root, dval);
					printf("\nThe element is deleted...");
					break;
		
		}
	}while(option!=6);

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
void inorderTraversal(struct node *root)
{
	if(root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}
struct node *findSmallestElement(struct node *root)
{
	if (root == NULL)
	{
		printf("Binary Search Tree is Empty\n");
		return root;
	}
	else if(root->left == NULL)
		return root;
	else
		return findSmallestElement(root->left);
}
struct node *findLargestElement(struct node *root)
{
	if (root == NULL)
	{
		printf("Binary Search Tree is Empty\n");
		return root;
	}
	else if(root->right == NULL)
		return root;
	else
		return findLargestElement(root->right);
}
struct node *deleteElement(struct node *root, int dval)
{
	if(root==NULL)
	{
		printf("\n The tree is empty ");
		return root;
	}
	else if(dval < root->data)
		root->left = deleteElement(root->left,dval);
	else if(dval > root->data)
		root->right = deleteElement(root->right,dval);
	else
	{
		// No child
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root=NULL;
		}
		//One child
		else if(root->left == NULL)
		{
			struct node *temp;
			temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			struct node *temp;
			temp = root;
			root = root->left;
			free(temp);
		}
		//Two children
		else
		{
			struct node *temp;
			temp = findSmallestElement(root->right);
			root->data = temp->data;
			root->right = deleteElement(root->right, temp->data);
		}
	}
	return root;
}