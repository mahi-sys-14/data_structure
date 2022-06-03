#include<stdio.h>
#include<string.h>

void main()
{
	char p[20], q[20];
	int *x1[20], x2[20], i=0, count = 1;
	//char *token;

	printf("Enter the 1st polynomial equation:\n");
	scanf("%s",p);

	printf("Enter the 2nd polynomial equation:\n");
	scanf("%s",q);

	printf("\n");

	char *token = strtok(p,"+");
	//printf("%s\n",token);
	//x1+i = token;
	while(token != NULL)
	{
		//i++;
		//count++;
		//x1+i = token;
		printf("%s\n",token);
		token = strtok(NULL,"+");
	}
/*
	printf("Array elements\n");
	for(int j=0; j<count; j++)
	{
		printf("%d",*(x1+j));
	}
*/
	

}
