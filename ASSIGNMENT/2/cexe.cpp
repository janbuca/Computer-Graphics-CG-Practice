#include<graphics.h>
#include<iostream>

 using namespace std;

#define keyup 72
#define keydown 80
#define keyleft 75
#define keyright 77

#define keyspace 32
#define keyenter 13
#define keyesc 27
#define keyback 8


int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i=0,j=0;

moveto(25,100);
lineto(10,100);
lineto(5,50);
lineto(25,20);
lineto(23,15);
lineto(130,15);
lineto(170,40);
lineto(220,50);
lineto(220,100);
lineto(195,100);
//tires
moveto(25,100);
lineto(195,100);
fillellipse(45,100,15,15);
fillellipse(172,100,15,15);
//
//windows
moveto(78,52);
lineto(157,52);
lineto(120,20);
lineto(78,20);
lineto(78,52);

moveto(65,52);
lineto(65,20);
lineto(48,20);
lineto(30,52);
lineto(65,52);

//road

do
   {
   	key=getch();
	switch(key)
	 {
   	  case keyright:
	    	{
	    	  while(!kbhit())
			  {
			  	cleardevice();
			  	setcolor(14);
			  	//
moveto(25,100);
lineto(10,100);
lineto(5,50);
lineto(25,20);
lineto(23,15);
lineto(130,15);
lineto(170,40);
lineto(220,50);
lineto(220,100);
lineto(195,100);
//tires
moveto(25,100);
lineto(195,100);
fillellipse(45,100,15,15);
fillellipse(172,100,15,15);
//
//windows
moveto(78,52);
lineto(157,52);
lineto(120,20);
lineto(78,20);
lineto(78,52);

moveto(65,52);
lineto(65,20);
lineto(48,20);
lineto(30,52);
lineto(65,52);
			  	//








getch();	
return 0;
}

