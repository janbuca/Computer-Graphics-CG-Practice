#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int endfunc(int e);

int main(){
    int gd,gm,x=200,y=200,d=1,dir=1,rx=200,ry=200,f=0;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    delay(2000);
    srand(time(NULL));
    setfillstyle(1,2);

    for(;;){
        setfillstyle(1,0);
        bar(0,0,640,480);
        setfillstyle(1,2);
        bar(0,0,640,10);
        bar(0,0,10,480);
        bar(0,480,640,470);
        bar(630,10,640,480);


        //food
        if(x==rx && y==ry){
                f=f+1;
        setfillstyle(1,0);
        bar(rx,ry,rx+10,ry+10);
        do{
        rx =(1 + rand()%620);
        ry = (1 + rand() % 460);

        }while(getpixel(rx,ry)!=0 && rx >10 && ry >10);
        rx=rx/10;
        rx=rx*10;
        ry=ry/10;
        ry=ry*10;
        setfillstyle(1,2);

    }
      bar(rx,ry,rx+10,ry+10);

        if(GetAsyncKeyState(VK_RIGHT)){d=1;}
        else if (GetAsyncKeyState(VK_LEFT)){d=2;}
        else if (GetAsyncKeyState(VK_UP)){d=3;}
        else if (GetAsyncKeyState(VK_DOWN)){d=4;}
        else {d=0;}
        switch(d){
    case 0:
        if(dir==1){x=x+10;}
        else if (dir==2){x=x-10;}
        else if (dir==3){y=y-10;}
        else if (dir==4){y=y+10;}
        else {d=0;}
         break;
    case 1:
        x=x+10;
        dir=1;
        break;
    case 2:
        x=x-10;
        dir=2;
        break;
    case 3:
        dir=3;
        y=y-10;
        break;
    case 4:
        dir=4;
        y=y+10;
        break;
        }

        bar(x,y,x+10,y+10);
                delay(100);
                if(x>=640 || x <=0 || y<=0 || y>=480){
                    endfunc(f);
                    break;
                }
    }

}

int endfunc(int e){
    setfillstyle(1,5);
    e=e-1;
    bar(0,0,640,480);
    system("cls");
    printf("YOU DIED OUTSIDE THE BOUNDARAY");
    printf(" SCORE : %d \n", e);
    getch();
}