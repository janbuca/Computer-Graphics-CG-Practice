#include <iostream.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
struct snake_head//定义蛇头结构体，默认为所有元素共有访问
{

	int x;//保存蛇头当前的x值
	int y;//保存蛇头当前的y值
	int dir;//蛇头的移动方向1,2,3,4分别为上下左右
	int speed;//蛇头的移动速度
};
class food
{
private:
	friend class snake;//声明为snake类的友元类
protected:
	int x,y;//食物左上角的顶点坐标

public:
	food();//构造函数，默认食物块儿大小为2像素长宽
	~food();//析构函数，进行物块儿的消失
	void draw();//画食物
	void hide();//隐藏食物
	int getx();//获取x
	int gety();//获取y
	void set(int,int);//设置食物出现的坐标
 	bool flag;//判断是否当前需要生成食物
};
void food::set(int xx,int yy)
{
	this->x=xx;
	this->y=yy;
}

food::food()//在构造食物时候需要判断是否在蛇身上，稍后增加
{
 cout<<"food构造函数调用"<<endl;
  flag=false;
 //srand((unsigned)time(NULL));
 //x=rand()%1024;//生成整数x
 //y=rand()%480;//生成整数y
 //x=500;
 //y=200;
}
food::~food()
{
	cout<<"food析构函数调用"<<endl;
	hide();

}
void food::draw()
{
	solidrectangle(x,y,x+10,y+10);
}
void food::hide()
{
	clearrectangle(x,y,x+10,y+10);
}
int food::getx()
{
	return x;
}
int food::gety()
{
	return y;
}
class snake
{
private:
	friend class food;
protected:	
	snake_head head;
	int length;//蛇的长度
	vector <snake_head> body;
	
public:
    snake();//蛇的构造函数，在游戏开始时进行调用ok
	~snake();//蛇的析构函数，在游戏结束时进行调用ok
	void move(int);//根据当前方向进行蛇身的移动ok
	int iscollision();//判断蛇头是否发生了碰撞事件,分别为撞墙时返回0，撞食物是返回1，撞自己返回2，没有碰撞返回3
    bool iseat(int,int);//判断是否蛇吃到了食物
    void draw_snake();//画蛇ok
	void hide_snake();//蛇的消隐ok
	void add_body();//增加蛇的身体长度	ok
	bool live;//判断是否活着,开始时候蛇为活着
};
snake::snake()
{
	cout<<"snake构造函数调用"<<endl;
	live=true;
	length=0;
	head.x=500;
	head.y=300;
	head.dir=3;
	head.speed=10;
	body.push_back(head);//body[0]用来保存蛇头的信息
	
}
snake::~snake()
{
	cout<<"snake被销毁"<<endl;
}
void snake::move(int d)//蛇进行移动的实现函数
{
	body[0].dir=d;
	for(int i=length;i>=1;i--)//蛇进行移动的关键,让蛇的每一个节点的坐标值等于前一个节点的值
	 {
      body[i].x=body[i-1].x;
	  body[i].y=body[i-1].y;
	  body[i].dir=body[i-1].dir;
	 
	 }
	switch (d)
	{
	case 1:  //上
		{
			head.y-=head.speed;
			body[0].y-=head.speed;
		}break;
	case 2:  //下
		{
            head.y+=head.speed;
			body[0].y+=head.speed;
		}break;
	case 3: //左
		{
			head.x-=head.speed;
			body[0].x-=head.speed;
		}break;
	case 4:  //右
		{
			head.x+=head.speed;
			body[0].x+=head.speed;
		}break;

	}
}
void snake::draw_snake()//画蛇操作
{
 int top,left;
 for(int i=0;i<=length;i++)
 {
	 left=body[i].x;
	 top=body[i].y;
	 solidrectangle(left,top,left+10,top+10);
 }
 
}
void snake::hide_snake()//进行蛇的消隐
{
int top,left;
 for(int i=0;i<=length;i++)
 {
	 left=body[i].x;
	 top=body[i].y;
	 clearrectangle(left,top,left+10,top+10);
 }
}
void snake::add_body()//进行蛇身长度的增加
{
	snake_head h;
	int dir=body[length].dir;
	switch(dir)
	{
	case 1:
		{
		h.x=body[length].x;
		h.y=body[length].y+10;
		h.dir=dir;
		body.push_back(h);//将新增加的节点纳入数组
		length++;//长度加1
		
		
		}break;
	case 2:
		{
			h.x=body[length].x;
			h.y=body[length].y-10;
			body.push_back(h);
			length++;
		}break;
	case 3:
		{
			h.x=body[length].x+10;
			h.y=body[length].y;
			body.push_back(h);
			length++;
		}break;
	case 4:
		{
			h.x=body[length].x-10;
			h.y=body[length].y;
			body.push_back(h);
            length++;
		}break;

	}
	int len=length-1;
	 body[length].dir=body[len].dir; 
	 cout<<length<<endl;
	
}
int snake::iscollision()
{
	//判断是否和自身发生碰撞
	if(body[length].x+2==body[0].x){live=false;return 2;}//发生了追尾事件，返回与自身发生了碰撞
	for (int i=1;i<=length;i++)
	{
		if((body[0].y+2==body[i].y)||(body[0].y==body[i].y+2)){live=false;return 2;}
	}
	if(body[0].x-10<=0||body[0].x+10>=1014||body[0].y-10<=0||body[0].y+10>=470){live=false;return 0;}
	
	return 3;
}
bool snake::iseat(int fx,int fy)
{
	if(body[0].x==fx&&body[0].y==fy){cout<<"eat"<<endl;return true;}
 else return false;
}
void draw_wall()
{
	rectangle(10,10,1014,470);
}

