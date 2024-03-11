#include<graphics.h>
#include<iostream>
int main(int argc, char const *argv[])
{
	int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i = 0, j=0;
int c=0;

  setcolor(4);	
  line(20,190,20,290);
  line(20,240,640,240);
moveto(20,240);
while(!kbhit())
{
  while(c<50)
  {
  
  lineto(20+i,240+j);
  
  delay(100);
  
  i++;
  j++; 
}
}
getch();
return 0;
}
