#include <stdio.h>
#define size 20
void bubblesort(int arr[], int n);
int main()
{
	int arr[size], num, i, n, beg, end, mid, pos=-1;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the elements: ");
		scanf("%d", &arr[i]);
	}
	printf("Sorted Array is ");
	bubblesort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\n Enter the number that has to be searched: ");
	scanf("%d", &num);
	beg = 0, end = n-1;
	while(beg<=end)
	{
		mid = (beg + end)/2;
		if (arr[mid] == num)
		{
			pos=mid+1;
			printf("\n %d is present in the array at position %d\n", num, pos);
			break;
		}
		else if (arr[mid]>num)
			end = mid-1;
		else
			beg = mid+1;
	}
	if (pos == -1)
		printf("\n %d does not exist in the array\n", num);
	return 0;
}
void bubblesort(int arr[],int n)
{
	int temp,i,j;
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
