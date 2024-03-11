#include <dos.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include<MMsystem.h>

using namespace std;
void help();
void game();
void check();
void dead();
void level();
void high();
void stagee();
int snake_x[500],snake_y[500],snake_size = 5,score,highscore,spd = 90,l,i=0,food_numb=0,stage_2=0,stage_3=0,stage2flag=0,stage=1,stage3flag=0,fx,fy,spdd=10,f5=0,f6=0,f7=0,f8=0,f9=0,f10=0,f11=0,f12=0,f13=0;
bool font=true,checkdied = false,BONUS = false,s2=true,s3=true;
int page=0;
main()
{
    int gdirect = DETECT,gmode;  /* request autodetection */
    initgraph(&gdirect,&gmode,""); /* initialize graphics and local variables */

    int cursor_y = 130;
    char ch;
    while(1)
    {
        if(font)
        {
            setcolor(3);
            settextstyle(4,0,4);
            outtextxy(90,2," Project-1: Snake");
            settextstyle(10,0,3);
            setcolor(10);
            outtextxy(20,80," Submitted by:");
            outtextxy(40,140,"Mahfuzur Rahman Emon");
            outtextxy(40,160,"Registration No: 2017831003");
            outtextxy(20,280," Submitted to: ");
            outtextxy(40,320,"Asif Mohammed Samir Sir ");
            outtextxy(40,340,"Assistant Professor");
            outtextxy(40,360,"IICT,SUST");
            getch();
            PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
            cleardevice();
            font=false;
        }

        setcolor(10);
        settextstyle(10,0,8);
        outtextxy(85,5," Snake ");
        setcolor(LIGHTRED);
        settextstyle(3,0,3); /*this part prints menu again but inside while loop,because other functions will return here*/
        outtextxy(200,130,"New Game");
        outtextxy(200,160,"Help and Instraction");
        outtextxy(200,190,"Select Level");
        outtextxy(200,220,"Select Stage");
        outtextxy(200,250,"Highscore");
        outtextxy(200,280,"Exit");
        setcolor(LIGHTGREEN);
        outtextxy(170,420,"Visit Help and Instruction first.");
        outtextxy(160,cursor_y,"-->");
        setcolor(YELLOW);
        settextstyle(3,0,3);

        if(kbhit)
        {
            ch = getch();
            setcolor(BLACK);
            outtextxy(160,cursor_y,"-->");

            if(ch==80)
            {
                cursor_y+=30;
                PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursor_y > 280)
                    cursor_y=130;
            }
            if(ch==72)
            {
                cursor_y-=30;
                PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursor_y < 130)
                    cursor_y=280;
            }

            if(ch == 13)  ///if(ch == 13) means if pressed "Enter" button///
            {
                PlaySound("button.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursor_y==280)
                    exit(0);
                else if(cursor_y==160)
                    help();
                else if(cursor_y==130)
                    game();
                else if(cursor_y==190)
                    level();
                else if(cursor_y==220)
                    stagee();
                else if(cursor_y==250)
                    high();
            }
        }
    }
    return 0;
}
void game()
{
    clearviewport();
    freopen("GameData.txt","r",stdin);
    cin >> highscore;
    cleardevice();
    char ch;
    string key = "right";
    int maxx = getmaxx();
    int maxy = getmaxy();
    int x = 26,y = 26;

    int food_x = rand()%maxx,food_y = rand()%maxy;
    int temp;
Here:
    temp = food_x%13;
    food_x-=temp;
    temp = food_y%13;
    food_y-=temp;
    fx=food_x;
    fy=food_y;
    if(((food_y>111 && food_y<304) && ((food_x>=137 && food_x<=161)||(food_x>=476 && food_x<=498))))
        goto Here;
    int i = 0;
    int bonus = 500;

    while(true)
    {
        clearviewport();
        if(food_numb >0 && food_numb%5==4)
            BONUS = true;
        else
        {
            if(stage2flag==0 && stage3flag==0)
            {
                if(i==0)
                    bonus = 500;
                else
                    bonus = 500+(10-spd/10)*100;
                BONUS = false;
            }
            else if(stage2flag==1 && stage3flag==0)
            {
                if(i==0)
                    bonus = 700;
                else
                    bonus = 700+(10-spd/10)*100;
                BONUS = false;
            }
            else if(stage2flag==1 && stage3flag==1)
            {
                if(i==0)
                    bonus = 1000;
                else
                    bonus = 1000+(10-spd/10)*100;
                BONUS = false;
            }
        }
        if(food_numb==15||food_numb==30)
        {
            food_x=130;
            food_y=130;
        }
        if(!BONUS || bonus == 0)
        {
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL,YELLOW);
            circle(food_x,food_y,5); //x position,y position,size
            floodfill(food_x,food_y,YELLOW);
        }
        else
        {
            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            circle(food_x,food_y,5);
            floodfill(food_x,food_y,BLUE);

            char spp[1000];
            sprintf(spp,"Hurry!!! %d",bonus);
            setcolor(YELLOW);
            settextstyle(5,0,4);
            outtextxy(155,maxy+15,spp);
            // clears
        }
        maxx = getmaxx();
        maxy = getmaxy()-50;
        setcolor(YELLOW);
        line(0,maxy+8,maxx,maxy+8);

        ///stage 2
        if(food_numb >=15)
        {
            if(stage2flag==0)
            {
                clearviewport();
                settextstyle(2,0,20);
                setcolor(GREEN);
                outtextxy(180,180,"STAGE 2!");
                delay(1000);
                x=260;
                y=260;
                for(int i=0; i<=5; i++)
                {
                    int pi=1500;
                    snake_x[i]=pi;
                    snake_y[i]=pi;
                    pi+=100;
                }
                snake_size=5;
                stage2flag=1;
                key="right";
            }

            setcolor(LIGHTGREEN);
            setfillstyle(3,LIGHTGREEN);
            bar(0,0,maxx,17);
            bar(0,maxy-6,maxx,maxy+7);
            bar(0,17,17,maxy-6 );
            bar(maxx-13,13,maxx,maxy-6);

            ///stage 3
            if(food_numb >=30)
            {
                if(stage3flag==0)
                {
                    clearviewport();
                    settextstyle(2,0,20);
                    setcolor(GREEN);
                    outtextxy(180,180,"STAGE 3!");
                    delay(1000);
                    snake_size=5;
                    x=260;
                    y=260;
                    for(int i=0; i<=5; i++)
                    {
                        int pi=1500;
                        snake_x[i]=pi;
                        snake_y[i]=pi;
                        pi+=100;
                    }
                    stage3flag=1;
                    key=="right";
                }
                if(s3)
                {
                    PlaySound("button.wav",NULL,SND_FILENAME | SND_SYNC);
                    s3 = false;
                }
                setcolor(RED);
                setfillstyle(8,YELLOW);
                bar(138,112,161,304);
                bar(476,112,498,304);

                if(food_numb==40)
                {
                    if(f5==0)
                    {
                        spd-=10;
                        setcolor(LIGHTMAGENTA);
                        outtextxy(250,180,"Speed Up");
                        delay(800);
                        f5=1;
                    }
                }
                else if(food_numb==50)
                {
                    if(f6==0)
                    {
                        spd-=10;
                        setcolor(LIGHTMAGENTA);
                        outtextxy(250,180,"Speed Up");
                        delay(800);
                        f6=1;
                    }
                }
                else if(food_numb==60)
                {
                    if(f7==0)
                    {
                        spd-=10;
                        setcolor(LIGHTMAGENTA);
                        outtextxy(250,180,"Speed Up");
                        delay(800);
                        f7=1;
                    }
                }
                else if(food_numb==70)
                {
                    if(f8==0)
                    {
                        spd-=10;
                        setcolor(LIGHTMAGENTA);
                        outtextxy(250,180,"Speed Up");
                        delay(800);
                        f8=1;
                    }
                }
                else if(food_numb==80)
                {
                    if(f9==0)
                    {
                        spd-=10;
                        setcolor(LIGHTMAGENTA);
                        outtextxy(250,180,"Speed Up");
                        delay(800);
                        f9=1;
                    }
                }
                else if(food_numb==90)
                {
                    if(f10==0)
                    {
                        spd-=10;
                        setcolor(LIGHTMAGENTA);
                        outtextxy(250,180,"Speed Up");
                        delay(800);
                        f10=1;
                    }
                }

            }
        }
        if(kbhit())
        {
            ch = getch();
            if(ch == 0)
                ch = getch();
            if(ch == 72 && key != "down" )
                key = "up";
            if(ch == 80 && key != "up")
                key = "down";
            if(ch == 75 && key != "right")
                key = "left";
            if(ch == 77 && key != "left")
                key = "right";
            if(ch == 27)
            {
                cleardevice();
                for(int i=0; i<=5; i++)
                {
                    int pi=2500;
                    snake_x[i]=pi;
                    snake_y[i]=pi;
                    pi+=100;
                }
                score=0;
                food_numb=0;
                snake_size=5;
                stage2flag=0;
                stage3flag=0;
                food_x=39;
                food_y=39;
                return;
            }
        }

        for(int _size = snake_size-2; _size >= 0; _size--)
        {
            snake_x[_size+1] = snake_x[_size];
            snake_y[_size+1] = snake_y[_size];
        }
        snake_x[0] = x;
        snake_y[0] = y;///starting point of the snake

        setcolor(RED);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,RED);///head of snake
        floodfill(snake_x[0],snake_y[0],RED);

        setcolor(3);
        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],5);
            setfillstyle(SOLID_FILL,3);///body of snake
            floodfill(snake_x[_size],snake_y[_size],3);
        }

        char ara[100];
        sprintf(ara,"Score - %d",score);
        settextstyle(8,0,2);
        setcolor(GREEN);
        outtextxy(10,maxy+10,ara);

        if(score<=highscore)
        {
            sprintf(ara,"Bestscore - %d",highscore);
            setcolor(WHITE);
            settextstyle(8,0,2);
            outtextxy(400,maxy+10,ara);
        }
        else
        {
            sprintf(ara,"BESTSCORE - %d!",score);
            setcolor(YELLOW);
            settextstyle(8,0,2);
            outtextxy(400,maxy+10,ara);
        }
        sprintf(ara,"Level - %d",10-spd/10);
        setcolor(WHITE);
        settextstyle(8,0,2);
        outtextxy(10,maxy+30,ara);

        if(stage2flag==0&&stage3flag==0)
            sprintf(ara,"Stage - %d",1);
        if(stage2flag==1&&stage3flag==0)
            sprintf(ara,"Stage - %d",2);
        if(stage2flag==1&&stage3flag==1)
            sprintf(ara,"Stage - %d",3);
        setcolor(WHITE);
        settextstyle(8,0,2);
        outtextxy(400,maxy+30,ara);

        delay(spd);
        if(x == food_x && y== food_y)
        {
            snake_size++;

            if(stage2flag==0 && stage3flag==0)
                score=score+(10-spd/10);
            else if(stage2flag==1 && stage3flag==0)
                score=score+(10-spd/10)+2;
            else if(stage2flag==1 && stage3flag==1)
                score=score+(10-spd/10)+5;

            food_numb++;

            ///* Snake eats food*///
            if(food_numb%5==0 && food_numb>0)
                score+=bonus;

            food_x = rand()%maxx,food_y = rand()%maxy;
            temp = food_x%13;
            food_x-=temp;
            temp = food_y%13;
            food_y-=temp;

            if(stage2flag == 1||stage3flag == 1)
            {
                if(food_x <= 17 || food_x >= maxx-13 || food_y <= 17 || food_y >= maxy-6)
                {
here:
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;

                    if(food_x <= 17 || food_x >= maxx-13 || food_y <= 17 || food_y >= maxy-6)
                        goto here;
                }
                if(stage3flag==1)
                {
                    if(((food_x>111 && food_y<304) && ((food_x>=137 && food_x<=161)||(food_x>=476 && food_x<=498))))
heere:
                        food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                    if(((food_y>111 && food_y<304) && ((food_x>=137 && food_x<=161)||(food_x>=476 && food_x<=498))))
                        goto heere;
                }
            }
            if(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
            {
                while(food_x < 5 || food_x > maxx - 5 || food_y < 5 || food_y > maxy - 5)
                {
                    food_x = rand()%maxx,food_y = rand()%maxy;
                    temp = food_x%13;
                    food_x-=temp;
                    temp = food_y%13;
                    food_y-=temp;
                }
            }
        }
        if(key == "right")
            x = x+13;
        if(x > maxx)
            x =0;
        if(key == "left")
            x = x-13;
        if(x < 0)
            x = maxx-(maxx%13);
        if(key == "up")
            y = y-13;
        if(y > maxy)
            y = 0;
        if(key == "down")
            y = y+13;
        if(y < 0)
            y = maxy-(maxy%13);
        check();
        if(checkdied)
        {
            dead();
            return;
        }

        if(BONUS)
        {
            if(bonus>0)
                bonus-=10;
        }
        setcolor(BLACK);
        circle(snake_x[0],snake_y[0],8);
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(snake_x[0],snake_y[0],BLACK);

        for(int _size = 1; _size < snake_size; _size++)
        {
            circle(snake_x[_size],snake_y[_size],5);
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(snake_x[_size],snake_y[_size],BLACK);
        }

    }
}
void check()
{
    freopen("GameData.txt","w",stdout);
    if(highscore < score)
        cout << score << endl;
    else
        cout << highscore << endl;

    int maxx=getmaxx();
    int maxy=getmaxy()-50;

    for(int i = 1; i < snake_size; i++)
    {
        if(snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i])
        {
            delay(1000);
            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[i],snake_y[i],RED);

            setcolor(YELLOW);
            for(int i =1 ; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(snake_x[i],snake_y[i],YELLOW);

            }

            settextstyle(2,0,20);
            setcolor(WHITE);
            outtextxy(160,180,"GAME OVER!");
            setcolor(3);
            settextstyle(1,0,3);
            outtextxy(200,380,"Press ENTER to continue.");
            PlaySound("death.wav",NULL,SND_FILENAME | SND_SYNC);
            stage2flag=0;
            stage3flag=0;
            food_numb=0;

            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        clearviewport();
                        return;
                    }
                }
            }
        }
    }

    if(stage2flag == 1)
    {
        if(snake_x[0] <= 17 || snake_x[0] >= maxx-13 || snake_y[0] <= 17 || snake_y[0] >= maxy-6)
        {
            delay(1000);
            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[i],snake_y[i],RED);

            setcolor(YELLOW);
            for(int i =1 ; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(snake_x[i],snake_y[i],YELLOW);
            }
            settextstyle(2,0,20);
            setcolor(WHITE);
            outtextxy(160,180,"GAME OVER!");
            setcolor(3);
            settextstyle(1,0,3);
            outtextxy(200,380,"Press ENTER to continue.");
            PlaySound("death.wav",NULL,SND_FILENAME | SND_SYNC);

            stage2flag=0;
            stage3flag=0;
            food_numb=0;
            spd=90;

            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        clearviewport();
                        return;
                    }
                }
            }

        }
    }

    if(stage2flag ==1 && stage3flag == 1)
    {
        if(snake_x[0] <= 17 || snake_x[0] >= maxx-13 || snake_y[0] <= 17 || snake_y[0] >= maxy-6||((snake_y[0]>111 && snake_y[0]<304) && ((snake_x[0] >= 137 &&snake_x[0] <= 161)||(snake_x[0] >= 476 && snake_x[0] <= 498))))
        {
            delay(1000);
            setcolor(RED);
            circle(snake_x[0],snake_y[0],8);
            setfillstyle(SOLID_FILL,RED);
            floodfill(snake_x[i],snake_y[i],RED);

            setcolor(YELLOW);
            for(int i =1 ; i < snake_size; i++)
            {
                circle(snake_x[i],snake_y[i],5);
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(snake_x[i],snake_y[i],YELLOW);
            }

            settextstyle(2,0,20);
            setcolor(WHITE);
            outtextxy(160,180,"GAME OVER!");
            setcolor(3);
            settextstyle(1,0,3);
            outtextxy(200,380,"Press ENTER to continue.");
            PlaySound("death.wav",NULL,SND_FILENAME | SND_SYNC);

            stage2flag=0;
            stage3flag=0;
            food_numb=0;
            spd=90;

            while(1)
            {
                if(kbhit())
                {
                    char ch = getch();
                    if(ch == 13)
                    {
                        checkdied = true;
                        clearviewport();
                        return;
                    }
                }
            }
        }
    }
}
void dead()
{
    checkdied = false;
    snake_size = 5;
    score = 0;
    i=0;
    spd=90;
    for(int i=0; i<=5; i++)
    {
        int pi=1500;
        snake_x[i]=pi;
        snake_y[i]=pi;
        pi+=100;
    }
    score=0;
    return;
}
void help()
{
    clearviewport();
    settextstyle(10,0,1);
    setcolor(3);
    outtextxy(155,20,"           INSTRUCTION      ");
    outtextxy(30,60,"> Move the snake using the Arrow keys.");
    outtextxy(30,90,"> Press 'Alt' to Pause.");
    outtextxy(30,120,"> Select level and Stage,The game has 10 levels 3 stages.");
    outtextxy(30,150,"> Score per food of each level and stage is dependent");
    outtextxy(30,180,"       to its level and stage.");
    outtextxy(30,210,"> If you are not already in stage 3,your stage will be ");
    outtextxy(30,240,"      updated after eating 15 food for each time.");
    outtextxy(30,270,"> After reaching stage 3 your level will be increased ");
    outtextxy(30,300,"      after eating 10 food for each time.");
    outtextxy(30,330,"> You can not to make collision with the obstacles and ");
    outtextxy(30,360,"      stage.");
    setcolor(LIGHTGREEN);
    outtextxy(140,380,"           ENJOY THE GAME!      ");
    setcolor(3);
    outtextxy(350,430,"Press Enter to continue.");

    char ch = getch();
    clearviewport();
    return;
}
void level()
{
    clearviewport();
    char ch;
    char ara[100];
    while(true)
    {
        i = abs(spd/10-10);
        sprintf(ara,"SELECT LEVEL : %d",i);

        setcolor(GREEN);
        settextstyle(10,0,6);
        outtextxy(90,180,ara);
        setcolor(3);
        settextstyle(1,0,3);
        outtextxy(200,430,"Press ENTER to continue.");
        if(kbhit())
        {
            ch = getch();
            if(ch == 80)
            {
                PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
                spd-=10;
                if(spd < 0)
                    spd = 90;
            }
            else if(ch == 72)
            {
                PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
                spd+=10;
                if(spd >= 90)
                    spd = 0;
            }
            else if(ch == 13)
            {
                PlaySound("button.wav",NULL,SND_FILENAME | SND_SYNC);
                break;
            }

            sprintf(ara,"SELECT LEVEL : %d",i);

            setcolor(BLACK);
            outtextxy(90,180,ara);
        }
    }

    clearviewport();
}
void high()
{
    clearviewport();
    freopen("GameData.txt","r",stdin);
    cin >> highscore;
    char ara[100];
    sprintf(ara,"Highscore: %d",highscore);
    setcolor(GREEN);
    settextstyle(10,0,6);
    outtextxy(90,180,ara);
    setcolor(3);
    settextstyle(1,0,3);
    outtextxy(200,430,"Press any key to continue.");
    char ch = getch();
    clearviewport();
}

