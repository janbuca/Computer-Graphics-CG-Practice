#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
//setlinestyle(0,1,3);
while(!kbhit()){
setcolor(15);
moveto(130,390);
lineto(520,465);
lineto(680,370);
lineto(685,115);
lineto(532,23);
lineto(285,67);
lineto(285,108);
lineto(483,82);
lineto(483,251);
lineto(130,245);
lineto(130,280);
lineto(530,305);
lineto(530,23);
moveto(530,305);
lineto(680,277);
moveto(624,286);
lineto(620,402);
lineto(551,392);
lineto(551,300);
lineto(617,302);
lineto(616,400);
//1sfw
moveto(285,108);
lineto(325,115);
setcolor(4);
lineto(483,96);
moveto(325,208);
lineto(483,205);
moveto(325,208);
lineto(325,115);
setcolor(15);
moveto(316,210);
lineto(484,205);
moveto(316,210);
lineto(316,249);
setcolor(14);
moveto(140,246);
lineto(140,200);
lineto(318,218);
moveto(140,200);
lineto(482,180);


//end
//gwindow
setcolor(4);
moveto(551,392);
lineto(444,441);
lineto(179,392);
lineto(179,283);
moveto(235,285);
lineto(235,402);
moveto(444,441);
lineto(444,300);
moveto(363,426);
lineto(363,294);
moveto(295,414);
lineto(295,290);
//
//exta0
//setcolor(15);
//moveto(624,286);
//lineto(875,300);
//moveto(624,403);
//lineto(875,417);

//swiming area
   //rectangle(128,390,442,516);
setcolor(2);
setfillstyle(3,1);
ellipse(250,450,0,360,100,23);
floodfill(250,450,2);
moveto(130,390);
lineto(0,420);
moveto(520,465);
lineto(417,532);
lineto(0,420);
//extra1
setcolor(15);
moveto(565,85);
lineto(865,55);
moveto(565,290);
lineto(865,290);
lineto(865,55);
lineto(965,138);
moveto(865,290);
lineto(965,265);
lineto(965,138);
  //iner window
moveto(565,85);
lineto(565,290);
  //iw
moveto(605,115);
lineto(605,260);
lineto(825,260);
lineto(825,85);
lineto(605,115);
  //
//extra parking
moveto(678,370);
lineto(876,408);
moveto(417,532);
lineto(772,627);
lineto(876,408);
     //crose
//moveto(534,580);
//lineto(578,539);
//moveto(605,522);
//lineto(660,486);
//moveto(692,485);
//lineto(744,431);
//car
setcolor(6);
moveto(550,520);
lineto(550,475);
lineto(725,510);
lineto(725,555);
lineto(550,520);

moveto(725,510);
lineto(760,480);
moveto(550,475);
lineto(585,445);
lineto(760,480);

lineto(775,440);
moveto(585,445);
lineto(600,405);
lineto(775,440);

lineto(850,390);
moveto(600,405);
lineto(675,355);
lineto(850,390);

moveto(725,555);
lineto(860,450);
//circle(760,525,10);

delay(1);
 }
getch();
return 0;
}

