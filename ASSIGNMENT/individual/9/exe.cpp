//ex1 a program that requre a bar of size 40x50 filled with 
#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i=0,j=0;
while(!kbhit()){


setcolor(14);
//setfillstyle(7,5);
circle(100, 240,15);
moveto(100,255);
lineto(100,275);
//hand
lineto(80,295);
moveto(100,275);
lineto(120+,295);
//leg
moveto(100+i,275);
lineto(100+i,295);

lineto(80+i,315);
moveto(100+i,295);
lineto(120+i,315);



delay(10);

setcolor(0);
//setfillstyle(7,5);
circle(100+i, 240,15);
moveto(100+i,255);
lineto(100+i,275);
//hand
lineto(80+i,295);
moveto(100+i,275);
lineto(120+i,295);
//leg
moveto(100+i,275);
lineto(100+i,295);

lineto(80+i,315);
moveto(100+i,295);
lineto(120+i,315);

i++;
}
getch();
return 0;
}
