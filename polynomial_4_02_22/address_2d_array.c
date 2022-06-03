/*
 *
 * Calculation of address of an element in 2d array for both row major and column major. Take base address, total number of rows and columns , index(i,j) of the element and either row or column major for which users want to find an address.
 *
 *
 */


#include<stdio.h>

void main()
{
	int ba, row, col, i, j, size, addr=0, major;
	
	printf("Enter the 0 for row 1 for column major: \n");
	scanf("%d",&major);
	
	printf("Enter the base address: \n");
	scanf("%d",&ba);

	printf("Enter the number of rows: \n");
	scanf("%d",&row);

	printf("Enter the number of columns: \n");
	scanf("%d",&col);

	printf("Enter the element number i for address: \n");
	scanf("%d",&i);

	printf("Enter the element number j for address: \n");
	scanf("%d",&j);

	printf("Enter the size of one element: \n");
	scanf("%d",&size);

	if(major == 1)
	{
		addr = ba + ((i-1) + (j-1)*row)*size;
		printf("Address of column major %d element is %d\n",i,addr);
	}
	else
	{
		addr = ba + ((i-1)*col + (j-1))*size;	
		printf("Address of row major %d & %d element is %d\n",i,j,addr);

	}
}


