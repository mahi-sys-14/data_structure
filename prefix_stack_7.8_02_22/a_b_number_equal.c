#include<stdio.h>
#include<string.h>

int push(char [], int *, char , int);
char pop(char [], int *);

void main()
{
	int top=0;
	char str[100];
	int i=0;
	int a=0,b=0;

	printf("Enter the string to check palindrome: \n");	
	scanf("%s",str);

	int length = strlen(str);
	char s[length+1];


	while(str[i] != 'b')
	{
		push(s, &top, str[i], length);
		i++;
		a++;

	}

	printf("Value of index is i=%d top=%d\n",i,top);
	
	while(i<length)
	{
		//printf("In while: i=%d top=%d\n",i,top);	
		//printf("popped element is %c\n",pop(s,&top));
		if(str[i] == 'b')
		{	
			b++;
		}
		i++;	
	}

	if(a == b)
	{
		printf("a & b is equal\n");
	}
	else
	{
		printf("a & b are not equal\n");
	}

}

int push(char s[], int *t, char str, int length)
{
	if(*t>=length)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		*t = *t+1;
		printf("top = %d str=%c\n",*t,str);
		s[*t] = str;
		return 1;
	}
}

char pop(char s[], int *t)
{
	if(*t==0)
	{
		printf("Stack underflow\n");
		return '0';
	}
	else
	{
		*t = *t-1;
		//printf("top = %d\n",*t);
		return s[*t+1];
	}
}