void stagee()
{
    clearviewport();
    int cursorr_y=190;
    settextstyle(3,0,3);
    setcolor(3);
    outtextxy(200,190,"EASY");
    outtextxy(200,220,"MEDIUM");
    outtextxy(200,250,"HARD");
    setcolor(LIGHTGREEN);
    outtextxy(150,cursorr_y,"-->");

    while(1)
    {
        if(kbhit)
        {
            char chh = getch();
            setcolor(BLACK);
            outtextxy(150,cursorr_y,"-->");

            if(chh==80)
            {
                cursorr_y+=30;
                PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursorr_y > 250)
                    cursorr_y=190;
            }
            else if(chh==72)
            {
                cursorr_y-=30;
                PlaySound("menu.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursorr_y < 190)
                    cursorr_y=250;
            }

            else if(chh == 13)
            {
                PlaySound("button.wav",NULL,SND_FILENAME | SND_SYNC);
                if(cursorr_y==190)
                {
                    food_numb=0;
                }
                else if(cursorr_y==220)
                {
                    food_numb=15;
                }
                else if(cursorr_y==250)
                {
                    food_numb=30;
                }
                break;
            }
            setcolor(LIGHTGREEN);
            outtextxy(150,cursorr_y,"-->");
        }
    }
    clearviewport();
}
