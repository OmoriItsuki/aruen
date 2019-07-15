#include <stdio.h>

void add(int *x,int y){
	*x+=y;
	}
	
int main(void){
	int a=10;
	add(&a, 5);add(&a, 5);
	printf("a:%d\n",a);
    return 0;
	}
