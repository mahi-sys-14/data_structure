#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lptr;
	struct node *rptr;
};

struct node *bst(struct node *, int );
void inorder(struct node *);
int search(struct node *, int);

void main()
{
	struct node *t = NULL;
	int n, search_value, flag = 0;

	printf("Enter the number of elements:\n");
	scanf("%d",&n);

	int a[n];
	printf("Enter values to create binary tree:\n");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}

	for(int i=0; i<n; i++)
	{
		//printf("Value of a[%d]: %d\n",i, a[i]);
		t = bst(t, a[i]);
		//inorder(t);
	}

	printf("Printing binary tree inorder:\n");
	inorder(t);
	printf("\n");

	printf("Enter the node value you want to search:\n");
	scanf("%d",&search_value);
	
	//printf("t->data: %d\n",t->data);

	flag = search(t, search_value);
	if(flag == 1)
		printf("Node exist\n");
	else
		printf("Node doesn't exist\n");
}

struct node *bst(struct node *head, int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Overflow!\n");
	}
	

		if(head == NULL)
		{
			//printf("Inserted head node\n");
			new_node->data = value;
			new_node->lptr = NULL;
			new_node->rptr = NULL;
			head = new_node;
			return head;
		}
		else
		{
			//printf("In else\n");

			if(value < head->data && head->lptr == NULL)
			{
				//printf("Inserting in left when head->lptr == NULL\n");
				new_node->data = value;
				head->lptr = new_node;
				new_node->lptr = new_node->rptr = NULL;
			}
			else if(value < head->data && head->lptr != NULL)
			{
				//printf("Inserting in left when head->lptr != NULL\n");
				bst(head->lptr, value);
			}
			
			if(value > head->data && head->rptr == NULL)
			{
				//printf("Inserting in right when head->rptr == NULL\n");
				new_node->data = value;
				new_node->lptr = new_node->rptr = NULL;
				head->rptr = new_node;
			}
			if(value > head->data && head->rptr != NULL)
			{
				//printf("Inserting in right when head->rptr != NULL\n");
				bst(head->rptr, value);
			}
		}


	//printf("head->info: %d\n", head->data);

	return head;
}

int search(struct node *head, int value)
{
	if(head == NULL)
	{
		printf("Underflow\n");
	}

	if(value != head->data)
	{
		//printf("Yes Node exist\n");

		if(value < head->data && head->lptr != NULL)
		{
			search(head->lptr, value);
		}
		else if(value > head->data && head->rptr != NULL)
		{
			search(head->rptr, value);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 1;
	}

}

void inorder(struct node *head)
{
	if(head == NULL)
	{
		printf("Inorder Empty Tree!!\n");
	}

	if(head->lptr != NULL)
	{
		//printf("\nhead->lptr: %d \n",head->lptr->data);
		inorder(head->lptr);
	}

	printf("%d \n",head->data);

	if(head->rptr != NULL)
	{
		//printf("\nhead->rptr: %d \n",head->rptr->data);
		inorder(head->rptr);
	}

}

