//ex1 a program that requre a bar of size 40x50 filled with 
#include<graphics.h>
#include<iostream>
#include <dos.h>
#include <time.h>
int main()
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i=30,j=0,t=0;
time_t tm;
    char* curDateTime;
    time(&tm);
    curDateTime = ctime(&tm);
    
    
while(!kbhit())
{
setbkcolor(YELLOW);
cleardevice();
setcolor(1);
//frame
setfillstyle(1,0);
rectangle(220,20,420,460);
floodfill(320,240,1);
//end
//pen
rectangle(440,170,450,440);
rectangle(443,170,447,445);
//
//top edge
rectangle(220,20,420,35);
    //speaker
    rectangle(305,26,335,30);
    //camera
    circle(230,28,2);
    circle(240,28,5);
    circle(250,28,4);
    circle(260,28,3);
//end
//bottom edge
rectangle(220,445,420,460);
//end
//right side button
rectangle(420,150,423,170);
//end


//body start
  //floating button

	int k=0;
    
    
    

    settextstyle(0,0,1);
    outtextxy(250,405,"fingerprint or swip");




//
//circle(320,100,5);

//name
outtextxy(225,150,"Hello,Kirubel");
outtextxy(225,300,curDateTime);
//end

while(!kbhit())
{
//screen saver 
//  //circle(x, y, radius);
    setcolor(2);
    circle(320,100,30);
    setcolor(2);
    pieslice(320, 100, 0,0-t, 20);
    
    setcolor(i/10);
    circle(240,430,10+k);//left bottom
    
    setcolor(i/10);
    circle(400,430,10+k); //right bottom

     delay(200);

    setcolor(0);
    pieslice(320, 100, 0,0-t, 20);
  
    t++;
    k++;
    i++;
    
    if(k>7)
    {
    	//cleardevice();
    	k=0;
	}
    

}
}
getch();
return 0;
}


