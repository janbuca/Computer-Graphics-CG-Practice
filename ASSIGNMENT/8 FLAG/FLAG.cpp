//Exercises on arc
//
#include<graphics.h>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");
int i=0;
int angle;
int rad;

cout<<"Enter The Radius"<<endl;
cin>>rad;
cout<<"Enter The angle"<<endl;
cin>>angle;

int f=rad/3;
int c=4;
int g,y,r;
int j=0;
int k=0;
int l=0;

while(!kbhit())
{
	while(i<rad)
	{
	 while(j<rad/3)
	{
setcolor(4);
arc(320,240,90-angle,90+angle,10+j);
delay(30);

i++;
j++;
}


while(k<rad/3)
	{
setcolor(YELLOW);
arc(320,240,90-angle,90+angle,10+j+k);
delay(30);

i++;
//j++;
k++;
}


while(l<rad/3)
	{
setcolor(2);
arc(320,240,90-angle,90+angle,10+j+k+l);
delay(30);

i++;
//j++;
//k++;
l++;
}


}
}
getch();
return 0;
}
