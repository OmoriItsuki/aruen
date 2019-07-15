#include <stdio.h>
#include <limits.h>

int main(void){
	printf("char型の表現範囲:%d~%d\n",CHAR_MIN,CHAR_MAX);
	printf("int型の表現範囲:%d~%d\n",INT_MIN,INT_MAX);
	printf("unsigned int型の表現範囲:%u~%u\n",0,UINT_MAX);
	}
