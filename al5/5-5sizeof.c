#include <stdio.h>

int main(void){
	char c;
	int i;
	double d;
	int a[10];
	
	printf("char 型の変数 c が占有するメモリ領域は%dバイトです。\n",sizeof(c));
	printf("int 型の変数 i が占有するメモリ領域は%dバイトです。\n",sizeof(i));
	printf("double 型の変数 d が占有するメモリ領域は%dバイトです。\n",sizeof(d));
	printf("int 型の配列 a が占有するメモリ領域は%dバイトです。\n",sizeof(a));
	printf("配列 a の要素数は%dです。",sizeof(a)/sizeof(int));
	}
	
