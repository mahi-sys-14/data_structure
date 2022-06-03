/*
 *
 * Convert Sparse matrix to linear representation.
 *
 *
 */


#include<stdio.h>
#include<string.h>

void main()
{
	int row, col,count=0;

	printf("Enter the size of matrix:\n");
	scanf("%d %d",&row, &col);

	int mat[row][col];

	printf("Enter the elements of matrix:\n");
	for(int i=1; i<=row; i++)
	{
		for(int j=1; j<=col; j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}

	//printf("Row\t Column\t Value\n");
	for(int i=1; i<=row; i++)
	{
		for(int j=1; j<=col; j++)
		{
			if(mat[i][j] != 0)
			{
				//printf("%d\t   %d\t   %d\n",i,j,mat[i][j]);
				count++;
			}
		}
	}

	int b[3][count] ,k ,c=1;

	for(int i=1; i<=row; i++)
	{
		for(int j=1; j<=col; j++)
		{
			k=1;
			if(mat[i][j] != 0)
			{
				b[k++][c] = i;
				b[k++][c] = j;
				b[k][c] = mat[i][j];
				
				//printf("%d\t   %d\t   %d\n",i,j,mat[i][j]);
				c++;
			}
		}
	}

	printf("The linear representation is: \n");
	for(int k=1; k<=3; k++)
	{
		for(int l=1; l<=count; l++)
		{
			printf("%d\t",b[k][l]);
		}
		printf("\n");
	}

}
