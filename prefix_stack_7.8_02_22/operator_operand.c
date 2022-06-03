#include<stdio.h>
#include<string.h>

int precedance(char );
int push(char [], int *, int ,char [], int);
char pop(char [], int *);

void main()
{
	char str[100];
	int i=0, j=0,top_stack=0, top_output=0;

	printf("Enter the string: \n");
	scanf("%s",str);

//	char temp = getchar();

	int l = strlen(str);
	printf("length of string is:%d\n",l);

	char stack[l+1], output[l];

	
	while(i != l+1)
	{
			printf("Value of str[%d]: %c\n",i,str[i]); 

			if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '1' && str[i] <= '9'))
			{
				printf("Pushed in output\n");
				push(output, &top_output, i, str, l);
				printf("Value of output[%d]: %c\n",i+1,output[i+1]);
				i++;
				printf("Value of i in output push: %d\n",i); 
			}
			else
			{
				printf("In else operator\n");
				if(top_stack == 0)
				{
					printf("When stack is empty: pushing in stack\n");
					push(stack, &top_stack, i, str, l);
					printf("Value of stack[%d]: %c\n",j+1,stack[j+1]);
					i++;
					j++;
					printf("Value of i in stack push: %d\n",i); 
				}
				else
				{
					printf("Checking precedence\n");
					int n = precedance(str[i]);
					int s = precedance(stack[top_stack]);

					if(s >= n)
					{
						printf("Poping from stack pushing in output\n");
						pop(stack, &top_stack);
						push(output, &top_output, j, stack, l);
						printf("Value of output[%d]: %c\n",i+1,output[i+1]);
						//i++;
						j--;
						printf("Value of i&j in output push op: %d&%d\n",i,j); 
					}
					else if(s < n)
					{
						printf("pushing in stack\n");
						push(stack, &top_stack, i, str, l);
						printf("Value of stack[%d]: %c\n",j+1,stack[j+1]);
						i++;
						j++;
						printf("Value of j in stack push op: %d\n",j); 
					}
					else
					{
						push(output, &top_output, j, stack, l);
						printf("Value of output[%d]: %c\n",i+1,output[i+1]);
					}
				}
			}
	}

	for(int i=1; i <= l ; i++)
	{
		printf("output string : %c\n",output[i]);
	}
}

int precedance(char x)
{
	switch(x) {
		case '+':
			return 1;
		case '-': 
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
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
		printf("top = %d str=%c\n",*t,str[i]);
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

