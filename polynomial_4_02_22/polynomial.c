#include<stdio.h>
#include<string.h>

void main()
{
	int p[20], q[20];
	int deg1, deg2, size=0;

	printf("Enter the degree of 1st polynomial:\n");
	scanf("%d",&deg1);

	printf("Enter the coefficients of the 1st polynomial:\n");
	for(int i=deg1; i>=0; i--)
	{
		printf("Coefficient for x^%d:",i);
		scanf("%d",&p[i]);
	}
	
	printf("\n");

	printf("Enter the degree of 2nd polynomial:\n");
	scanf("%d",&deg2);
	
	for(int i=deg2; i>=0; i--)
	{
		printf("Coefficient for x^%d:",i);
		scanf("%d",&q[i]);
	}

	if(deg1>deg2)
	{
		size = deg1;
	}
	else
	{
		size = deg2;
	}

	printf("\n");
	
	printf("1st Polynomial equation is : \n");
	for(int j=deg1; j>=0;j--)
	{
		if(p[j] != 0)
		{
			if(j == 0)
			{
				printf("%d\n",p[j]);
			}
			else
			{
				printf("%dx^%d+",p[j],j);
			}
		}
	}
	printf("\n");

	printf("2nd Polynomial equation is : \n");
	for(int j=deg2; j>=0;j--)
	{
		if(q[j] != 0)
		{
			if(j == 0)
			{
				printf("%d\n",q[j]);
			}
			else
			{
				printf("%dx^%d+",q[j],j);
			}
		}
	}
	printf("\n");

	int sum[size];
	for(int i=size; i>=0; i--)
	{
		sum[i] = p[i] + q[i];
	}

	printf("Added polynomial equation is:\n");
	for(int i=size; i>=0; i--)
	{
		if(sum[i] != 0)
		{
			if(i == 0)
			{
				printf("%d\n",sum[i]);
			}
			else
			{
				printf("%dx^%d+",sum[i],i);
			}
		}
	}
	printf("\n");

}
