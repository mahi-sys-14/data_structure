#include<stdio.h>

int enqueue(int [], int *, int *, int, int);
int dequeue(int [], int *, int *, int);
void display(int [], int *, int *, int);

void main()
{
	int n;

	printf("Enter the size of queue:\n");
	scanf("%d",&n);
	
	int q[n];
	int i, f=0, r=0, value,op,y, a=1, index;

	while(a != 0)
	{

	printf("Enter number to number operation:\n");
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\n");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
			printf("Enter number to enqueue:\n");
			scanf("%d",&y);
			enqueue(q,&f,&r,y,n);
			break;
		case 2:
			printf("Deleted element is %d\n",dequeue(q, &f, &r,n));
			break;
		case 3:
			printf("Enter the index of element to display:\n");
			scanf("%d",&index);
			display(q,&f, &r,index);
			break;
		case 4:
			a=0;
			printf("Thank you!\n");
			break;
		default:
			printf("Enter Valid number\n");
	}

	}

}

int enqueue(int s[], int *f, int *r, int x, int n)
{
	if(*r == n)
	{
		*r = 1;
	}
	else
	{
		*r = *r+1;
	}

	if(*f == *r)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		s[*r] = x;
		printf("*r=%d\n",*r);

		if(*f == 0)
		{
			*f = *f+1;
			printf("*f=%d\n",*f);
		}
		return 1;
	}

}

int dequeue(int s[], int *f, int *r, int n)
{
	if(*f == 0)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	else
	{
		int z = s[*f];
		if(*f == *r)
		{
			*f=*r=0;
		}
		
		if(*f == n)
		{
			*f = 1;
		}
		else
		{
			*f = *f+1;
			printf("*f=%d\n",*f);
		}

		return z;
	}
}

void display(int s[], int *f, int *r, int i)
{
	printf("Element on index %d is %d\n",i,s[i]);
}
