/****************************************************************
 Rakibul Islam      ID: 12.01.04.001
 Shofiur Rahman     ID: 12.01.04.012
 Eshtiak Ahmed      ID: 12.01.04.013
 -------------------------------------
 Date: 21.01.2013, Platform: Turbo C
*****************************************************************/

#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int i,x,y,incre=5,life=3,b=0,level=1,button,score=0,n[300],m[300];
int spd=150,limit=0,choise1=0,life1,life2;
char key,ch,sc[100],lv[100],lf[100];
FILE *fp1;

struct srlnm
{
    int s;
    char nm[10];
}sn,sn1;
void border();
void border1();
void firstpage();
void menupage();
void menufunction();
void move();
void check();
void mark();
void lvl1();
void lvl2();
void lvl3();
void lvl4();
void lvl5();
void maze();
void maze1();
void lvlcomplete();
void win();
void hiscrt();
void hisrd();
void option();
void difficulty();
void intro();
void about();
void quit();

void border()
{
    setbkcolor(0);
    setcolor(14);
    setfillstyle(SOLID_FILL,GREEN);
    bar(15,15,625,465);
    setfillstyle(7,RED);
    bar(25,25,615,455);
    setfillstyle(SOLID_FILL,BLUE);
    bar(35,35,605,445);
    setfillstyle(WIDE_DOT_FILL,DARKGRAY);
    bar(45,45,595,435);
}

void border1()
{
    setbkcolor(0);
    setcolor(14);
    line(35,35,605,35);
    line(35,445,605,445);
    line(35,35,35,445);
    line(605,35,605,445);
    line(35,390,605,390);
}

void firstpage()
{
    border();
    setcolor(10);
    settextstyle(4,0,7);
    outtextxy(160,80,"Snake Game");
    setcolor(3);
    settextstyle(2,0,6);
    outtextxy(273,295,"LOADING.....");
    setcolor(5);
    setfillstyle(SOLID_FILL,BLUE);
    bar(160,270,480,290);
    setfillstyle(SOLID_FILL,BLACK);
    bar(164,272,476,288);
    for(i=0;i<=298;i+=18){
	setfillstyle(SOLID_FILL,YELLOW);
	bar(168+i,274,182+i,286);
	delay(300);
    }
}

void menupage()
{
    cleardevice();
    border();
    setcolor(10);
    settextstyle(10,0,4);
    outtextxy(180,75,"Snake Game");
    setcolor(WHITE);
    settextstyle(3,0,3);
    outtextxy(260,160,"Start Game");
    settextstyle(3,0,3);
    outtextxy(290,195,"Option");
    settextstyle(3,0,3);
    outtextxy(270,230,"Highscore");
    settextstyle(3,0,3);
    outtextxy(300,265,"Intro");
    settextstyle(3,0,3);
    outtextxy(290,300,"About");
    settextstyle(3,0,3);
    outtextxy(300,335,"Exit");

    for(i=1;i<=10;i++){
	setcolor(i);
	settextstyle(10,0,4);
	outtextxy(180,75,"Snake Game");
	delay(150);
    }
    menufunction();
}

void menufunction()
{
    key=getch();
    switch(key)
    {
	case 'q':
	    quit();
	case 's':
	    choise1=0;
	    lvl1();
	case 'h':
	    hisrd();
	case 'o':
	    option();
	case 'a':
	    about();
	case 'i':
	    intro();
	default:
	    menufunction();
    }
}

void hiscrt()
{
	cleardevice();
	fp1=fopen("C:\\TC\\file1.txt","wb");
	if(fp1==NULL)
	{
	    printf("Error occured while opening file\n");
	    getch();
	    exit(1);
	}
	sn.s=score;
	printf("NAME: ");
	scanf("%s",&sn.nm);
	getchar();

	fwrite(&sn,sizeof(sn),3,fp1);
	fclose(fp1);
	hisrd();
}

void hisrd()
{
	fp1=fopen("C:\\TC\\file1.txt","rb");
	if(fp1==NULL)
	{
		printf("Error occured while opening file");
		getch();
		exit(1);
	}

       fread(&sn1,sizeof(sn1),3,fp1);
       cleardevice();
       printf("%d\t",sn1.s);
       puts(sn1.nm);
       getch();
       fclose(fp1);
       menupage();
}

void option()
{
    cleardevice();
    border();
    settextstyle(3,0,5);
    outtextxy(240,80,"Option");
    setcolor(WHITE);
    settextstyle(3,0,3);
    outtextxy(210,165,"# Difficulty level");
    key=getch();
    switch(key)
    {
	case 'd':
	    difficulty();
	case 'c':

	case 'q':
	    menupage();
	default:
	    option();
    }
}

