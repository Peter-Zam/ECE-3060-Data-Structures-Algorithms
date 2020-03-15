#include <stdio.h>
#define size 10
//void bubble_sort(int arr[], int n);
//void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
int main()
{
	int i, n, arr[10];
	printf("\n Enter the number of elements in the array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the elements: ");
		scanf("%d", &arr[i]);
	}
	//bubble_sort(arr,n);
	//insertion_sort(arr, n);
	selection_sort(arr, n);
	printf("\n The array sorted in ascending order is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}

/*
void bubble_sort(int arr[], int n)
{
	int i, j, temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
*/

/*
void insertion_sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++) 
	{
		temp = arr[i];
		j = i - 1;
 		while (temp < arr[j] && j >= 0) 
 		{
 			arr[j+1] = arr[j];
 			j = j - 1;
 		}
 		arr[j+1] = temp;
	}
}
*/

void selection_sort(int arr[], int n)
{
	int i, j, temp, min;
	for (i = 0; i < n; i++) 
	{
		min=i;
		for (j=i+1; j<n ; j++)
 		{
 			if (arr[j]<arr[min])
 			{
			 	min=j;
			}
		}
		 temp = arr[i];
 		 arr[i] = arr[min];
 		 arr[min] = temp;
	}
}
