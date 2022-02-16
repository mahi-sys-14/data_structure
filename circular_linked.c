#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};
/*
struct node *insert_at_begin(struct node *,struct node *, int);
struct node *insert_at_end(struct node *,struct node *, int);
struct node *insert_in_bw(struct node *, struct node *,int);
void display(struct node *, struct node *);
*/

void insert_at_begin(int);
void insert_at_end(int);
void insert_in_bw(int);

int delete_node(int);
void display();

struct node *start = NULL;
struct node *end = NULL;

void main()
{
	int x, flag=0, ch, c=0;

	while(flag != 1)
	{

		printf("Enter the choice:\n");
		printf("1.Inser at beginning\n2.Insert at end\n3.Insert in between\n4.Display\n5.Delete node\n6.quit\n\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the value to insert:\n");
				scanf("%d",&x);
				insert_at_begin(x);
				printf("start->info:%d\t end->info:%d\n",start->info, end->info);
				break;
			case 2:
				printf("Enter Value to insert at end:\n");
				scanf("%d",&x);
				insert_at_end(x);
				printf("start->info:%d\t end->info:%d\n",start->info, end->info);
				break;
			case 3:
				printf("Enter Value to insert in between:\n");
				scanf("%d",&x);
				insert_in_bw(x);
				printf("start->info:%d\t end->info:%d\n",start->info, end->info);
				break;
			case 4:
				printf("ALL elements of linked list are:\n");
				display();
				break;
			case 5:
				printf("Enter element you want to delete\n");
				scanf("%d",&x);
				delete_node(x);
				break;
			case 6:
				flag = 1;
				printf("Thank you!!\n");
				break;
			default:
				printf("Enter valid number\n");
		}
	}
}

void insert_at_begin(int value)
{

	struct node *new_node;

	new_node = (struct node *)malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		new_node->info = value;

		if(start == NULL)
		{
			new_node->link = new_node;
			start = end = new_node;
			//printf("start->info: %d\t end->info: %d\n", start->info, end->info);
		}
		else
		{
			//printf("Insert other elements at begining\n");
			//printf("before start->info: %d\t end->info: %d\n",start->info, end->info);

			new_node->link = start;
			end->link = new_node;
			start = new_node;

			//printf("start->info: %d\t end->info: %d\n",start->info, end->info);
			//printf("Inserted new node at front\n");
		}
	}
}

void display()
{
	struct node *save = (struct node *)malloc(sizeof(struct node));
	save = start;

	//printf("Display==>> start->info: %d\t end->info: %d\n",start->info, end->info);

	if(start == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(save->link != start)
		{
			printf("==>>%d\n",save->info);
			save = save->link;
			//printf("after: %d\n",save->info);
			//char temp = getchar();
		}
		printf("==>>%d\n",save->info);
	}
}

void insert_at_end(int value)
{
	struct node *new_node;
	new_node = (struct node *)malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		if(end == NULL)
		{
			new_node->info = value;
			new_node->link = new_node;
			start = end = new_node;

			//printf("if End==>> start->info: %d\t end->info: %d\n",start->info,end->info);
		}
		else
		{
			new_node->info = value;
			new_node->link = end->link;
			end->link = new_node;
			end = new_node;

			//printf("Else End==>> start->info: %d\t end->info: %d\n",start->info,end->info);
		}
	}
}

void insert_in_bw(int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *save;

	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		new_node->info = value;
		//printf("New node info : %d\n",new_node->info);

		if(start == NULL)
		{
			//printf("If start = NULL\n");
			new_node->link = new_node;
			start = end = new_node;
			//printf("b/w==>> start->info: %d\t end->info: %d\n",start->info,end->info);
		}
		else
		{
			//printf("start->info : %d\n",start->info);

			if(new_node->info <= start->info)
			{
				//printf("Else If new_node->info <= start->info\n");
				new_node->link = start;
				end->link = new_node;
				start = new_node;
				//printf("else b/w==>> start->info: %d\t end->info: %d\n",start->info,end->info);
			}
			else
			{
				//printf("else: traverse list to insert in between\n");
				save = start;
				//printf("b/w save==>> start->info: %d\t end->info: %d\n",start->info,end->info);

				while(save != end && new_node->info >= save->link->info)
				{
					save = save->link;
				}
				
				if(save == end)
				{
					//printf("Insert at end\n");
					new_node->link = start;
					save->link = new_node;
					//printf("sa=la==>> start->info: %d\t end->info: %d\n",start->info,end->info);
					end = new_node;
				}
				else
				{
					//printf("Insert in b/w\n");
					new_node->link = save->link;
					save->link = new_node;
					//printf("Else else==>> start->info: %d\t end->info: %d\n",start->info,end->info);

				}
			}
		}
	}
}

int delete_node(int value)
{
	struct node *save;
	struct node *pred;

	if(start == NULL)
	{
		printf("Underflow\n");
		return -1;
	}
	else
	{
		save = start;

		while(save->info != value && save != end)
		{
			pred = save;
			save = save->link;
		}

		if(save->info != value)
		{
			printf("Node not found\n");
			return -1;
		}

		if(value == start->info)
		{
			start = start->link;
			end->link = start;
		}
		else
		{
			pred->link = save->link;
			if(value == end->info)
			{
				end = pred;
			}
		}

		free(save);
		return 0;
	}

}
