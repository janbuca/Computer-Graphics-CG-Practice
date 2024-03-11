//Exercises on arc
//
#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

int r=4,y=0,g=0;

while(!kbhit())
{
//switch 1
setcolor(7);
//settextstyle(font, direction, font_size);

//outtextxy(290,100, "STOP");
setcolor(14);

//frame left
 //rectangle
rectangle(250,30,390,410);
//lense 1
moveto(250,50);
lineto(150,50);
lineto(200,150);
lineto(250,150);
//lense 2
moveto(250,170);
lineto(150,170);
lineto(200,270);
lineto(250,270);
//lense 3
moveto(250,290);
lineto(150,290);
lineto(200,390);
lineto(250,390);
//end

setfillstyle(1,4);
fillellipse(320,100,50,50);
settextstyle(1,0,2);
outtextxy(280,90, "STOP");

setfillstyle(1,0);
fillellipse(320,220,50,50);

setfillstyle(1,0);
fillellipse(320,340,50,50);

  delay(2000);
//switch 2
  cleardevice();

setcolor(7);
setcolor(14);

//frame left
 //rectangle
rectangle(250,30,390,410);
//lense 1
moveto(250,50);
lineto(150,50);
lineto(200,150);
lineto(250,150);
//lense 2
moveto(250,170);
lineto(150,170);
lineto(200,270);
lineto(250,270);
//lense 3
moveto(250,290);
lineto(150,290);
lineto(200,390);
lineto(250,390);
//end

//red light
setfillstyle(1,0);
fillellipse(320,100,50,50);
//yellow light
setfillstyle(1,14);
fillellipse(320,220,50,50);
settextstyle(1,0,1);
outtextxy(265,210, "READY");
//green light
setfillstyle(1,0);
fillellipse(320,340,50,50);
    
    delay(2000);
//switch 3
    cleardevice();
    
setcolor(7);
setcolor(14);

//frame left
 //rectangle
rectangle(250,30,390,410);
//lense 1
moveto(250,50);
lineto(150,50);
lineto(200,150);
lineto(250,150);
//lense 2
moveto(250,170);
lineto(150,170);
lineto(200,270);
lineto(250,270);
//lense 3
moveto(250,290);
lineto(150,290);
lineto(200,390);
lineto(250,390);
//end

setfillstyle(1,0);
fillellipse(320,100,50,50);

setfillstyle(1,0);
fillellipse(320,220,50,50);

setfillstyle(1,2);
fillellipse(320,340,50,50);
settextstyle(1,0,1);
outtextxy(300,330, "GO");

delay(2000);
    cleardevice();
    
    
}
getch();
return 0;
}




