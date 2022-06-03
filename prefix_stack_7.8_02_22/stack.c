#include<stdio.h>
#include"stack.h"

void main()
{
	int top=0;
	int n=10;
	char s[n+1];
	char x,z,y;
	int i=1;
	int op,p;


	while(i != 0 || op != 5)
	{
		printf("Enter element for the operation you want to perform\n");
		printf("1.push\n2.pop\n3.peep\n4.change\n5.quit\n");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				printf("Enter Element to push:\n");
				//scanf("%c",&z);
				scanf("\n%c",&x);
				//char temp = getchar();
				i = push(s, &top, x, n);
				break;
			case 2: 
				//l = pop(s, &top);
				printf("Character popped: %c\n",pop(s,&top));
				break;
			case 3:
				printf("Enter the index of element :\n");
				scanf("%d",&p);
				printf("Value at %d is %c\n",p,peep(s, &top, p));
				break;
			case 4:
				printf("Enter the index of element you want to change: \n");
			        scanf("%d",&p);
				printf("Enter the value: \n");	
				scanf("\n%c",&x);
				i = change(s,&top,p,x);
				break;
			case 5: 
				printf("Thank you!!\n");
				i=0;
				break;
			default:
				printf("Enter valid number\n");
		}
	}
}


