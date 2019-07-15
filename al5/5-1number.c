#include <stdio.h>

int judge(int n){
	return n%2 == 0? 0:
	       n%3 == 0? 0:
	       n%10== 0? 0:1;
	}
	
int next_num(int n){
	do
	{
		n++;
	}while(judge(n)==0);
	return n;
	}
	
int main(void){
	int n=0,i=0;
	while(n<10000){
		n=next_num(n);
		i++;
		}
	printf("初めて10000を超えるのは%d番目であり、その数は%dである。\n",i,n);
	}