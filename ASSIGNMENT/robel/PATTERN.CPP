#include <cmath>
#include<graphics.h>
using namespace std;
int main(){
double RAD = M_PI/180;
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
outtextxy(200,30, "NAME: ROBEL MAMO");
int x=getmaxx()/2;
int y=240, l=5;
int alpha = 0,i=0,r=50,j=0;
int color[]={2,3,4,5,14,1};
while(!kbhit()){
    moveto(x+l*cos(i*RAD),y+l*sin(i*RAD));
    while(j<6){
        setcolor(color[j]);
        i+=60;
        lineto(x+l*cos(i*RAD),y+l*sin(i*RAD));
        delay(20);
    j++;
    }
    j=0; i-=4;  l+=5;
}
getch();

}
