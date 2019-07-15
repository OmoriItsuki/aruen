#include <stdio.h>

int main(void){
	long double ld;
	printf("実数を入力してください:");
	scanf("%Lf\n",&ld);
	
	double d=(double)ld;
	float f=(float)ld;
	
	printf("float型のサイズは%dバイトで、値は%fです。\n",sizeof(f),f);
	printf("double型のサイズは%dバイトで、値は%lfです。\n",sizeof(d),d);
	printf("long double型のサイズは%dバイトで、値は%Lfです。\n",sizeof(ld),ld);
	}
