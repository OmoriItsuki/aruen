#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 30
#define SIZE_X 20
#define SIZE_Y 10
int start_x;
int start_y;

struct coord{
    int y;
    int x;
	struct coord *p;
};

struct queue{
	struct coord *buf[BUF_SIZE];
	int front;
	int rear;
	};

void read_map(char map[SIZE_Y][SIZE_X]){
	FILE *fp;
	fp=fopen("meiro1.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		return;
		}
	char chr;
	for(int i=0;i<SIZE_Y;i++){
		int j=0;
		while(j<SIZE_X){
			chr=fgetc(fp);
			if(chr!='\n'){
				map[i][j]=chr==' '?'/':chr;
				if(chr=='S'){
					start_x=j;
					start_y=i;
				}
				j++;
			}else{
				continue;
			}
		}
	}
	}

struct coord *create_node(struct coord *p,int y,int x){
	struct coord *coord=(struct coord*)malloc(sizeof(struct coord));
	coord->y=y;
	coord->x=x;
	coord->p=p;
	return coord;
	}
		
void enqueue(struct queue *q,struct coord *c){
	if((q->front-q->rear-BUF_SIZE)%BUF_SIZE!=-1){
		q->buf[q->front]=c;
		q->front=(q->front+1)%BUF_SIZE;
	}else{
		printf("Queue is Full\n");
	}
	}
	
struct coord *dequeue(struct queue *q){
	if(q->front!=q->rear){
		struct coord *c=q->buf[q->rear];
        struct coord *n=create_node(NULL,-1,-1);
		q->buf[q->rear]=n;
		q->rear=(q->rear+1)%BUF_SIZE;
		return c;
	}else{
		printf("Queue is None\n");
        struct coord *c=create_node(NULL,-1,-1);
		return c;
	}
	}
	
void print_map(char map[SIZE_Y][SIZE_X]){
		for (int i = 0; i < SIZE_Y; i++)
		{
			for(int j=0;j<SIZE_X;j++){
				if(map[i][j]=='/')map[i][j]=' ';
				putchar(map[i][j]);
			}
			putchar('\n');
		}
	}
	
void recursive_search(char map[SIZE_Y][SIZE_X],struct queue *q){
	struct coord *c;
	while((c=dequeue(q))->x!=-1){
	if(map[c->y-1][c->x]=='G' || map[c->y+1][c->x]=='G' ||map[c->y][c->x-1]=='G' ||map[c->y][c->x+1]=='G'){
		while (c->p!=NULL){
			map[c->y][c->x]='.';
			c=c->p;
		}
		return;
	}
	map[c->y][c->x]=map[c->y][c->x]=='S'?'S':' ';
	if(map[c->y-1][c->x]=='/'){
		struct coord *next=create_node(c,c->y-1,c->x);
		enqueue(q,next);
	}	
	if(map[c->y+1][c->x]=='/'){
		struct coord *next=create_node(c,c->y+1,c->x);
		enqueue(q,next);
	}
	if(map[c->y][c->x-1]=='/'){
		struct coord *next=create_node(c,c->y,c->x-1);
		enqueue(q,next);
	}
	if(map[c->y][c->x+1]=='/'){
		struct coord *next=create_node(c,c->y,c->x+1);
		enqueue(q,next);
	}
	}
}	

int main(void){
	char map[SIZE_Y][SIZE_X];
	read_map(map);
	struct queue q;
	q.front=q.rear=0;
	struct coord *s=(struct coord*)malloc(sizeof(struct coord));
	s->y=start_y;
	s->x=start_x;
	s->p=NULL;
	enqueue(&q,s);
	recursive_search(map,&q);
	print_map(map);
	}
