#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>

struct node1{
	int x;
	int y;
	struct node1 * next;
	struct node1 * prev;
}*start,*last;

int arr[150][150] = {{0}};

typedef struct node1 * node;

node newnode(int x, int y){
	node temp = (node)malloc(sizeof(node));
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void startgame(){
	int j;
	node temp = start;
	node t;
	start = NULL;
	start = newnode(150,150);
	for (j=0;j<6;j++){
		putpixel(temp->x,temp->y,WHITE);
		arr[temp->x][temp->y] = 1;
		t = newnode(temp->x,temp->y + 1);
		temp->next = t;
		t->prev = temp;
		temp = t;
		last = temp;
	}
	putpixel(temp->x,temp->y,WHITE);
	arr[temp->x][temp->y] = 1;
	last = temp;
}

void moveup(){
	node temp = newnode(start->x,start->y+1);

	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void movedown(){
	node temp = newnode(start->x,start->y-1);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void moveleft(){
	node temp = newnode(start->x-1,start->y);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void moveright(){
	node temp = newnode(start->x+1,start->y);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

int main(){
	//int j;
	int gdriver = DETECT, gmode, errorcode;
	int gd = DETECT, gm,j;
	char c;
	//scanf ("%c",&c);
	//initgraph(&gdriver, &gmode, "");
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	for (j=0;j<150;j++){
		arr[0][j] = 0;
		arr[149][j] = 0;
		putpixel(0,j,WHITE);
		putpixel(149,j,WHITE);
	}
	getch();
	for (j=0;j<150;j++){
		arr[j][0] = 0;
		arr[j][149] = 0;
		putpixel(j,0,BLACK);
		putpixel(j,149,BLACK);
	}
	//scanf("%c",&c); // input char for input 		taking w-a-s-d control method
	c=getch();
	startgame();
	while (1){
		if (kbhit()){ // checking if any key was hitted by the user
			c = getch();
		}
	   //	start->y;
	   //	start->x;
		if ((int) c == 27) break; // checking if the key hitted was esc
		if (c == 'w') moveup();
		else if (c == 'a') moveleft();
		else if (c == 's') movedown();
		else if (c == 'd') moveright();

//		if (start->x == fruitx && start->y == fruity){
//				node temp = newnode(start->x+1,start->y);
//				temp->next = start;
//				start->prev = temp;
//				start = temp;
//		}
	}
	closegraph();
	return 0;
}

