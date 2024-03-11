#include<graphics.h>
#include<iostream>
#include<math.h>
int main(int argc, char const *argv[])
{
	int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i = 0, j=0;
int c=0;

int angle=0;
double x,y;

setcolor(4);	
  line(20,190,20,290);

line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

for(x=0;x<getmaxx();x+=3)

{

setcolor(YELLOW);

y=50*sin(angle*3.141/180);

y=getmaxy()/2-y;

putpixel(x,y,15);

delay(100);

angle+=5;

}

getch();
return 0;
}

