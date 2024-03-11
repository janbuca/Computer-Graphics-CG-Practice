#include<graphics.h>
#include<iostream>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include <dos.h>

using namespace std;

int i=0;

void Translation()
{
	//the original
	int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
    drawpoly(8, arr);
	//
	int tx,ty;
	outtextxy(280,50, "Developed by kirubel Jalleta");
	
	cout<<"Enter translation coordinate tx:"<<endl;
	cin>>tx;
	cout<<"Enter translation coordinate ty:"<<endl;
    cin>>ty;
     
     setcolor(4);
	 int arrT[] = {320+tx,140+ty,420+tx,240+ty,370+tx,240+ty,370+tx,340+ty,270+tx,340+ty,270+tx,240+ty,220+tx,240+ty,320+tx,140+ty};
     drawpoly(8, arrT);
     getch();
     closegraph();
}

void Scaling()
{
	//the original
	int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
    drawpoly(8, arr);
	//
	double sx,sy;
	outtextxy(280,50, "Developed by kirubel Jalleta");
	
	cout<<"Enter Scaling factor Sx:"<<endl;
	cin>>sx;
	cout<<"Enter Scaling factors Sy:"<<endl;
    cin>>sy;
    
    
     setcolor(4);
	 int arrT[] = {320*sx,140*sy,420*sx,240*sy,370*sx,240*sy,370*sx,340*sy,270*sx,340*sy,270*sx,240*sy,220*sx,240*sy,320*sx,140*sy};
     drawpoly(8, arrT);
     i=i+1;
	 getch();
	 closegraph();
}

void Rotation()
{
	outtextxy(280,50, "Developed by kirubel Jalleta");
    
    double s,c,angle;
    c = cos(angle *3.14/180);  
    s = sin(angle *3.14/180);
    
    cout<<"Enter rotation angle:"<<endl;
	cin>>angle;
    //
//    int arro[] = {320,140,
//	             420,240,
//				 370,240,
//				 370,340,
//				 270,340,
//				 270,240,
//				 220,240,
//				 320,140};
//    drawpoly(8, arro);
	//
	//x'=xcos?-ysin?
    //y'=xsin?+ycos?
    int x1=320,x2=420,x3=370,x4=370,x5=270,x6=270,x7=220,x8=320;
    int y1=140,y2=240,y3=240,y4=340,y5=340,y6=240,y7=240,y8=140;
    
   // x1 = floor(x1 * c + y1 * s);
   cleardevice();
   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x4,y4);
   line(x4,y4,x5,y5);
   line(x5,y5,x6,y6);
   line(x6,y6,x7,y7);
   line(x7,y7,x8,y8);
    
    int rx1=x1*c+y1*s,
        rx2=x2*c+y2*s,
        rx3=x3*c+y3*s,
        rx4=x4*c+y4*s,
        rx5=x5*c+y5*s,
        rx6=x6*c+y6*s,
        rx7=x7*c+y7*s,
        rx8=x8*c+y8*s;
    //y1 = floor(-x1 * s + y1 * c);
    int ry1=-x1*s+y1*c,
        ry2=-x2*s+y2*c,
        ry3=-x3*s+y3*c,
        ry4=-x4*s+y4*c,
        ry5=-x5*s+y5*c,
        ry6=-x6*s+y6*c,
        ry7=-x7*s+y7*c,
        ry8=-x8*s+y8*c;
    
    setcolor(4);
    
    line(rx1,ry1,rx2,ry2);
    line(rx2,ry2,rx3,ry3);
    line(rx3,ry3,rx4,ry4);
    line(rx4,ry4,rx5,ry5);
    line(rx5,ry5,rx6,ry6);
    line(rx6,ry6,rx7,ry7);
    line(rx7,ry7,rx8,ry8);
				  
//	int arrR[] = {(x1*cos(a))-(y1*sin(a)) , (x1*sin(a))+(y1*cos(a)),
//	              (x2*cos(a))-(y2*sin(a)) , (x2*sin(a))+(y2*cos(a)),
//				  (x3*cos(a))-(y3*sin(a)) , (x3*sin(a))+(y3*cos(a)),
//				  (x4*cos(a))-(y4*sin(a)) , (x4*sin(a))+(y4*cos(a)),
//				  (x5*cos(a))-(y5*sin(a)) , (x5*sin(a))+(y5*cos(a)),
//				  (x6*cos(a))-(y6*sin(a)) , (x6*sin(a))+(y6*cos(a)),
//				  (x7*cos(a))-(y7*sin(a)) , (x7*sin(a))+(y7*cos(a)),
//				  (x8*cos(a))-
    
			 getch();
			 closegraph();
}

