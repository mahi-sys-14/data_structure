int push(char s[], int *t, char x, int n)
{
	if(*t>=n)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		*t = *t+1;
		printf("top = %d\n",*t);
		s[*t] = x;
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
		printf("top = %d\n",*t);
		return s[*t+1];
	}
}

char peep(char s[], int *t, int i)
{
	if(*t-i+1<=0)
	{
		printf("Stack underflow\n");
		return '0';
	}
	else
	{
		//*t = *t-1;
		printf("top = %d\n",*t);
		return s[*t-i+1];
	}
}

int change(char s[], int *t, int i, char value)
{
	if(*t-i+1<=0)
	{
		printf("Stack underflow\n");
		return 0;
	}
	else
	{
		//*t = *t-1;
		s[*t-i+1] = value;
		printf("top = %d\n",*t);
		return 1;
	}
}

