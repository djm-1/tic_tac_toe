#include<stdio.h>
char board[3][3];
bool checkcol(int j)
{
	int i;
		for(i=1;i<3;i++)
			if((board[i][j]!=board[0][j])||(board[i][j]==NULL))
				return false;
		return true;
		
}
bool checkrow(int i)
{
	int j;
	for(j=1;j<3;j++)
			if((board[i][j]!=board[i][0])||(board[i][j]==NULL))
				return false;
		return true;
}
bool checkdiag_1(int i)
{
	for(i=1;i<3;i++)
		if((board[i][i]!=board[0][0])||(board[i][i]==NULL))
			return false;
	return true;		
}
bool checkdiag_2(int i)
{
	for(i=1;i<3;i++)			
		if((board[i][2-i]!=board[0][2])||(board[i][2-i]==NULL))
				return false;
	return true;		
}
int main()
{
	int i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				board[i][j]=NULL;
			}
		}
	int count;
	bool game;
	for(count=1,game=true;game==true;count++)
	{
		if(count%2!=0)
		{
			printf("\n----TURN FOR PLAYER X----\n");
		}
		else
		{
			printf("\n----TURN FOR PLAYER O----\n");
		}
		int row,col;
		printf("where do you want to put your player?\n");
		printf("which row?----");
		scanf("%d",&row);
		printf("which coloumn?---");
		scanf("%d",&col);
		if(row>3||col>3)
		{
			printf("\nINVALID INPUT\n");
			break;
		}
		else if(board[row-1][col-1]=='X'||board[row-1][col-1]=='O')
		{
			printf("\nINVALID INPUT\n");
			break;
		}
		
		else
		{
				if(count%2!=0)
			{
				board[row-1][col-1]='X';
			}
			else
			{
				board[row-1][col-1]='O';
			}
		
		}
		
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%c ",board[i][j]);
			}
			printf("\n");
		}
		for(j=0;j<3;j++)
		{
			if(checkcol(j))
			{
				printf("\n----GAME OVER----\n");
				game=false;
				break;
			}
		}
		for(i=0;i<3;i++)
		{
			if(checkrow(i))
			{
				printf("\n----GAME OVER----\n");
				game=false;
				break;
			}
		}
		for(i=0;i<3;i++)
		{
			if(checkdiag_1(i))
			{
				printf("\n----GAME OVER----\n");
				game=false;
				break;
			}
		}
		for(i=1;i<3;i++)
		{
			if(checkdiag_2(i))
			{
				printf("\n----GAME OVER----\n");
				game=false;
				break;
			}
		}
	}
}

	
	

