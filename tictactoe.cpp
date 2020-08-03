#include<iostream>
using namespace std;

char square[3][3];
void board()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<square[i][j]<<"|";
		}
		cout<<endl;
		cout<<"------"<<endl;
	}
}
char inst()
{
	char x;
	square[0][0]=' ';square[0][1]=' ';square[0][2]=' ';square[1][0]=' ';square[1][1]=' ';square[1][2]=' ';square[2][0]=' ';square[2][1]=' ';square[2][2]=' ';
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<square[i][j]<<"|";
		}
		cout<<endl;
				cout<<"------"<<endl;

	}
	cout<<"Choose X or O";
	label:
	cin>>x;
	if(x!='X'&& x!='O')
	{
		cout<<"Choose accordingly";
		goto label;
	}
	else
	return x;
}
void getmove(char move , int player_no)
{
	
	int x;
	cout<<"Enter cell number player "<<player_no;
	cin>>x;
	if(x>9)
	{
	cout<<"Enter limit in range"<<endl;
	getmove(move,player_no);
	return;
	}
	switch(x)
	{
		
		case 1: if(square[0][0]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[0][0]=move;
				break;
		case 2: if(square[0][1]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[0][1]=move;
				break;
		case 3: if(square[0][2]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[0][2]=move;
				break;
		case 4: if(square[1][0]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[1][0]=move;
				break;
		case 5: if(square[1][1]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[1][1]=move;
				break;
		case 6: if(square[1][2]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[1][2]=move;
				break;
		
		case 7: if(square[2][0]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[2][0]=move;
				break;
		
		case 8: if(square[2][1]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[2][1]=move;
				break;
		
		case 9: if(square[2][2]!=' ')
				{
				getmove(move,player_no);
				return;
				}
				square[2][2]=move;
				break;
	}
	board();
}
bool checkwin()
{
	if(square[0][0] == square[0][1] && square[0][1] == square[0][2] && square[0][0]!=' ')
	return true;
	else if((square[1][0] == square[1][1] && square[1][1] == square[1][2] && square[1][0]!=' '))
	return true;
	else if((square[2][0] == square[2][1] && square[2][1] == square[2][2] && square[2][0]!=' '))	
	return true;
	else if((square[0][0] == square[1][0] && square[1][0] == square[2][0] && square[0][0]!=' '))	
	return true;
	else if((square[0][1] == square[1][1] && square[1][1] == square[2][1] && square[0][1]!=' '))	
	return true;
	else if((square[0][2] == square[1][2] && square[1][2] == square[2][2] && square[0][2]!=' '))	
	return true;
	else if((square[0][0] == square[1][1] && square[1][1] == square[2][2] && square[0][0]!=' '))	
	return true;
	else if((square[2][0] == square[1][1] && square[1][1] == square[0][2] && square[2][0]!=' '))	
	return true;
	else return false;
}
bool checkdraw()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(square[i][j]==' ')
			{
			return false;
			}
		}
	}
	return true;
}
int main()
{
	char move_human1;
	char move_human2;
	int player_no;
	move_human1 = inst();
	if(move_human1 == 'X')
	move_human2='O';
	else move_human2 = 'X';
	while(true)
	{
		int flag=0;
	if(checkwin()==false)
	{
	getmove(move_human1,1);
	player_no=1;
	if(checkdraw())
	{
		cout<<"Oops its draw";
		exit(0);
	}

	}
	if(checkwin()==false)
	{
	getmove(move_human2,2);
	player_no=2;
	if(checkdraw())
	{
		cout<<"Oops its draw";
		exit(0);
	}

	}
	
	if(checkwin()==true)
	{
		cout<<"Game ends"<<endl;
		cout<<"Player  "<<player_no<<"  wins";
		exit(0);
	}
	
	}
	
}

