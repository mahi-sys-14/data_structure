/*
 *
 *Calculation of address of an element in 1D array. Take base address, index of the element for which users want to find an address.
 *
 */


#include<stdio.h>

void main()
{
	int ba, i, size, addr=0;

	printf("Enter the base address: \n");
	scanf("%d",&ba);

	printf("Enter the element number for address: \n");
	scanf("%d",&i);

	printf("Enter the size of one element: \n");
	scanf("%d",&size);

	addr = ba + (i-1)*size;

	printf("Address of %d element is %d\n",i,addr);

}


