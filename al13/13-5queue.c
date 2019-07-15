#include <stdio.h>
#define BUF_SIZE 20

struct  queue{
	int buf[BUF_SIZE];
	int head;
	int tail;
	};
	
int enqueue(struct queue *q,int v){
	if((q->head-q->tail-BUF_SIZE)%BUF_SIZE!=-1){
		q->buf[q->head]=v;
		q->head=(q->head+1)%BUF_SIZE;
		return 1;
	}else{
		printf("Queue is Full\n");
		return -1;
	}
	}
	
int dequeue(struct queue *q){
	if(q->head!=q->tail){
		int n=q->buf[q->tail];
		q->buf[q->tail]=0;
		q->tail=(q->tail+1)%BUF_SIZE;
		return n;
	}else{
		printf("Queue is None\n");
		return -1;
	}
	}
	
void display(struct queue q){
	int n;
	while(1){
		n=dequeue(&q);
		if(n!=-1){
			printf("%d\n",n);
		}else{
			return;
		}	
	}
	}
	
int main(void){
		struct queue q;
		q.head=q.tail=0;
		enqueue(&q,1);enqueue(&q,2);enqueue(&q,3);enqueue(&q,4);enqueue(&q,5);
		display(q);
		dequeue(&q);dequeue(&q);
		display(q);
		return 0;
	}
