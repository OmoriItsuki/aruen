#include <stdio.h>

int main(void){
	int a=10,b=20,result1,result2,*p,*q;
	p=&a,q=&b;
	result1 = a*b;
	result2 = (*p)*(*q);
	printf("result1: %d\n",result1);
	printf("result2: %d\n",result2);
	return 0;
	}
