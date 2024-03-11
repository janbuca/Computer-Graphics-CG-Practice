//simple snake game
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
int i1=0,j1=0,i2=0,j2=0;
char key;
int x1=60,y1=240,x2=80,y2=260;
int fruitX,fruitY;
fruitX = rand()%510+60;

fruitY = rand()%350+60;



//frame
moveto(0,430);
lineto(640,430);

moveto(50,430);
lineto(50,0);

moveto(0,50);
lineto(640,50);

moveto(590,0);
lineto(590,480);
//
//fruit
circle(fruitX,fruitY,5);
//

//Game over
//if(x1=50)
//{
//	cleardevice();
//outtextxy(320, 240,"Game Over !");
//cout<<"Game Over !";
//getch();	
//}
//
//setup

//


while(!kbhit()){

setcolor(13);
 rectangle(x1+i1,y1,x2+i2,y2);

delay(10);

//cleardevice();
setcolor(0);
//setfillstyle(7,5);
 rectangle(x1+i1,y1,x2+i2,y2);

i1++;
i2++;

}

//if(i1=51)
//{
	//cleardevice();
	//outtextxy(320, 240, "Game Over !");
	//getch();
//	exit(1);
//}

do
   {
   	key=getch();
	switch(key)
	 {
   	  case keyup:
	    	{
	    	  while(!kbhit())
			  {
	    	    //cleardevice();
	    	     setcolor(14);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			    
			    delay(10);
			    
			    //cleardevice();
			    setcolor(0);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			
			    j1--;
			    j2--;
			  }
			    
	        break;	
			}
			
	  case keydown:
	    	{
	    	  while(!kbhit())
			  {
	    	    //cleardevice();
	    	    setcolor(14);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			    
			    delay(10);
			    
			    //cleardevice();
			    setcolor(0);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			
			    j1++;
			    j2++;
			  }
			    
	        break;	
			}
			
		case keyright:
	    	{
	    	  while(!kbhit())
			  {
	    	    //cleardevice();
	    	    setcolor(14);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			    
			    delay(10);
			    
			    //cleardevice();
			    setcolor(0);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			
			    i1++;
			    i2++;
			  }
			    
	        break;	
			}
			
		case keyleft:
	    	{
	    	  while(!kbhit())
			  {
	    	    //cleardevice();
	    	    setcolor(14);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			    
			    delay(10);
			    
			    //cleardevice();
			    setcolor(0);
			     //rectangle(10+i1,240+j1,30+i2,260+j2);
			     rectangle(x1+i1,y1+j1,x2+i2,y2+j2);
			
			    i1--;
			    i2--;
			  }
			    
	        break;	
			}
			
		case keyesc:
			exit(0);
		default:;
	}
	
}while(key!=keyesc);



return 0;
}

