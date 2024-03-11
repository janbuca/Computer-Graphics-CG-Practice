#include <graphics.h>
#include <cmath>
int main()
{int gd = DETECT, gm;
    double angle = 0;
    double x=10, y, RAD= M_PI/180;

    initgraph(&gd, &gm, "");
    outtextxy(200,30, "NAME: ROBEL MAMO");
 line(10, getmaxy() / 2, getmaxx(), getmaxy() / 2);
 setlinestyle(1,0,3);
 line(10,170,10,310);
 setlinestyle(1,0,2);

 moveto(x,240);
 for( ;x < getmaxx(); x+=5) {
setcolor(14);
     y = 50*sin(angle*RAD);
     y = getmaxy()/2 + y;

  lineto(x, y );
  delay(20);

  /* increment angle */
  angle+=5;
 }
 getch();
 closegraph();
}
