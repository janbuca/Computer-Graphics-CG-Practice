#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
	int gd=DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    
    moveto(322,454);
    lineto(562,344);
    lineto(594,93);
    lineto(318,44);
    lineto(46,92);
    lineto(73,345);
    lineto(322,454);
    lineto(327,167);
    lineto(594,93);
    lineto(327,167);
    lineto(46,92);
//side1
//cub1
setcolor(15);
setfillstyle(1,4);
moveto(233,341);
lineto(315,372);
lineto(317,447);
lineto(235,413);
lineto(233,341);
floodfill(275,392,15);

//cube2
moveto(148,305);
lineto(219,336);
lineto(219,403);
lineto(149,374);
lineto(148,305);
setfillstyle(1,YELLOW);
floodfill(176,359,15);
//CUBE3
moveto(70,276);
lineto(135,301);
lineto(139,367);
lineto(76,342);
lineto(70,276);
setfillstyle(1,rand()%15);
floodfill(104,316,15);
//cube4
moveto(233,248);
lineto(316,275);
lineto(316,356);
lineto(232,325);
lineto(233,248);
setfillstyle(1,rand()%15);
floodfill(265,301,15);
//cube5
moveto(141,218);
lineto(215,245);
lineto(219,321);
lineto(146,293);
lineto(141,218);
setfillstyle(1,rand()%15);
floodfill(179,268,15);
//cube6
moveto(63,192);
lineto(128,213);
lineto(135,286);
lineto(69,263);
lineto(63,192);
setfillstyle(1,rand()%15);
floodfill(93,236,15);
//cube7

//top viwe
moveto(328,160);
lineto(411,136);
lineto(325,116);
lineto(239,135);
lineto(328,160);
setfillstyle(1,2);
floodfill(323,138,15);
//
moveto(317,46);
lineto(251,59);
lineto(318,72);
lineto(383,59);
lineto(317,46);
setfillstyle(1,YELLOW);
floodfill(317,55,15);
//
moveto(577,93);
lineto(516,110);
lineto(431,92);
lineto(492,78);
lineto(577,93);
setfillstyle(1,2);
floodfill(504,89,15);
//
moveto(63,92);
lineto(148,76);
lineto(212,92);
lineto(129,109);
lineto(63,109);
setfillstyle(1,4);
floodfill(128,87,15);
//
  //right
moveto(330,374);
lineto(410,340);
lineto(409,411);
lineto(330,449);
lineto(330,374);
setfillstyle(1,15);
floodfill(363,397,15);
//
moveto(558,341);
lineto(499,369);
lineto(505,303);
lineto(565,275);
lineto(558,341);
setfillstyle(1,2);
floodfill(531,320,15);
//
moveto(587,102);
lineto(524,118);
lineto(516,199);
lineto(578,180);
lineto(587,102);
	
	    
getch();
return 0;
}
