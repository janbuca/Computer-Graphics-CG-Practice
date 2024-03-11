//Exercises on arc
//exercise e
//
#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

//road
moveto(2,335);
lineto(186,339);
moveto(580,347);
lineto(639,348);
setcolor(YELLOW);
moveto(1,436);
lineto(639,441);

//
setcolor(15);
moveto(26,86);
lineto(54,86);
lineto(132,214);
lineto(203,244);
//left wing
lineto(354,245);
lineto(352,235);
lineto(363,245);
lineto(504,250);
lineto(538,254);
lineto(576,269);
//pilot  window
//1
lineto(589,279);
lineto(586,282);
lineto(590,288);
lineto(595,287);
lineto(589,279);
//2
moveto(583,281);
lineto(578,281);
lineto(581,293);
lineto(588,289);
lineto(583,281);
//3
moveto(575,281);
lineto(568,281);
lineto(568,287);
lineto(578,292);
lineto(575,281);
//

moveto(595,287);
lineto(615,300);
lineto(619,305);
lineto(623,311);
lineto(622,318);
lineto(578,344);
lineto(578,354);
lineto(548,360);

//leg
lineto(549,390);
   //front tire
   fillellipse(549,390,10,10);
   //back
   fillellipse(327,375,10,10);
   fillellipse(319,367,10,10);
//
//door 1
moveto(534,271);
lineto(535,312);
lineto(547,312);
lineto(547,271);
lineto(534,271);
//door2
moveto(354,277);
lineto(353,304);
lineto(363,304);
lineto(363,277);
lineto(354,277);
//door3
moveto(143,308);
lineto(156,308);
lineto(156,266);
lineto(143,266);
lineto(143,308);
//
//users windows
fillellipse(177,285,3,10);
fillellipse(186,285,3,10);
fillellipse(195,285,3,10);

fillellipse(347,285,3,10);
fillellipse(336,285,3,10);
fillellipse(327,285,3,10);
//
//flag
   //red
setfillstyle(1,4);
int tRpoints[]={57,245,51,216,150,243,57,245};
fillpoly(4, tRpoints);
   //yellow
setfillstyle(1,YELLOW);
int tYpoints[]={52,211,46,175,151,237,52,211};
fillpoly(4, tYpoints);
   //green
setfillstyle(1,2);
int tGpoints[]={46,169,35,112,152,233,46,169};
fillpoly(4, tGpoints);
//
//right wing
moveto(436,330);
//lineto(431,325);
lineto(410,323);
lineto(393,316);
lineto(264,318);
lineto(370,333);
lineto(370,339);
lineto(347,354);
lineto(375,371);

moveto(436,330);
lineto(435,370);
lineto(375,371);
//
moveto(548,359);
lineto(548,351);
lineto(436,350);







moveto(26,86);
lineto(54,249);
lineto(18,252);
lineto(38,253);
lineto(101,264);
moveto(11,232);
lineto(29,232);
lineto(53,242);
moveto(11,232);
lineto(30,251);
moveto(36,260);
lineto(42,281);
lineto(130,320);
lineto(187,339);
lineto(314,348);

getch();
return 0;
}





