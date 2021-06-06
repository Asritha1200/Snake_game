#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include <unistd.h>

int height=20,width=20;
int fruitx,fruity;
int x,y;
int gameover=0,score=0;
int flag=0;

void setup()
{
    y=height/2;
    x=width/2;

label1:
    fruitx= rand() % 20;
    if(fruitx==0)
      goto label1;


label2:
    fruity= rand() % 20;
    if(fruity==0)
      goto label2;

}

void draw()
{
    int i;
    int j;
 system("cls");

    for( i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(i==0||i==height-1||j==0||j==width-1)
            {
                printf("#");

            }
            else if(i==y && j==x)
            {
                printf("0");
            }
            else if(i==fruitx&&j==fruity)
            {
                printf("F");

            }
            else
            printf(" ");

        }
        printf("\n");

    }
    printf("press x to quit\n");
    printf("score is %d",score);
}

void input()
{
    if(kbhit())
    {
        
    
    switch(getchar())
    {
        case 'a':
            flag=1;
            break;
        case 'd':
             flag=2;
             break;
    
        case 'w':
             flag=3;
             break;
             
        case 's':
             flag=4;
             break;
        
        case 'x':
             gameover=1;
             break;
         
    }
    }

}

void logic()
{
      sleep(0.1);
    switch(flag)
    {
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
        default:
            break;

        


    }

if(x<0||x>width||y<0||y>height)
{
    gameover=1;
}

if(x==fruitx&&y==fruity)
{

    score=score+10;
    label3:
    fruitx= rand() % 20;
    if(fruitx==0)
      goto label3;


    label4:
    fruity= rand() % 20;
    if(fruity==0)
      goto label4;

}
}



int main()
{
    setup();

    while(!gameover)
    {
        draw();
        input();
        logic();

    }
    return 0;
}