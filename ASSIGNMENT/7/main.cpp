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


rectangle(50,50,550,400);

//trangle 1
setfillstyle(7,4);
int t1points[]={50,50,125,400,50,400,50,50};
fillpoly(4, t1points);

//trangle 2
setfillstyle(1,4);
int t2points[]={50,50,166,50,125,400,50,50};
fillpoly(4, t2points);

//trangle 3
setfillstyle(1,5);
int t3points[]={166,50,250,400,125,400,166,50};
fillpoly(4, t3points);

//trangle 4
setfillstyle(1,6);
int t4points[]={166,50,322,50,250,400,166,50};
fillpoly(4, t4points);

//trangle 5
setfillstyle(1,7);
int t5points[]={322,50,375,400,250,400,322,50};
fillpoly(4, t5points);

//trangle 6
setfillstyle(1,rand() % 10);
int t6points[]={322,50,488,50,375,400,322,50};
fillpoly(4, t6points);

//trangle 7
setfillstyle(1,rand() % 10);
int t7points[]={488,50,550,400,375,400,488,50};
fillpoly(4, t7points);

//trangle 8
setfillstyle(7,rand() % 10);
int t8points[]={550,50,550,400,488,50,550,50};
fillpoly(4, t8points);

delay(30);

}
getch();
return 0;
}





