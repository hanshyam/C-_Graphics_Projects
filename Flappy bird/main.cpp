#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
int main()
{
    int Xs[200],Ys[200],d = 0,a=100,b = 100,c = 100;
    int X1f = 450,Y1f = 0,X2f = 600,Y2f =0,X3f = 750,Y3f = 0;
    int Score = 0;
    Xs[0] = 200;Ys[0] =200;
    initwindow(450,500,"Flappy Bird",450,100);
    for(;;)
    {
      //Boundary
          {
        setfillstyle(1,3);
        bar(0,0,450,10);
        bar(0,490,450,500);
        bar(0,0,10,500);
        bar(440,0,450,500);
          }
     setbkcolor(7);

     //pillar
     bar(X1f,Y1f             ,X1f+20,Y1f+200);
     bar(X1f,Y1f+a+200,X1f+20,Y1f+500);

     bar(X2f,Y2f             ,X2f+20,Y2f+300);
     bar(X2f,Y2f+b+300,X2f+20,Y2f+500);

     bar(X3f,Y3f             ,X3f+20,Y3f+250);
     bar(X3f,Y3f+c+250,X3f+20,Y3f+500);

     X1f = X1f -5;
    X2f = X2f -5;
    X3f = X3f -5;
    if(X1f==0 && X2f!=0 && X3f!=0)
    {
        X1f = 450;
    }
    else if(X2f==0 && X1f!=0 && X3f!=0)
    {
        X2f = 450;
    }
    else if(X3f==0 && X1f!=0 && X2f!=0)
    {
        X3f = 450;
    }

    //Bird
    {
    setfillstyle(1,2);
     bar(Xs[0],Ys[0],Xs[0]+15,Ys[0]+15);
     }

      if(GetAsyncKeyState(VK_UP)){d=1;}
  switch(d)
  {
   case 1:
     Ys[0] = Ys[0] -10;
     d =0;
    break;

    case 0:
     Ys[0] = Ys[0] + 10;
     break;
  }
 // label:
  if(Xs[0] == X1f && Ys[0]<=Y1f+200 || Xs[0] == X2f && Ys[0]<=Y2f+300 || Xs[0] == X3f && Ys[0]<=Y3f+250 || Xs[0] == X1f && Ys[0]>=Y1f+a+200 || Xs[0] == X2f && Ys[0]>=Y2f+b+300 || Xs[0] == X3f && Ys[0]>=Y3f+c+250 ||Ys[0]>=500)
  {
      cleardevice();
      setcolor(BLACK);
      outtextxy(210,250,"GAME OVER");
      getch();
      goto GameOver;
  }
  else if(Xs[0]==X1f && Ys[0]>=Y1f+200 && Ys[0]<=Y1f+a+200 || Xs[0]==X2f && Ys[0]>=Y2f+300 && Ys[0]<=Y2f+b+300  || Xs[0]==X3f && Ys[0]>=Y3f+250 && Ys[0]<=Y3f+c+250)
  {
      Score = Score +10;
  }

  system("cls");
   printf("Score = %d",Score);
  //delay(20);
   cleardevice();
 //goto play;
   }
   GameOver:

    getch();
    return 0;
}
