//Exercises on arc
//exercise e
//
#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

while(!kbhit())
{
	
setcolor(14);
setfillstyle(1,2);
setlinestyle(0,1,3);
//fillellipse(100,100,80,50);
//ellipse(250,100,20,120,80,50);
//sector(400,100,20,120,80,50);

//arc(x, y, starting angle, ending angle, radius);
arc(320, 240, 0, 180, 200);
//pieslice1
setfillstyle(1,4);
setlinestyle(0,1,3);
pieslice(320, 240, 0, 45, 200);
//
//pieslice2
setfillstyle(1,8);
setlinestyle(0,1,3);
pieslice(320, 240, 45, 90, 200);
//
//pieslice3
setfillstyle(1,2);
setlinestyle(0,1,3);
pieslice(320, 240, 90, 135, 200);
//
//pieslice4
setfillstyle(1,5);
setlinestyle(0,1,3);
pieslice(320, 240, 135, 180, 200);
//


delay(30);

}
getch();
return 0;
}





