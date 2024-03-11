//loading co ordinates from text file
#include<graphics.h>
#include<iostream>
#include <fstream>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include <fstream>
#include <sstream>
//
using namespace std;
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
//cleardevice();
setcolor(14);

//setlinestyle(0,1,3);
setfillstyle(1,1);
moveto(100,110); ///were we want put our image
int i=0,x,y;
ifstream in;
in.open("coordinate.txt");

while(!in.eof())
	 {in>>x>>y;
	 setfillstyle(3,1);
	 lineto(x,y);
	 floodfill(152,96,14);
	 }
	 in.close();

delay(200);
settextstyle(3, 0, 3);
outtextxy(200, 250, "Griffin mythical beast");
getch();
return 0;
}



