#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

while(!kbhit()){
moveto(100,100);
lineto(200,200);
lineto(300,100);

moveto(200,200);
lineto(200,300);

delay(1);
 }
getch();
return 0;
}

