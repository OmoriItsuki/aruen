#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 100
#define SIZE_X 20
#define SIZE_Y 10
int start_x;
int start_y;

struct coord{
    int y;
    int x;
};

struct queue{
	struct coord buf[BUF_SIZE];
	int head;
	int tail;
	};

void read_map(char map[SIZE_Y][SIZE_X]){
	FILE *fp;
	fp=fopen("meiro2.txt", "r");
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
		
void enqueue(struct queue *q,struct coord c){
	if((q->head-q->tail-BUF_SIZE)%BUF_SIZE!=-1){
		q->buf[q->head]=c;
		q->head=(q->head+1)%BUF_SIZE;
	}else{
		printf("Queue is Full\n");
	}
	}
	
    struct coord dequeue(struct queue *q){
	if(q->head!=q->tail){
		struct coord c=q->buf[q->tail];
        struct coord n={0,0};
		q->buf[q->tail]=n;
		q->tail=(q->tail+1)%BUF_SIZE;
		return c;
	}else{
		printf("Queue is None\n");
        struct coord c={-1,-1};
		return c;
	}
	}

void print_map(char map[SIZE_Y][SIZE_X]){
		for (int i = 0; i < SIZE_Y; i++)
		{
			for(int j=0;j<SIZE_X;j++){
				//if(map[i][j]=='/')map[i][j]=' ';
				putchar(map[i][j]);
			}
			putchar('\n');
		}
	}

int what_char(char map[SIZE_Y][SIZE_X],struct coord c,int dy,int dx){
	switch(map[c.y+dy][c.x+dx])
	{
		case 'G':return 1;
		case '/':return 0;
		case '.':return -2;
		default:return -1;
	}
}
	
void back(char map[SIZE_Y][SIZE_X],int y,int x){
		if(map[y][x]=='0'){
			map[y][x]='.';
			return;
		}else if(map[y][x]=='S')return;
		else if(map[y][x]=='G')return;
		else{
			map[y][x]=' ';
			if(map[y-1][x]=='.')back(map, y-1,x);
			if(map[y+1][x]=='.')back(map, y+1,x);
			if(map[y][x-1]=='.')back(map, y,x-1);
			if(map[y][x+1]=='.')back(map, y,x+1);
		}
	}

void recursive_search(char map[SIZE_Y][SIZE_X],struct queue *q){
	struct coord c;
	while((c =dequeue(q)).x!=-1){
			map[c.y][c.x]=map[c.y][c.x]=='S'?'S':map[c.y][c.x]=='G'?'G':'.';
			if(what_char(map,c,0,0)=='G'){
				return;
			}else if(what_char(map,c,-1,0)<0 && what_char(map,c,1,0)<0 && what_char(map,c,0,-1)<0 &&what_char(map,c,0,1)<0){
				back(map,c.y,c.x);
			}else{
				int m=0;
				if(what_char(map,c,-1,0)>=0){
					struct coord n={c.y-1,c.x};
					enqueue(q,n);
					m++;
				}
				if(what_char(map,c,1,0)>=0){
					struct coord n={c.y+1,c.x};
					enqueue(q,n);
					m++;
				}
				if(what_char(map,c,0,1)>=0){
					struct coord n={c.y,c.x+1};
					enqueue(q,n);
					m++;
				}
				if(what_char(map,c,0,-1)>=0){
					struct coord n={c.y,c.x-1};
					enqueue(q,n);
					m++;
				}
				if(m>1 && map[c.y][c.x]!='S'){
					map[c.y][c.x]='0';
				}
			}
		
	}
}	

int main(void){
	char map[SIZE_Y][SIZE_X];
	read_map(map);
	struct queue q;
	q.head=q.tail=0;
	struct coord start={start_y,start_x};
	enqueue(&q,start);
	recursive_search(map,&q);
	print_map(map);
	}
