#include<stdio.h>
#include<string.h>

int push(char [], int *, int ,char [], int);
char pop(char [], int *);

void main()
{
	int top=0;
	char str[100];
	//char s[n+1];
	char x,z,y;
	int i=0;
	int op,p;
	int flag=1;

	printf("Enter the string to check palindrome: \n");	
	scanf("%s",str);

	int length = strlen(str);
	char s[length+1];


	while(length/2 != i)
	{
		push(s, &top, i, str, length);
		i++;
	}


	if(length%2 == 0)
	{
		//printf("Value of index is i=%d top=%d\n",i,top);
	}
	else
	{
		i++;
		//printf("Value of index is i=%d top=%d\n",i++,top);
	}
	
	while(top != 0)
	{
		//printf("In while: i=%d top=%d\n",i,top);
		if(s[top] ==  str[i])
		{
			printf("popped element is %c\n",pop(s,&top));
			i++;
		}
		else
		{
			//printf("In else\n");
			flag = 0;
			break;
		}
	}

	if(flag == 1)
	{
		printf("String is palindrome\n");
	}
	else
	{
		printf("String is not palindrome\n");
	}

}

int push(char s[], int *t, int i, char str[], int length)
{
	if(*t>=length)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		*t = *t+1;
		//printf("top = %d str=%c\n",*t,str[i]);
		s[*t] = str[i];
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

