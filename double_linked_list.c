#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lptr;
	struct node *rptr;
};

struct node *insert(struct node *, struct node *, int, int);
struct node *delete(struct node *, struct node *, int);
void display(struct node *, struct node *);

void main()
{
	struct node *left = NULL;
	struct node *right = NULL;
	
	int ch, flag=0, M, value;

	while(flag != 1)
	{
		printf("\nEnter the choice:\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Quit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the position of M for inserting\n");
				scanf("%d",&M);
				printf("Enter the element you want to insert\n");
				scanf("%d",&value);
				left = insert(left, right, M, value);
				break;
			case 2:
				printf("Enter element to delete node:\n");
			        scanf("%d",&value);
				left = delete(left, right, value);
				break;
			case 3:
				display(left, right);
				break;
			case 4:
				flag = 1;
				printf("Thank you!!\n");
				break;
			default:
				printf("Enter Valid choice\n");
		}
	}

}

void display(struct node *l, struct node *r)
{
	struct node *save = (struct node *)malloc(sizeof(struct node));

	save = l;

	do
	{
		printf("==>>%d\n",save->info);
		save = save->rptr;
	}while(save != NULL);

}

struct node *insert(struct node *l, struct node *r, int M, int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *save = (struct node *)malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		new_node->info = value;

		if(l == NULL)
		{
			printf("Inserting new node\n");
			new_node->lptr = new_node->rptr = NULL;
			l = r = new_node;
			printf("M = %d\t l->info=%d\t r->info=%d\n",M,l->info,r->info);
			return new_node;
		}
		else
		{
			printf("In else condition\n");
			//printf("M = %d\t l->info=%d\t r->info=%d\n",M,l->info,r->info);

			if(M == l->info)
			{
				printf("Inserting at beginning");
				// Insert at beginning
				new_node->lptr = NULL;
				new_node->rptr = l;
				l->lptr = new_node;
				l = new_node;
				printf("M = %d\t l->info=%d\t \n",M,l->info);
				return l;
			}
			/*
			else if(M == r->info)
			{
				printf("Inserting at end\n");
				new_node->rptr = NULL;
				new_node->lptr = r;
				r->rptr = new_node;
				r = new_node;
				return l;
			}*/
			else
			{
				printf("Inserting before a specified node\n");
				// Insert After
				save = l;
				while(save->rptr != NULL && M != save->rptr->info)
				{
					save = save->rptr;
				}

				save = save->rptr;

				new_node->lptr = save->lptr;
				new_node->rptr = save;
				save->lptr = new_node;
				new_node->lptr->rptr = new_node;

				return l;
			}
		}
	}

}


struct node *delete(struct node *l, struct node *r, int value)
{
	struct node *save = (struct node *)malloc(sizeof(struct node));

	if(l == NULL)
	{
		printf("Underflow\n");
		//return -1;
	}
	else
	{
		if(value == l->info)
		{
			l = l->rptr;
			l->lptr = NULL;
			return l;
		}
		/*
		else if(value == r->info)
		{
			r = r->lptr;
			r->rptr = NULL;
			return r;
		}*/
		else
		{
			save = l;

			while(save->rptr != NULL && value != save->rptr->info)
			{
				save = save->rptr;
			}

			save = save->rptr;
		
			if(save->rptr == NULL)
			{
				printf("If last save->info:%d\t save->lptr:%p\t \n",save->info,save->lptr);
				save->lptr->rptr = NULL;
				//r = save;
			}
			else
			{
				printf("save->info:%d\t save->lptr:%p\t \n",save->info,save->lptr);
				save->lptr->rptr = save->rptr;
				save->rptr->lptr = save->lptr;
			}

			free(save);
			return l;
		}
	}
}
