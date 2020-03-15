#include <stdio.h>
#define size 10
int main()
{
	int marks[size][size], studnum, subnum, i, j, max_marks;
	printf("Enter the number of students: ");
	scanf("%d",&studnum);
	printf("Enter the number of subjects: ");
	scanf("%d", &subnum);
	for(i=0; i<studnum; i++)
	{
		printf("\n Enter the marks obtained by student %d",i+1);
		for(j=0; j<subnum; j++)
		{
			printf("\n marks[%d][%d] = ", i, j);
			scanf("%d", &marks[i][j]);
		}
	}
	printf("Students' Marks are \n\n");
    printf(" Subjects   ");
    for(j=0; j<subnum; j++)
    {
    	printf(" %d ", j+1);
    }
    printf("\n");
	for(i = 0; i<studnum; i++)
    {
		printf(" Student %d [ ", i+1);
		for(j = 0; j < subnum; j++)
        {
			printf("%d ", marks[i][j]);
   		}
        printf("]");
        printf("\n");  
     }
	return 0;
}
