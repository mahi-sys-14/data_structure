#include<stdio.h>

int enqueue(int [], int *, int *, int, int);
int dequeue(int [], int *, int *);
void display(int [], int *, int *);

void main()
{
	int n;

	printf("Enter the size of queue:\n");
	scanf("%d",&n);
	
	int q[n];
	int i, f=0, r=0, value,op,y, a=1;

	while(a != 0)
	{

	printf("Enter number to number operation:\n");
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\n");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
			printf("Enter number tp enqueue:\n");
			scanf("%d",&y);
			enqueue(q,&f,&r,y,n);
			break;
		case 2:
			printf("Deleted element is %d\n",dequeue(q, &f, &r));
			break;
		case 3:
			printf("Enter the index of element to display:\n");
			display(q,&f, &r);
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

int enqueue(int s[], int *f, int *r, int x, int l)
{
	
/*	if(*f = 0)
	{
		*f = *f+1;
	}
*/	
	if(*r >= l)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		*r = *r + 1;
		printf("*r=%d\n",*r);

		s[*r] = x;

		if(*f == 0)
		{
			*f = *f+1;
			printf("*f=%d\n",*f);
		}

		return 1;
	}

}

int dequeue(int s[], int *f, int *r)
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
		else
		{
			*f = *f+1;		
			printf("*f=%d\n",*f);

		}

		return z;
	}
}

void display(int s[], int *f, int *r)
{
	for(int i=*f; i<=*r; i++)
	{
		printf("Element s[%d] : %d\n",i,s[i]);
	}
}
