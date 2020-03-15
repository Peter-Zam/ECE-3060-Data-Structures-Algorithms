#include <stdio.h>
#define size 10
int main()
{
	int arr[size], num, i, n, pos = -1;
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the elements: ");
		scanf("%d", &arr[i]);
	}
	printf("\n Enter the number that has to be searched : ");
	scanf("%d", &num);
	for(i=0;i<n;i++)
	{
		if(arr[i] == num)
		{
			pos=i+1;
			printf("\n %d is found in the array at position %d \n", num,pos);
		}
	}
	if (pos == -1)
		printf("\n %d does not exist in the array\n", num);
	
	return 0;
}