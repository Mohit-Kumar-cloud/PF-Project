#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void board(char*,int*,int*);
void boardone(char*);
int result(char*);
void onevsone();
void onevscom();
void threeplayer();
void fourplayer();
void tournament();
void main()
{
	FILE*ptr1;
	int type,i=0;
	char score[100];
	do
	{
	printf("1)Start\n2)Highscore\n0)Exit\n");
	scanf("%d",&type);
	if(type==1)
	{
		printf("Enter which mode you want to play!\n");
		printf("1)1 vs 1\n2)1 vs computer\n3)1 vs 1 vs 1\n4)four player\n5)Tournament\n");
		scanf("%d",&type);
		if(type==1)
		{	
			onevsone();
		}
		else if(type==2)
		{
			onevscom();
		}
		else if(type==3)
		{
			threeplayer();
		}
		else if(type==4)
		{
			fourplayer();
		}
		else if(type==5)
		{
			tournament();
		}
		else
		{
			printf("Please try again!\n");
		}
	}
	else if(type==2)
	{
		printf("1)one vs one\n2)one vs computer\n");
		scanf("%d",&type);
		if(type==1)
		{
		ptr1=fopen("highscore1.txt","r");
		while(fscanf(ptr1,"%s",&score[i])!=EOF)
		i++;
		printf("Score=Player\n");
		printf("%s\n",score);	
		}
		else if(type==2)
		{
		ptr1=fopen("highscore2.txt","r");
		while(fscanf(ptr1,"%s",&score[i])!=EOF)
		i++;
		printf("Score=Player\n");
		printf("%s\n",score);
	}
		else
		{
			printf("please try again!\n");
		}
	}
}
while(type!=0);
}
void onevsone()
{
	int choice=100,*c1,*c2,j,player=0,count=1,s1=0,s2=0,h1=0;
	char mark,str[100];
	FILE*ptr1;
	c1=&s1;
	c2=&s2;
	ptr1=fopen("highscore1.txt","r");
	fscanf(ptr1,"%d",&h1);
	while(choice!=0)
	{
		char square[10]={'0','1','2','3','4','5','6','7','8','9'};
		char *s=square;
		do
		{
			board(s,c1,c2);
			if(count%2==1)
			{
				player=1;
			}
			else
			{
				player=2;
			}
			if(player==1)
			{
				mark='X';
			}
			else
			{
				mark='O';
			}
			printf("Player %d Enter a number(enter zero to end the game):",player);
			scanf("%d",&choice);
			if(choice==0)
			{
				break;
			}
			else if(choice==1 && square[1]=='1')
			{
				square[1]=mark;
			}
			else if(choice==2 && square[2]=='2')
			{
				square[2]=mark;
			}
			else if(choice==3 && square[3]=='3')
			{
				square[3]=mark;
			}
			else if(choice==4 && square[4]=='4')
			{
				square[4]=mark;
			}
			else if(choice==5 && square[5]=='5')
			{
				square[5]=mark;
			}
			else if(choice==6 && square[6]=='6')
			{
				square[6]=mark;
			}
			else if(choice==7 && square[7]=='7')
			{
				square[7]=mark;
			}
			else if(choice==8 && square[8]=='8')
			{
				square[8]=mark;
			}
			else if(choice==9 && square[9]=='9')
			{
				square[9]=mark;
			}
			else if(choice!=0)
			{
				printf("invalid move!\n");
				count--;
			}
			j=result(s);
			count++;
		}
		while(j==0);
		board(s,c1,c2);
		if(j==-1)
			{
				printf("Game Draw!\n");
			}
		else if(j==1&&choice!=0)
		{
			printf("Player %d Wins\n",player);
			if(player==1&&choice!=0)
			{
				s1++;
			}
			else if(player==2&&choice!=0)
			{
				s2++;
			}
		}
	}
	if(s1>s2)
	{
		printf("Player1 Enter your name:");
		scanf("%s",&str);
		if(s1>h1)
		{
			ptr1=fopen("highscore1.txt","w");
			fprintf(ptr1,"%d=%s",s1,str);
			printf("%s won the match\n",str);
		}
		else
		{
			printf("%s won the match\n",str);
		}
	}
	else if(s2>s1)
	{
		printf("Player 2 Enter your name:");
		scanf("%s",&str);
		if(s2>h1)
		{
			ptr1=fopen("highscore1.txt","w");
			fprintf(ptr1,"%d=%s",s2,str);
			printf("%s won the match\n",str);
		}
		else
		{
			printf("%s won the match\n",str);
		}
	}
	else
	{
		printf("Game draw!!\n");
	}
}
void onevscom()
{
	int choice=100,*c1,*c2,j,player=0,count=1,s1=0,s2=0,h1=0;
	char mark,str[100];
	time_t t;
	FILE*ptr1;
	c1=&s1;
	c2=&s2;
	ptr1=fopen("highscore2.txt","r");
	fscanf(ptr1,"%d",&h1);
	srand((unsigned) time(&t));
	while(choice!=0)
	{
		char square[10]={'0','1','2','3','4','5','6','7','8','9'};
		char *s=square;
		do
		{
			board(s,c1,c2);
			if(count%2==1)
			{
				player=1;
			}
			else
			{
				player=2;
			}
			if(player==1)
			{
				mark='X';
			}
			else
			{
				mark='O';
			}
			if(player==1)
			{
			printf("Player 1 Enter a number(enter zero to end the game):");
			scanf("%d",&choice);
			}
			else if(player==2)
			{
				printf("Computer turn...\n");
				sleep(1);
				choice=(rand()%9)+1;
			}
			if(choice==0)
			{
				break;
			}
			else if(choice==1 && square[1]=='1')
			{
				square[1]=mark;
			}
			else if(choice==2 && square[2]=='2')
			{
				square[2]=mark;
			}
			else if(choice==3 && square[3]=='3')
			{
				square[3]=mark;
			}
			else if(choice==4 && square[4]=='4')
			{
				square[4]=mark;
			}
			else if(choice==5 && square[5]=='5')
			{
				square[5]=mark;
			}
			else if(choice==6 && square[6]=='6')
			{
				square[6]=mark;
			}
			else if(choice==7 && square[7]=='7')
			{
				square[7]=mark;
			}
			else if(choice==8 && square[8]=='8')
			{
				square[8]=mark;
			}
			else if(choice==9 && square[9]=='9')
			{
				square[9]=mark;
			}
			else if(choice!=0)
			{
				printf("invalid move!\n");
				count--;
			}
			j=result(s);
			count++;
		}
		while(j==0);
		board(s,c1,c2);
		if(j==-1)
			{
				printf("Game Draw!\n");
			}
		else if(j==1&&choice!=0)
		{
			if(player==1)
			printf("Player 1 Wins\n");
			else
			printf("Computer wins\n");
			if(player==1&&choice!=0)
			{
				s1++;
			}
			else if(player==2&&choice!=0)
			{
				s2++;
			}
		}
	}
		printf("Player1 Enter your name:");
		scanf("%s",&str);
		if(s1>h1)
		{
			ptr1=fopen("highscore2.txt","w");
			fprintf(ptr1,"%d=%s",s1,str);
		}
}
void threeplayer()
{
	int choice,i,j,player=0,s1=0,s2=0,count=1;
	char mark;
	for(i=0;i<2;i++)
	{
		char square[10]={'0','1','2','3','4','5','6','7','8','9'};
		char *s=square;
		do
		{
			boardone(s);
			if(count%2==1)
			{
				player=1;
				if(s2==1)
				{
					player=3;
				}
			}
			else
			{
				player=2;
				if(s1==1)
				{
					player=3;
				}
			}
			if(count%2==1)
			{
				mark='X';
			}
			else
			{
				mark='O';
			}
			printf("Player %d Enter a number:",player);
			scanf("%d",&choice);
			if(choice==1 && square[1]=='1')
			{
				square[1]=mark;
			}
			else if(choice==2 && square[2]=='2')
			{
				square[2]=mark;
			}
			else if(choice==3 && square[3]=='3')
			{
				square[3]=mark;
			}
			else if(choice==4 && square[4]=='4')
			{
				square[4]=mark;
			}
			else if(choice==5 && square[5]=='5')
			{
				square[5]=mark;
			}
			else if(choice==6 && square[6]=='6')
			{
				square[6]=mark;
			}
			else if(choice==7 && square[7]=='7')
			{
				square[7]=mark;
			}
			else if(choice==8 && square[8]=='8')
			{
				square[8]=mark;
			}
			else if(choice==9 && square[9]=='9')
			{
				square[9]=mark;
			}
			else
			{
				printf("invalid move!\n");
				count--;
			}
			j=result(s);
			count++;
		}
		while(j==0);
		boardone(s);
		if(j==-1)
			{
				printf("Game Draw!\n");
				i--;
			}
		else if(j==1)
		{
			printf("Player %d Wins\n",player);
			if(player==1)
			{
				s1++;
			}
			else if(player==2)
			{
				s2++;
			}
		}
	}
}
void fourplayer()
{
	int choice,i,j,player=0,s1=0,s2=0,s3=0,s4=0,count=1;
	char mark;
	for(i=0;i<3;i++)
	{
		char square[10]={'0','1','2','3','4','5','6','7','8','9'};
		char *s=square;
		do
		{
			boardone(s);
			if(count%2==1)
			{
				player=1;
				if(i==1)
				player=4;
				if(i==2)
				{
					if(s1==1)
					player=1;
					else if(s2==1)
					player=2;
				}
				
			}
			else
			{
				player=2;
				if(i==1)
				player=3;
				if(i==2)
				{
					if(s3==1)
					player=3;
					else if(s4==1)
					player=4;
				}
			}
			if(count%2==1)
			{
				mark='X';
			}
			else
			{
				mark='O';
			}
			printf("Player %d Enter a number:",player);
			scanf("%d",&choice);
			if(choice==1 && square[1]=='1')
			{
				square[1]=mark;
			}
			else if(choice==2 && square[2]=='2')
			{
				square[2]=mark;
			}
			else if(choice==3 && square[3]=='3')
			{
				square[3]=mark;
			}
			else if(choice==4 && square[4]=='4')
			{
				square[4]=mark;
			}
			else if(choice==5 && square[5]=='5')
			{
				square[5]=mark;
			}
			else if(choice==6 && square[6]=='6')
			{
				square[6]=mark;
			}
			else if(choice==7 && square[7]=='7')
			{
				square[7]=mark;
			}
			else if(choice==8 && square[8]=='8')
			{
				square[8]=mark;
			}
			else if(choice==9 && square[9]=='9')
			{
				square[9]=mark;
			}
			else
			{
				printf("invalid move!\n");
				count--;
			}
			j=result(s);
			count++;
		}
		while(j==0);
		boardone(s);
		if(j==-1)
			{
				printf("Game Draw!\n");
				i--;
			}
		else if(j==1)
		{
			printf("Player %d Wins\n",player);
			if(player==1)
			{
				s1++;
			}
			else if(player==2)
			{
				s2++;
			}
			else if(player==3)
			{
				s3++;
			}
			else if(player==4)
			{
				s4++;
			}
		}
}
}
void tournament()
{
	int choice,i,j,player=0,s1=0,s2=0,s3=0,s4=0,count=1;
	char mark;
	for(i=0;i<5;i++)
	{
		char square[10]={'0','1','2','3','4','5','6','7','8','9'};
		char *s=square;
		do
		{
			boardone(s);
			if(count%2==1)
			{
				player=1;
				if(i==1)
				player=3;
				if(i==2)
				{
					if(s1==1)
					player=1;
					else if(s2==1)
					player=2;
				}
				if(i==3)
				{
					if(s1==0)
					player=1;
					else if(s2==0)
					player=2;
				}
				if(i==4)
				{
					if(s1==3)
					player=1;
					else if(s2==3)
					player=2;
					else if(s3==3)
					player=3;
					else if(s4==3)
					player=4;
				}
			}
			
			else
			{
				player=2;
				if(i==1)
				player=4;
				if(i==2)
				{
					if(s3==1)
					player=3;
					else if(s4==1)
					player=4;
				}
				if(i==3)
				{
					if(s3==0)
					player=3;
					else if(s4==0)
					player=4;
				}
				if(i==4)
				{
					if(s1==2)
					player=1;
					else if(s2==2)
					player=2;
					else if(s3==2)
					player=3;
					else if(s4==2)
					player=4;
				}
			}
			if(count%2==1)
			{
				mark='X';
			}
			else
			{
				mark='O';
			}
			printf("Player %d Enter a number:",player);
			scanf("%d",&choice);
			if(choice==1 && square[1]=='1')
			{
				square[1]=mark;
			}
			else if(choice==2 && square[2]=='2')
			{
				square[2]=mark;
			}
			else if(choice==3 && square[3]=='3')
			{
				square[3]=mark;
			}
			else if(choice==4 && square[4]=='4')
			{
				square[4]=mark;
			}
			else if(choice==5 && square[5]=='5')
			{
				square[5]=mark;
			}
			else if(choice==6 && square[6]=='6')
			{
				square[6]=mark;
			}
			else if(choice==7 && square[7]=='7')
			{
				square[7]=mark;
			}
			else if(choice==8 && square[8]=='8')
			{
				square[8]=mark;
			}
			else if(choice==9 && square[9]=='9')
			{
				square[9]=mark;
			}
			else
			{
				printf("invalid move!\n");
				count--;
			}
			j=result(s);
			count++;
		}
		while(j==0);
		boardone(s);
		if(j==-1)
			{
				printf("Game Draw!\n");
				i--;
			}
		else if(j==1)
		{
			if(i!=4)
			printf("Player %d Wins\n",player);
			else if(i==4)
			printf("Player %d won the tournament!!!",player);
			if(player==1)
			{
				s1++;
			}
			else if(player==2)
			{
				s2++;
			}
			else if(player==3)
			{
				s3++;
			}
			else if(player==4)
			{
				s4++;
			}
			if(i==3)
			{
				if(player==1)
			{
				s1=s1+2;
			}
			else if(player==2)
			{
				s2=s2+2;
			}
			else if(player==3)
			{
				s3=s3+2;
			}
			else if(player==4)
			{
				s4=s4+2;
			}
			}
		}
	}
}
int result(char *s)
{
	if(s[1]==s[2] && s[2]==s[3])
	{
		return 1;
	}
	else if(s[4]==s[5] && s[5]==s[6])
	{
		return 1;
	}
	else if(s[7]==s[8] && s[8]==s[9])
	{
		return 1;
	}
	else if(s[1]==s[4] && s[4]==s[7])
	{
		return 1;
	}
	else if(s[2]==s[5] && s[2]==s[8])
	{
		return 1;
	}
	else if(s[3]==s[6] && s[6]==s[9])
	{
		return 1;
	}
	else if(s[1]==s[5] && s[5]==s[9])
	{
		return 1;
	}
	else if(s[3]==s[5] && s[5]==s[7])
	{
		return 1;
	}
	else if(s[1]!='1' && s[2]!='2' && s[3]!='3' && s[4]!='4' && s[5]!='5' && s[6]!='6' && s[7]!='7' && s[8]!='8' && s[9]!='9')
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
	void board(char *s,int *c1,int *c2)
	{
		printf("\n\n\tTic Tac Toe\n\n");
		printf("Player1=%d\t\t Player2=%d\n",*c1,*c2);
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[1], s[2], s[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[4], s[5], s[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[7], s[8], s[9]);
    printf("     |     |     \n\n");
	}
	void boardone(char *s)
	{
		printf("\n\n\tTic Tac Toe\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[1], s[2], s[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[4], s[5], s[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", s[7], s[8], s[9]);
    printf("     |     |     \n\n");
	}
