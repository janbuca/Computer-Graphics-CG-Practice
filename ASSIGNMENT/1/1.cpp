 #include "ex.h"
 #include<fstream>
 using namespace std;
 int main()
 {
    int gd=0,gm, i=0,x,y;
     initgraph(&gd,&gm,"\\tc\\bgi");
     ifstream in;
     while(!kbhit()){
     	while(i<getmaxx()-100){
		 
     	
	 
	setcolor(5);
     moveto(80+i,50);
     
	 in.open("mycar.txt");
	 while(!in.eof())
	 {in>>x>>y;
	 lineto(x+i,y);
	 }
	 in.close();
	 delay(20);
	 	setcolor(5);
     moveto(80+i,50);
     
	 in.open("mycar.txt");
	 while(!in.eof())
	 {in>>x>>y;
	 lineto(x+i,y);
	 }
	 in.close();
	 i++;
	 	setcolor(5);
     moveto(80+i,50);
     
	 in.open("mycar.txt");
	 while(!in.eof())
	 {in>>x>>y;
	 lineto(x+i,y);
	 }
	 in.close();
}
     /*tlinestyle(0,1,3);
 
 	moveto(80,50);
     lineto(150,50);
     lineto(190,90);
     lineto(230,90);
     lineto(230,130);
     lineto(50,130);
     lineto(50,80);
     lineto(80,50);*/
     
     
}

getch();
   
}
     
     
     
    
     
     
 
 


