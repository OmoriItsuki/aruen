#include <stdio.h>
#define BUF_SIZE 20

struct  stack{
	int buf[BUF_SIZE];
	int top;
	};
	
int push(struct stack *s,int v){
	if(s->top<BUF_SIZE){
		s->buf[s->top]=v;
		s->top++;
		return 1;
	}else{
		printf("Stack is Full\n");
		return -1;
	}
	}
	
int pop(struct stack *s){
	if(s->top>0){
		s->top--;
		int n=s->buf[s->top];
		s->buf[s->top]=0;
		return n;
	}else{
		printf("Stack is None\n");
		return -1;
	}
	}
	
void display(struct stack s){
	int n;
	while((n=pop(&s))!=-1){
		printf("%d\n",n);
	}
	}
	
int main(void){
		struct stack s;
		s.top=0;
		push(&s,1);push(&s,2);push(&s,3);push(&s,4);push(&s,5);
		display(s);
		pop(&s);pop(&s);
		display(s);
		return 0;
	}
