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

moveto(25,100);
lineto(10,100);
lineto(5,50);
lineto(25,20);

getch();
return 0;
}
