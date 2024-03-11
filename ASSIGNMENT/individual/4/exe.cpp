//Exercises on arc
//exercise e
//
#include<graphics.h>
#include<iostream>
#include <dos.h>
#include <ctime>

void slide1()
{
	
	outtextxy(320, 10, "catod ray tube");
	
moveto(100,190);
lineto(300,190);

moveto(100,250);
lineto(300,250);
//
moveto(300,190);
lineto(375,150);

moveto(300,250);
lineto(375,290);
//
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
ellipse(375, 220, 270,90, 50, 70);
//moveto(375,150);
//lineto(375,290);
}

void slide2()
{
	
	outtextxy(320, 10, "catod ray tube");
	
moveto(100,190);
lineto(300,190);

moveto(100,250);
lineto(300,250);
//
moveto(300,190);
lineto(375,150);

moveto(300,250);
lineto(375,290);
//
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
ellipse(375, 220, 270,90, 50, 70);
//moveto(375,150);
//lineto(375,290);
//new
outtextxy(275, 125, "Vacuum Tube");
moveto(275,125);
lineto(300,190);
	
}

void slide3()
{
	
	outtextxy(320, 10, "catod ray tube");
	
moveto(100,190);
lineto(300,190);

moveto(100,250);
lineto(300,250);
//
moveto(300,190);
lineto(375,150);

moveto(300,250);
lineto(375,290);
//
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
ellipse(375, 220, 270,90, 50, 70);
//moveto(375,150);
//lineto(375,290);
//
outtextxy(275, 125, "Vacuum Tube");
moveto(275,125);
lineto(300,190);
//new
outtextxy(450, 125, "Phosphorous Coat");
moveto(450,125);
lineto(420,200);

	
}

void slide4()
{
	
	outtextxy(320, 10, "catod ray tube");
	
moveto(100,190);
lineto(300,190);

moveto(100,250);
lineto(300,250);
//
moveto(300,190);
lineto(375,150);

moveto(300,250);
lineto(375,290);
//
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
ellipse(375, 220, 270,90, 50, 70);
//moveto(375,150);
//lineto(375,290);
//
outtextxy(275, 125, "Vacuum Tube");
moveto(275,125);
lineto(300,190);
//new
outtextxy(450, 125, "Phosphorous Coat");
moveto(450,125);
lineto(420,200);
//new
bar3d(80,180,100,260,10,1);
outtextxy(125, 125, "Base");
moveto(125,125);
lineto(100,180);
}

void slide5()
{
	
	outtextxy(320, 10, "catod ray tube");
	
moveto(100,190);
lineto(300,190);

moveto(100,250);
lineto(300,250);
//
moveto(300,190);
lineto(375,150);

moveto(300,250);
lineto(375,290);
//
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
ellipse(375, 220, 270,90, 50, 70);
//moveto(375,150);
//lineto(375,290);
//
outtextxy(275, 125, "Vacuum Tube");
moveto(275,125);
lineto(300,190);
//new
outtextxy(450, 125, "Phosphorous Coat");
moveto(450,125);
lineto(420,200);
//bas
bar(80,180,100,260);
outtextxy(125, 125, "Base");
moveto(125,125);
lineto(100,180);
//new
//connector pins
bar(50,190,80,200);
bar(50,210,80,220);
bar(50,230,80,240);
outtextxy(100, 100, "connector pins");
moveto(100,100);
lineto(65,190);

}

void slide6()
{
	
	outtextxy(320, 10, "catod ray tube");
	
moveto(100,190);
lineto(300,190);

moveto(100,250);
lineto(300,250);
//
moveto(300,190);
lineto(375,150);

moveto(300,250);
lineto(375,290);
//
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
//ellipse(x, y, start_angle,end_angle, x_rad, y_rad);
ellipse(375, 220, 270,90, 50, 70);
//moveto(375,150);
//lineto(375,290);
//
outtextxy(275, 125, "Vacuum Tube");
moveto(275,125);
lineto(300,190);
//new
outtextxy(450, 125, "Phosphorous Coat");
moveto(450,125);
lineto(420,200);
//bar
bar(80,180,100,260);
outtextxy(125, 125, "Base");
moveto(125,125);
lineto(100,180);
//
//connector pins
bar(50,190,80,200);
bar(50,210,80,220);
bar(50,230,80,240);
outtextxy(100, 125, "connector pins");
moveto(100,125);
lineto(65,190);
//new
//electron gun 
bar(100,210,120,230);

}


int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

settextstyle(1,0,1);
setcolor(4);

slide1();
delay(3000);
cleardevice();

slide2();
delay(3000);
cleardevice();

slide3();
delay(3000);
cleardevice();

slide4();
delay(3000);
cleardevice();

slide5();
delay(3000);
cleardevice();

slide6();
delay(3000);
cleardevice();

getch();
return 0;
}





