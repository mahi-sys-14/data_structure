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
struct node *delete(struct node *, int);

void main()
{
	struct node *t = NULL;
	int n, in;

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
		printf("Value of a[%d]: %d\n",i, a[i]);
		t = bst(t, a[i]);
		//inorder(t);
	}

	printf("Printing binary tree inorder:\n");
	inorder(t);
	printf("\n");

	printf("Enter node value to delete:\n");
	scanf("%d",&in);

	t = delete(t, in);

	inorder(t);

	printf("\n");
}

struct node *minValueNode(struct node *head)
{
	struct node *current = head;

	while(current && current->lptr != NULL)
	{
		current = current->lptr;
	}

	return current;
}

struct node *delete(struct node *head, int value)
{
	struct node *pred;

	if(head == NULL)
	{
		printf("Underflow\n");
		return NULL;
	}



		if(value < head->data && head->lptr != NULL)
		{
			//printf("lptr: head->data:%d\n",head->data);
			head->lptr = delete(head->lptr, value);
		}
		else if(value > head->data && head->rptr != NULL)
		{
			//printf("rptr: head->data:%d\n",head->data);
			head->rptr = delete(head->rptr, value);
		}
		else
		{
			if(head->lptr == NULL)
			{
				//printf("In head->lptr == NULL\n");
				struct node *temp = head->rptr;
				free(head);
				return temp;
			}
			else if(head->rptr == NULL)
			{
				//printf("In head->rptr == NULL\n");
				struct node *temp = head->lptr;
				free(head);
				return temp;
			}
			else
			{
				struct node *temp = minValueNode(head->rptr);

				head->data = temp->data;

				head->rptr = delete(head->rptr, temp->data);
			}

		}

	/*
	else
	{
		printf("In else head->data:%d\t \n",head->data);
		if(head->lptr == NULL && head->rptr == NULL)
		{
			printf("head->data:%d\t \n",head->data);
			//pred->rptr = NULL;
			//pred->lptr = NULL;
			free(head);
		}
	}
	*/

	return head;
}

struct node *bst(struct node *head, int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));

	if(new_node == NULL)
	{
		printf("Overflow!\n");
		return NULL;
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

	printf("%d ",head->data);

	if(head->rptr != NULL)
	{
		//printf("\nhead->rptr: %d \n",head->rptr->data);
		inorder(head->rptr);
	}

}

