#include "snake.h"
int main()
{
	/*initgraph(1024,480);
	snake a;
	food f;
	f.draw();
	draw_wall();
	a.add_body();
	a.add_body();
	a.add_body();
	a.add_body();
	a.add_body();
	while(!kbhit()&&(a.iscollision(f.getx(),f.gety())==3))
	{
	if(a.iseat(f.getx(),f.gety())==true){a.add_body();}
	a.draw_snake();
    Sleep(300);
	a.hide_snake();
	a.move(1);
	}

	getch();
	closegraph();
//	game_rule game;
	//play(game);*/
   bool flag=true;
   while(flag==true)
   {
	   int choice=game_screen();
	   switch(choice)
	   {
	   case 1:
		   {
			  // while(1)
			   play();
		   }break;
	   case 2:
		   {
			   help_screen();
		   }break;
	   case 3:
		   {
		   }break;
	   case 4:
		   {
			   flag=false;
		   }break;
	   }
   }













	return 0;
}