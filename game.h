
extern char game[R][C];
char one[20];
char zero[20];
void Game()
{
    int i,j;
    char n;
    for(i=0;i<N;i++)
        printf("\n");
        for(i=0;i<R;i++)        //assigning * to the array
    {
        for(j=0;j<C;j++)
            game[i][j]='*';
    }

    pattern();
    while(1)
  {

    printf("\n\n %s your turn",one);
    n=press();
    //n=getch();
    //n-=49;
    soo:
    if(*(*(game)+n)=='*')
    *(*(game)+n)='1';
    else
    {
        printf("\n\nyou do not overwrite\npress a key to continue");
        getch();
        system("clear");
        pattern();
        printf("\n\nplease re enter your character");
        n=press();
        goto soo;
    }
    system("clear");
     for(i=0;i<N;i++)
        printf("\n");
    pattern();
    test();
    printf("\n\n now %s your turn",zero);
    n=press();
    //n=getch();
    //n-=49;
     soz:
     if(*(*(game)+n)=='*')
    *(*(game)+n)='0';
    else
    {
        printf("\n\nyou do not overwrite\npress a key to continue");
        getch();
        system("clear");
        pattern();
        printf("\n\nplease re enter your character");
        n=press();
        goto soz;
    }
    //*(*(game)+n)='0';
    system("clear");
     for(i=0;i<N;i++)
        printf("\n");
    pattern();
    test();
  }
}
   void test()                //test the chance of win
   {
       int i;
       char new;
    for(i=0;i<C;i++)
    {
        if((*(*(game)+3*i))==(*(*(game)+3*i+1))&&(*(*(game)+3*i))==(*(*(game)+3*i+2))&&(*(*(game)+3*i))!='*')
        {
            if(*(*(game)+3*i)=='1')
            {
                printf("%s won this match",one);
                //break;
                another(one);
								system("clear");
                exit(0);
            }
            else
            {
                 printf("%s won this match",zero);
                //break;
                another(zero);
                exit(0);
            }
        }
        if((*(*(game)+i))==(*(*(game)+i+C))&&(*(*(game)+i))==(*(*(game)+i+2*C))&&(*(*(game)+i))!='*')
        {
            if((*(*(game)+i))=='1')
                {
                   printf("%s won this match",one);
                //break;
                another(one);
                exit(0);
                }
                else
            {
                 printf("%s won this match",zero);
                //break;
                another(zero);
                exit(0);
            }
        }
        if(*(*game)==*(*(game)+C+1)&&(*(*game))==*(*(game)+2*(C+1))&&*(*game)!='*')//||(*(*game+2)==*((*(game)+2)+C-1)&&(*(*game+2))==*((*(game)+2)+2*(C+1))))
             {
            if((*(*(game)))=='1')
                {
                   printf("%s won this match",one);
                //break;
                another(one);
                exit(0);
                }
                else
            {
                 printf("%s won this match",zero);
                //break;
                another(zero);
                exit(0);
            }
        }
              if(*(*game+2)==*((*(game)+2)+C-1)&&(*(*game+2))==*((*(game)+2)+2*(C-1))&&*(*game+2)!='*')
              {
            if(*(*(game)+2)=='1')
            {
                printf("%s won this match",one);
                //break;
                another(one);
                exit(0);

            }
            else
            {
                 printf("%s won this match",zero);
                //break;
                another(zero);
                exit(0);
            }
        }
    }
    for(i=0;i<R*C;i++)
    {
        if(*(*game+i)!='*')
            continue;
        else break;
    }
          if(i==9)
          {
              gotomn(1,9);
             printf("This match is draw\n") ;
             printf("Do you want a new battle (y/n)\n");
             son:
        new=getch();
        if(new=='n')
            exit(0);
        else if(new=='y')
        {
            system("clear");
            Game();
        }
        else
        {
            system("clear");
            printf("\n\n\n\n\t\t\t\tDo you continue with a new battle(y/n)?");
            goto son;
        }
          }
}
void pattern()
{
    int i,j,k;
    gotomn(8,7);
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {

            printf("%14c",game[i][j]);
        }
        for(k=0;k<N;k++)
          printf("\n");
          gotomn(0,7);
    }

}
char press()
{
    char n;
    n=getch();
    n-=49;
    return n;
}
void another(char (*name)[20])           //code for next rounds
{
    int i;
    char new;
    printf("\n Great match!\npress any key");
    getch();
    system("clear");
    for(i=0;i<N;i++)
        printf("\n");
        gotomn(10,7);
        printf("congratulations ! %s you won the battle.\n \n\n\n\nDo you continue with a new battle(y/n)",name);
        sos:
        new=getch();
        if(new=='n')
            exit(0);
        else if(new=='y')
        {
            system("clear");
            Game();
        }
        else
        {
            system("clear");
            printf("\n\n\n\n\t\t\t\tDo you continue with a new battle(y/n)?");
            goto sos;
        }
}

void gotomn(int m,int n)         //it takes the cursor at mth row and nth tab
{
    int i,j;
    for(i=0;i<m;i++)
    {
        printf("\n");
    }
    for(j=0;j<n;j++)
    {
        printf("\t");
    }
}
void rules()
{
    gotomn(3,7);
    printf("Rules:\n\n\n");
    printf("\t\t1. In game you see such a pattern\n\n");
    pattern();
    printf("\nEnter a key");getch();system("clear");
    gotomn(3,7);
    printf("Place value of * is\n\n");
     int i,j,k,l=1;
    gotomn(3,7);
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {

            printf("%14d",l++);
        }
        for(k=0;k<N;k++)
          printf("\n");
          gotomn(0,7);
    }
     printf("\n\n\n\n\nEnter a key");
    getch();
    system("clear");
    gotomn(9,3);
    printf("3. The person who makes the 3 continuously ones or zeros will be the winner of that match\nTo Go back press a key");
     printf("\n\n\n\n\nEnter a key");
    getch();
}
