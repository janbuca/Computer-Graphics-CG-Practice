//write a program that moves a circle of radius 10
//horizontally to the right
#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i = 0;
cleardevice();
setbkcolor(0);
while(!kbhit())
{
setcolor(4);
//road
setcolor(15);
moveto(0,280);
lineto(640,280);

//moveto(0,180);
//lineto(640,180);
//
moveto(100,240);
lineto(200,240);
//bactire
setcolor(4);
circle(70,240,30);
circle(70,240,20);
//front tire
//circle(230,240,30);
//front
//moveto(260,240);
//lineto(300,240);
//back wing
moveto(70,210);
lineto(50,180);
lineto(15,180);
//
moveto(70,210);
lineto(150,180);
lineto(180,180);
lineto(180,210);
lineto(230,210);
lineto(230,195);


delay(100);

}
getch();
return 0;
}


