/*
 *
 * Identify either sparse matrix or linear representation is better by comparing non zero enteries with sparse matrix
 *
 */


#include<stdio.h>

void main()
{
	int row, col, nonzero;

	printf("Enter number of rows and columns:\n");
	scanf("%d %d",&row, &col);

	printf("Number of non zero enteries:\n");
	scanf("%d",&nonzero);

	int result=0, real;

	result = nonzero*3;
	real = row*col;

	if(real>result)
	{
		printf("Linear representation is better\n");
	}
	else
	{
		printf("Sparse is better\n");
	}

}