char game_over()
{
	cout<<"\t--------------------------------------------------------------------"<<endl;
	cout<<"\t-------------------------game over----------------------------------"<<endl;
	cout<<"\t-------------------------will you continue?(y/n)-------------------------"<<endl;
	char a=getchar();
	return a;
}
int game_screen()
{
	cout<<"\t--------------------------------------------------------------------"<<endl;
	cout<<"\t------------------------1.game start--------------------------------"<<endl;
	cout<<"\t------------------------2.help--------------------------------------"<<endl;
	cout<<"\t------------------------3.record------------------------------------"<<endl;
	cout<<"\t------------------------4.quit--------------------------------------"<<endl;
	cout<<"\t------------------------your choice---------------------------------"<<endl;
	int choice;
	cin>>choice;
	return choice;
}
void help_screen()
{
	cout<<"\t----------------------------------------------------------------------"<<endl;
	cout<<"\tpress 'w': up,press 's':down,press 'a':left,press 'd':right,press 'e' to exit"<<endl;
	cout<<"\t----------------------------------------------------------------------"<<endl;
}
void game_init()
{
initgraph(1024,480);//初始画布
	draw_wall();//画墙
}
void give_food(int&x1,int&y1)
{
	int x,y;
srand((unsigned)time(NULL));
do
{
  x=rand()%1004;//生成整数x
  y=rand()%460;//生成整数y
}while((x%10!=0)||(y%10!=0));
x1=x;y1=y;
}
void game_loop(int dir,snake&s)
{
	
	do
	{
     s.draw_snake();
    Sleep(200);
	s.hide_snake();
	s.move(dir);


	}while(!kbhit());
    char a=getch();
	switch(a)
	{
	case 'w':
		{
			dir=1;
		}break;
	case 's':
		{
			dir=2;
		}break;
	case 'a':
		{
			dir=3;
		}break;
	case 'd':
		{
			dir=4;
		}break;
	}

}

void play()
{
	snake s;
	food f;
	game_init();
	int x,y,sign=1,dir=1;
while(sign==1)
{
	if(f.flag==false)
	{
	 give_food(x,y);
	 f.set(x,y);
	 f.draw();
	 f.flag=true;
	}
	do
	{
     s.draw_snake();
    Sleep(450);
	s.hide_snake();
	s.move(dir);
    if(s.iseat(f.getx(),f.gety())==true){f.flag=false;s.add_body();}
	if(s.iscollision()==0||s.iscollision()==2){sign=-1;break;}

	}while(!kbhit());
    char a=getch();
	switch(a)
	{
	case 'w':
		{
			dir=1;
		}break;
	case 's':
		{
			dir=2;
		}break;
	case 'a':
		{
			dir=3;
		}break;
	case 'd':
		{
			dir=4;
		}break;
	case 'e':
		{
			sign=-1;
		}break;
	}
	
	
}
 closegraph();	

}