void ReflectionXA1Q()
{
	//the original
	int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
    drawpoly(8, arr);
	//
	outtextxy(280,50, "Developed by kirubel Jalleta");
	
	setcolor(4);
	// Reflection along y-axis i.e.,
    // in 3rd quadrant
	int arrx[] = {getmaxy()-320,140,getmaxy()-420,240,getmaxy()-370,240,getmaxy()-370,340,getmaxy()-270,340,getmaxy()-270,240,getmaxy()-220,240,getmaxy()-320,140};
    drawpoly(8, arrx);
    
    getch();
    closegraph();
}

void ReflectionYA3Q()
{
	//the original
	int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
    drawpoly(8, arr);
	//
	outtextxy(280,50, "Developed by kirubel Jalleta");
	
	setcolor(4);
	// Reflection along y-axis i.e.,
    // in 3rd quadrant
	int arrx[] = {320,getmaxy()-140,420,getmaxy()-240,370,getmaxy()-240,370,getmaxy()-340,270,getmaxy()-340,270,getmaxy()-240,220,getmaxy()-240,320,getmaxy()-140};
    drawpoly(8, arrx);
    
    getch();
    closegraph();
}

void ReflectionO4Q()
{
	//the original
	int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
    drawpoly(8, arr);
	//
	outtextxy(280,50, "Developed by kirubel Jalleta");
	
	setcolor(4);
	// Reflection along y-axis i.e.,
    // in 3rd quadrant
	int arrx[] = {getmaxx()-320,getmaxy()-140,getmaxx()-420,getmaxy()-240,getmaxx()-370,getmaxy()-240,getmaxx()-370,getmaxy()-340,getmaxx()-270,getmaxy()-340,getmaxx()-270,getmaxy()-240,getmaxx()-220,getmaxy()-240,getmaxx()-320,getmaxy()-140};
    drawpoly(8, arrx);
    
    getch();
    closegraph();
}

void ShearX()
{
	//the original
	          int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
              drawpoly(8, arr);
	        //
	double shy;
	outtextxy(280,50, "Developed by kirubel Jalleta");
	
			cout<<"Enter Shy:"<<endl;
	        cin>>shy;
	        //Y' = Y + Shy . X
            //X’ = X
            int y1=140+shy*320,
                y2=240+shy*420,
                y3=240+shy*370,
                y4=340+shy*370,
                y5=340+shy*270,
                y6=240+shy*270,
                y7=240+shy*220,
                y8=140+shy*320;
            //
            setcolor(4);
            int arrSH[] = {320,y1,420,y2,370,y3,370,y4,270,y5,270,y6,220,y7,320,y8};
            drawpoly(8, arrSH);
        
    getch();
    closegraph();
}
        
void ShearY()
{
	double shx;
			cout<<"Enter Shx:"<<endl;
	        cin>>shx;
			//the original
	          int arrn[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};
              drawpoly(8, arrn);
	        //
	        //X’ = X + Shx . Y
            //Y’ = Y
            int x1=320+shx*140,
            x2=420+shx*240,
            x3=370+shx*240,
            x4=370+shx*340,
            x5=270+shx*340,
            x6=270+shx*240,
            x7=220+shx*240,
            x8=320+shx*140;
            //
            setcolor(4);
            int arrY[] = {x1,140,x2,240,x3,240,x4,340,x5,340,x6,240,x7,240,x8,140};
            drawpoly(8, arrY);
            
getch();
    closegraph();  
}

int main()
{
	
	while(!kbhit())
{
	system ("cls");
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

outtextxy(280,20, "Developed by kirubel Jalleta");
outtextxy(200,30, "==========================================");
outtextxy(280,40, "2D Transformation");
outtextxy(200,50, "==========================================");

 int arr[] = {320,140,420,240,370,240,370,340,270,340,270,240,220,240,320,140};

drawpoly(8, arr);


int choice;
cout<<"Enter Choice:"<<endl;
cout<<"1)2D Translation"<<endl;
cout<<"2)Scaling"<<endl;
cout<<"3)Rotation"<<endl;
cout<<"4)Reflection along origin in 4th quadrant"<<endl;
cout<<"5)Reflection along y-axis in 3rd quadrant"<<endl;
cout<<"6)Reflection along x-axis in 1st quadrant"<<endl;
cout<<"7)Shearing in the X-direction"<<endl;
cout<<"8)Shearing in the Y-direction"<<endl;
cout<<"================================="<<endl;
cout<<"enter your op"<<endl;

cin>>choice;

switch(choice)
	{
		case 1:
			Translation();
			break;
		
		case 2:	
		     Scaling();
		     main();
		
		case 3:	
		     Rotation();
		     
		case 4:
			ReflectionO4Q();
			break;
		
		case 5:
			ReflectionYA3Q();
			break;
			
		case 6:
			ReflectionXA1Q();
			break;
		
		case 7:	
		     ShearX();
		     break;
		     
		case 8:	
		     ShearY();
		     break;
		   			
		default: break;
   }
   
}

getch();
closegraph();		
return 0;
}
