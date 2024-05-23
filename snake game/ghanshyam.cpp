#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{

  int Xs[200],Ys[200],Xf=200,Yf=200,score=-10,length=1,d,dir,check=1000;
  char playAgain;
  /*for(int i=0;i<200;i++)
  {
      Xs[1]=0;
      Ys[1]=0;
  }*/
 initwindow(640,420," a",200,100);
Xs[0]=200;
Ys[0]=200;
 play:
  for(;;)
  {
      setfillstyle(1,2);
      bar(0,0,640,10);
      bar(0,0,10,480);
      bar(630,0,640,420);
      bar(0,410,640,420);


      //fruit generating
     if(Xs[0]==Xf && Ys[0]==Yf)
     {
         score=score+10;
         Beep(7600,100);
         length=length+1;
         setfillstyle(1,0);

  do{
      //  setfillstyle(1,2);
        Xf=(1+rand()%630);
        Yf=(1+rand()%470);
    }while(getpixel(Xf,Yf)!=0 && Xf>10 && Yf>10);
   Xf=Xf/10;
   Xf=Xf*10;
   Yf=Yf/10;
   Yf=Yf*10;
  }
  setfillstyle(1,2);{
  setcolor(GREEN);
  bar(Xf,Yf,Xf+10,Yf+10);
  floodfill(Xf,Yf,GREEN);}
  if(GetAsyncKeyState(VK_RIGHT)){d=1;}
  else if(GetAsyncKeyState(VK_LEFT)){d=2;}
  else if(GetAsyncKeyState(VK_UP)){d=3;}
  else if(GetAsyncKeyState(VK_DOWN)){d=4;}
  else if(GetAsyncKeyState(VK_BACK)){d=5;}

  switch(d)
  {
  //case 0:
/*if(dir==1){Xs[0]=Xs[0]+10;}
else if(dir==2){Xs[0]=Xs[0]-10;}
else if(dir==3){Ys[0]=Ys[0]-10;}
else if(dir==4){Ys[0]=Ys[0]+10;}*/
  case 1:
    Xs[0]=Xs[0]+10;
    dir=1;
    break;

  case 2:
    Xs[0]=Xs[0]-10;
    dir=2;
    break;

  case  3:
    Ys[0]=Ys[0]-10;

    dir=3;
    break;

  case 4:
    Ys[0]=Ys[0]+10;
    dir=4;
    break;
  }
 for(int i =0;i<length;i++)
{
  setfillstyle(1,1);
  bar(Xs[i],Ys[i],Xs[i]+10,Ys[i]+10);
}
for(int i=199;i>0;i--){
    Xs[i]=Xs[i-1];
    Ys[i]=Ys[i-1];
}
  setfillstyle(1,4);{
  bar(Xs[0],Ys[0],Xs[0]+10,Ys[0]+10);}
  delay(50);
  cleardevice();
for(int i=0;i<length;i++)
{
    if(Xs[0] == Xs[i] && Ys[0] == Ys[i]){
    check=i;
    break;}

if(Xs[0] == Xs[check] && Ys[0] == Ys[check]){
   goto label;
    break;
}}

 if(Xs[0]<=0||Xs[0]>=640 || Ys[0]<=0|| Ys[0]>=480)
 {
      outtextxy(250,100,"GAME OVER");
      getch();
      break;
      }
}
if(Xs[0]==Xf  && Ys[0]==Yf)
{

    score=score+10;
}
   label:
  printf("Your score is : %d",score);
  printf("\nDid you want to play again y for yes n for no  :    ");
  scanf("%c",&playAgain);
  if(playAgain=='y')
  {
      goto play;
  }
  getch();
}
