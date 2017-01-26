#include"header.h"
#include"game.h"
extern char one[20];
extern char zero[20];
char game[R][C];
void main()
{
    system("clear");

    int i,j;
    for(i=0;i<R;i++)        //assigning * to the array
    {
        for(j=0;j<C;j++)
            game[i][j]='*';
    }
    gotomn(11,6);
    printf("  Game: \'zero-one\'     Developer: Nikhil Kumar Mishra");
    printf("\n\n\n\n\n\nEnter a button to continue");
    getch();
    system("clear");
    gotomn(12,7);
    printf("This game will play by number keys  1-9\n\n\n");
    gotomn(1,7);
    printf("Do you want to see the rules of this game(y/n)");
		//while(getchar!='\n');
    if(getch()=='y')
    {
        system("clear");
        rules();
    }

    system("clear");
    gotomn(15,6);
    printf("Enter the name of Player who choose \'one\'\n\n");
    gets(one);
    printf("\n\nGreat Job!   press a key to continue\n");
    getch();
    system("clear");
    gotomn(10,6);
    printf("Enter the name of Player who choose \'zero\'\n\n");
    fgets(zero,20,stdin);
     printf("\n\nGreat Job!   press a key to continue\n");
		// while(getchar!='\n');
    getch();
    system("clear");
    gotomn(15,7);
    printf("To start game press any key and to quit press 0");
    if(getch()==48)
		{
		system("clear");
    exit(0);
		}
    system("clear");
    Game();
}
