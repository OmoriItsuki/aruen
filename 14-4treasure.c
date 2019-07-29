#include<stdio.h>
#include<stdlib.h>
#define SIZE_X 20
#define SIZE_Y 10
#define BUF_SIZE 50
#define TREASURE_NUMBER 3

struct coord{
   int x;
   int y;
};
typedef struct coord coord;

struct queue{
   coord buf[BUF_SIZE];
   int front;
   int rear;
};
typedef struct queue queue;

coord start,goal;
coord treasure[TREASURE_NUMBER + 2];
coord visit[TREASURE_NUMBER+1][SIZE_X][SIZE_Y];

int enqueue(struct queue *q, coord v){
   if(q->rear%BUF_SIZE == (q->front-1)%(BUF_SIZE)){
       printf("Queue Overflow!\n");
       return -1;
   }
   q->buf[(q->rear) % BUF_SIZE] = v;
   q->rear = (q->rear + 1) % BUF_SIZE;
   return 1;
}

coord dequeue(struct queue *q){
   if(q->rear == q->front){
       printf("Queue Underflow!\n");
       coord t;
       t.x = -1;
       t.y = -1;
       return t;
   }
   q->front = (q->front+1) % BUF_SIZE;
   return q->buf[q->front-1];
}

void display(struct queue q){
   if(q.rear == q.front){
       printf("This Queue is empty or Overflow!\n");
       return;
   }
   for(int i = q.front; i < q.rear; i = (i+1)%BUF_SIZE){
       printf("x:%d y:%d\n",q.buf[i].x,q.buf[i].y);
   }
   putchar('\n');
}

void read_map(char map[SIZE_X][SIZE_Y]){
   FILE *fp;
   int c,i=0,j=0,t=1;
   fp=fopen("meiro4.txt","r");
   if(fp==NULL){
       printf("FIle read error!\n");
       exit(1);
   }
   while ((c=fgetc(fp))!=EOF)
   {
       if(c!='\n'){
           map[j][i]=c;
           if(c=='S'){
               start.x=j;
               start.y=i;
               treasure[0] = start;
           }else if(c=='G'){
               goal.x=j;
               goal.y=i;
               treasure[TREASURE_NUMBER + 1]=goal;
           }else if(c=='T'){
               treasure[t].x=j;
               treasure[t].y=i;
               t++;
           }
           j++;
       }else{
           i++;
           j=0;
       }
   }
   fclose(fp);
}

void pure_print_map(char map[SIZE_X][SIZE_Y]){
    for (int i = 0; i < SIZE_Y; i++)
    {
       for (int j = 0; j < SIZE_X; j++)
       {
           printf("%c",map[j][i]);
       }
       putchar('\n');
   }
}

int print_map(char map[][SIZE_Y], int n, coord g, coord s, int a){
    coord index = visit[n][g.x][g.y];
    int t=1;
     for (int i = 0; i < SIZE_Y; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            if(map[j][i]=='.'){
                map[j][i]=' ';
            }
        }
    }

    while(index.x != s.x || index.y != s.y){
         map[index.x][index.y]='.';
        index = visit[n][index.x][index.y];
        t++;
    }
    if(a){
        pure_print_map(map);
    }
     for (int i = 0; i < SIZE_Y; i++)
    {
        for (int j = 0; j < SIZE_X; j++)
        {
            if(map[j][i]=='.'){
                map[j][i]=' ';
            }
        }
    }
   return t;
}

int queue_serch(char map[][SIZE_Y], coord s, coord g, int n, int k){
   queue q;
   q.front=0;
   q.rear=0;
    int a,b;
    enqueue(&q,s);
   coord tmp;
   while(q.rear != q.front){
       tmp=dequeue(&q);
       if(tmp.x != s.x || tmp.y != s.y){
           map[tmp.x][tmp.y]='.';
       }
       for(int i = 0; i < 4; i++){
           switch(i){
               case 0:
                   a=0;b=-1;
                   break;
               case 1:
                   a=0;b=1;
                   break;
               case 2:
                   a=1;b=0;
                   break;
               case 3:
                   a=-1;b=0;
                   break;
           }
           if(tmp.x+a == g.x && tmp.y+b == g.y){
                visit[n][tmp.x+a][tmp.y+b]=tmp;
               return print_map(map,n,g,s,k);
               
           }
           if(map[tmp.x+a][tmp.y+b] == ' '){
                visit[n][tmp.x+a][tmp.y+b]=tmp;
               tmp.x+=a;
               tmp.y+=b;
               enqueue(&q, tmp);
               tmp.x-=a;
               tmp.y-=b;
               //printf("%d %d\n",tmp.x,tmp.y);
               //pure_print_map(map);
           }
       }
   }
   printf("error!\n");
   return -1;
}

int treasure_cost(char map[][SIZE_Y], coord rout[TREASURE_NUMBER+2], int a){
    int t=0,k;
    for(int i = 0; i < TREASURE_NUMBER + 1; i++){
       //printf("x:%d y:%d x:%d y:%d\n",rout[i].x,rout[i].y,rout[i+1].x,rout[i+1].y);
       if(a){
           printf("\nPhase%d\n",i+1);
       }
       k = queue_serch(map, rout[i], rout[i+1],i,a);
       if(k == -1){
           return -1;
       }else{
           t += k;
       }
   }
   return t;
}

int main(void){
    int c;
   char map[SIZE_X][SIZE_Y];
   read_map(map);
   coord rout[TREASURE_NUMBER+2];
   rout[0]=start;
   rout[TREASURE_NUMBER+1]=goal;
   int min_cost[TREASURE_NUMBER+1];
   for(int l = 1; l <= TREASURE_NUMBER; l++){
       for(int m = 1; m <= TREASURE_NUMBER; m++){
           for(int n = 1; n <= TREASURE_NUMBER; n++){
               if(l != n && n != m && l != m){
                   //printf("%d %d %d\n",l,m,n);
                    rout[1]=treasure[l];
                    rout[2]=treasure[m];
                    rout[3]=treasure[n];
                    if(min_cost[0]>(c=treasure_cost(map, rout,0)) || min_cost[0]==0){
                        min_cost[0]=c;
                        min_cost[1]=l;
                        min_cost[2]=m;
                        min_cost[3]=n;
                    }
                    //printf("cost:%d\n",c);
               }
               
           }
       }
   }
   if(min_cost[0]>0){
        for(int i=1;i<=3;i++){
            rout[i]=treasure[min_cost[i]];
        }
        treasure_cost(map,rout,1);
        printf("総コスト：%d\n",min_cost[0]);
   }else{
       printf("error!");
   }
   return 0;
}