void difficulty()
{
    cleardevice();
    border();
    setcolor(WHITE);
    settextstyle(3,0,3);
    outtextxy(240,80,"Difficulty Level");
    outtextxy(260,165,"1. Easy");
    outtextxy(260,200,"2. Normal");
    outtextxy(260,235,"3. Hard");
    key=getch();
    switch(key)
    {
	case '1':
	    choise1=1;
	    lvl1();
	case '2':
	    choise1=2;
	    lvl1();
	case '3':
	    choise1=3;
	    lvl1();
	case 'q':
	    option();
	default:
	    difficulty();
    }
}

void intro()
{
    cleardevice();
    border();
    setcolor(WHITE);
    settextstyle(3,0,3);
    outtextxy(200,80,"Game Introduction");
    outtextxy(100,110,"--------------------------");
    settextstyle(3,0,1);
    outtextxy(60,140,"This is a normal snake game.");
    outtextxy(60,160,"Use the UP,DOWN,LEFT,RIGHT key to control the snake.");
    outtextxy(60,180,"Use UP key to move the snake upward.");
    outtextxy(60,200,"Use DOWN key to move the snake downward.");
    outtextxy(60,220,"Use the RIGHT key to move the snake right.");
    outtextxy(60,240,"Use the LEFT key to move the snake left.");
    outtextxy(60,260,"With every food your snake length increases.");
    outtextxy(60,280,"When you score 500 you'll advance to next level.");
    outtextxy(60,300,"Every new level comes with new difficulties & surprises.");
    outtextxy(100,330,"---------------------------------");
    if(getch()=='q') menupage();
    else intro();
}

void about()
{
    cleardevice();
    border();
    setcolor(WHITE);
    settextstyle(3,0,3);
    outtextxy(230,70,"Developed by -");
    settextstyle(3,0,1);
    outtextxy(100,130,"-----------------------------------");
    outtextxy(130,160,"Rakibul Islam       ID: 12.01.04.001");
    outtextxy(130,180,"Shofiur Rahman    ID: 12.01.04.012");
    outtextxy(130,200,"Eshtiak Ahmed     ID: 12.01.04.013");
    outtextxy(100,230,"-----------------------------------");
    outtextxy(105,260,"Ahsanullah University of Science and Technology");
    outtextxy(105,280,"Department of Computer Science and Engineering");
    outtextxy(100,310,"-----------------------------------");
    if(getch()=='q') menupage();
    else about();
}

void quit(){
     cleardevice();
     border();
     setcolor(WHITE);
     settextstyle(3,0,3);
     outtextxy(200,160,"Thankyou for playing");
     getch();
     cleardevice();
     exit(1);
}

void gameover()
{
     cleardevice();
     border();
     setcolor(WHITE);
     settextstyle(3,0,3);
     outtextxy(250,160,"GAME OVER");
     getch();
     if(sn.s<score) hiscrt();
     menupage();
}

void win()
{
     cleardevice();
     border();
     setcolor(WHITE);
     settextstyle(3,0,3);
     outtextxy(180,150,"-------------------");
     outtextxy(235,180,"Congratulation");
     outtextxy(210,220,"You win the G@ME");
     outtextxy(180,250,"-------------------");
     getch();
	 hiscrt();
}

void s0und()
{
     int i;
     for(i=200;i<=1000;i+=20)
     {
	 sound(i);
	 delay(1);
     }
     nosound();
}

void check()
{
     int a;
     for(a=1;a<10;a++)
     if(m[0]==m[a]&&n[0]==n[a])
     {
	 life--;
	 if(life<=0)
	 {
	     gameover();
	 }
     }
     else continue;
}

void mark(int a, int b, int c){
    cleardevice();
    border1();
    setcolor(14);
    settextstyle(10,0,1);
    sc[100]=a;
    lf[100]=b;
    lv[100]=c;
    itoa(score,sc,10);
    itoa(life,lf,10);
    itoa(level,lv,10);
    outtextxy(65,390,"Score:");
    outtextxy(160,390,sc);
    outtextxy(300,390,"Life:");
    outtextxy(370,390,lf);
    outtextxy(465,390,"Level:");
    outtextxy(555,390,lv);
}

void lvlcomplete(){
     cleardevice();
     border1();
     setcolor(WHITE);
     settextstyle(3,0,3);
     outtextxy(210,160,"LEVEL COMPLETE");
     outtextxy(200,200,"Next Level Starting");
	 outtextxy(200,250,"Press 's' to start");
     key=getch();
     if(key=='s') goto code3;
     else lvlcomplete();
     code3:
     switch(level)
     {
	 case 2: lvl2();
	 case 3: lvl3();
	 case 4: lvl4();
	 case 5: lvl5();
     }
}

void maze()
{
    setfillstyle(SOLID_FILL,14);
    bar(150,170,250,180);
    bar(200,260,300,270);
    bar(450,150,460,250);
}

