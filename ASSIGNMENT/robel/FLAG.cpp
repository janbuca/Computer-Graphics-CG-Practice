#include <graphics.h>
#include <iostream>
using namespace std;
int main(){
    initwindow(getmaxx(),getmaxy());
    outtextxy(200,30, "NAME: ROBEL MAMO");
    int radius, sangle, eangle,angle;
    cout<<"Enter Radius of the Rainbow: ";
    cin>>radius;
    cout<<"Enter Angle of the Radius: ";
    cin>>sangle;
    eangle=180-sangle;
    int color[]={4,14,2};
    int i=0;
while(i<3){
for(int j=0; j<60; j++){
    setcolor(color[i]);
    arc(320,380,sangle,eangle,radius);
    delay(20);
    radius++;
}i++;
}
getch();
closegraph();
}
