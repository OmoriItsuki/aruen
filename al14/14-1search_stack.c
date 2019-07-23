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

struct  stack{
	struct coord buf[BUF_SIZE];
	int top;
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
	
int push(struct stack *s,struct coord c){
	if(s->top<BUF_SIZE){
		s->buf[s->top]=c;
		s->top++;
		return 1;
	}else{
		printf("Stack is Full\n");
		return -1;
	}
	}
	
struct coord pop(struct stack *s){
	if(s->top>0){
		s->top--;
		struct coord c=s->buf[s->top];
		s->buf[s->top].y=0;
		s->buf[s->top].x=0;
		return c;
	}else{
		printf("Stack is None\n");
        struct coord c= {-1,-1};
		return c;
	}
	}
	
void print_map(char map[SIZE_Y][SIZE_X],struct stack *s){
		for (int i = 0; i < SIZE_Y; i++)
		{
			for(int j=0;j<SIZE_X;j++){
				if(map[i][j]=='/')map[i][j]=' ';
				putchar(map[i][j]);
			}
			putchar('\n');
		}
	}

int search_next(char map[SIZE_Y][SIZE_X],struct stack *s,int dy,int dx){
	struct coord next;
	switch(map[s->buf[s->top-1].y+dy][s->buf[s->top-1].x+dx]){
		case '/':
			next.y=s->buf[s->top-1].y+dy;
			next.x=s->buf[s->top-1].x+dx;
			push(s,next);
			return 0;
		case 'G':
			return 1;
		default:
			return -1;
	}
}

void recursive_search(char map[SIZE_Y][SIZE_X],struct stack *s){
	if(map[s->buf[s->top-1].y][s->buf[s->top-1].x]!='S'){
		map[s->buf[s->top-1].y][s->buf[s->top-1].x]='.';
	}
	int n;
	if((n=search_next(map,s,1,0))>=0){
		if(n==0)recursive_search(map,s);
	}else if((n=search_next(map,s,0,-1))>=0){
		if(n==0)recursive_search(map,s);
	}else if((n=search_next(map,s,0,1))>=0){
		if(n==0)recursive_search(map,s);
	}else if((n=search_next(map,s,-1,0))>=0){
		if(n==0)recursive_search(map,s);
	}else{
		struct coord c = pop(s);
		map[c.y][c.x]=' ';
		recursive_search(map,s);
	}
}
	
int main(void){
	char map[SIZE_Y][SIZE_X];
	read_map(map);
	struct stack s;
	s.top=0;
	struct coord start={start_y,start_x};
	push(&s,start);
	recursive_search(map,&s);
	print_map(map,&s);
	}