void maze1()
{
    border1();
    setfillstyle(SOLID_FILL,14);
    bar(150,220,160,320);
    bar(300,100,310,200);
    bar(450,220,460,320);
}

void move()
{
    cleardevice();
    border();
    incre=5;
    int x=-100,y=140,a=0,i=0,j,temp,p,q;
    mark(score,life,level);
    code1:
    randomize();
    p=rand()%552;
    q=rand()%386;
    if(q<=70||p<=55) goto code1;
    while(1)
    {
	if(level==3||level==4) maze();
	if(level==5) maze1();
	setcolor(12);
	setfillstyle(SOLID_FILL,RED);
	circle(p,q,5);
	floodfill(p,q,12);
	if(kbhit())
	{
	    ch=getch();
	    if(ch=='H'&&a!=2) a=1;
	    if(ch=='P'&&a!=1) a=2;
	    if(ch=='K'&&a!=4) a=3;
	    if(ch=='M'&&a!=3) a=4;
	    if(ch=='q') menupage();
	}
	if(i<30)
	{
	    m[i]=x;
	    n[i]=y;
	    i++;
	}
	if(i>=30)
	{
	    for(j=incre;j>=0;j--)
	    {
		m[1+j]=m[j];
		n[1+j]=n[j];
	    }
	    m[0]=x;
	    n[0]=y;
	    for(j=1;j<incre;j++)
	    {
		setcolor(14);
		setfillstyle(SOLID_FILL,BLUE);
		circle(m[j],n[j],6);
		floodfill(m[j],n[j],14);
	    }
	    delay(spd);
	    setcolor(BLACK);
	    setfillstyle(SOLID_FILL,BLACK);
	    circle(m[j],n[j],6);
	    floodfill(m[j],n[j],BLACK);
	}
	check();

	if(x-p<=11&&x-p>=-11&&y-q<=11&&y-q>=-11)
	{
	    s0und();
	    incre++;
	    score+=20;
	    if(score>=limit)
	    {
		level++;
		if(level>=6) win();
		lvlcomplete();
	    }
	    mark(score,life,level);
	    code2:
	    randomize();
	    p=rand()%552;
	    q=rand()%386;
	    if(q<=70||p<=55) goto code2;
	}

	if(a==1) y-=12;    //up
	if(a==2) y+=12;    //down
	if(a==3) x-=12;    //left
	if(a==4) x+=12;	   //right

	if(x>=590) x=55;
	if(y<=50) y=380;
	if(y>=385) y=55;
	if(x<=45) x=585;

	if(a==0)
	{
	    y=100;
	    x+=12;
	}

	if(level==3||level==4)
	{
	    life1=life;
	    if(x>=150&&x<=250&&y>=170&&y<=180) life--;
	    if(x>=200&&x<=300&&y>=260&&y<=270) life--;
	    if(x>=450&&x<=460&&y>=150&&y<=250) life--;

	    if(life1!=life)
	    {
		cleardevice();
		border1();
		mark(score,life,level);
	    }
	}

	if(level==5)
	{
	    life2=life;
	    if(x>=150&&x<=160&&y>=220&&y<=320) life--;
	    if(x>=300&&x<=310&&y>=100&&y<=200) life--;
	    if(x>=450&&x<=460&&y>=220&&y<=320) life--;

	    if(life2!=life)
	    {
		cleardevice();
		border1();
		mark(score,life,level);
	    }
	}

	if(life<=0)
	{
	    gameover();
	}
    }
}

void lvl1()
{
    limit=100;life=3;level=1,score=0;
    if(choise1==0) spd=150;
    else if(choise1==1) spd=150;
    else if(choise1==2) spd=140;
    else if(choise1==3) spd=130;
    move();
}

void lvl2()
{
    limit=200;level=2;score=100;
    if(choise1==0) spd=100;
    else if(choise1==1) spd=100;
    else if(choise1==2) spd=90;
    else if(choise1==3) spd=80;
    move();
}

void lvl3()
{
    limit=300;level=3;score=200;
    if(choise1==0) spd=70;
    else if(choise1==1) spd=70;
    else if(choise1==2) spd=60;
    else if(choise1==3) spd=55;
    move();
}

void lvl4()
{
    limit=400;level=4;score=300;
    if(choise1==0) spd=50;
    else if(choise1==1) spd=50;
    else if(choise1==2) spd=45;
    else if(choise1==3) spd=40;
    move();
}

void lvl5()
{
    limit=500;level=5;score=400;
    if(choise1==0) spd=40;
    else if(choise1==1) spd=40;
    else if(choise1==2) spd=35;
    else if(choise1==3) spd=30;
    move();
}

void main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:/TC/bgi");
    firstpage();
    menupage();
    closegraph();
}