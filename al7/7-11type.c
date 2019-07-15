#include <stdio.h>

int main(void){
	int i=8;double d=1.0;
	
	printf("変数iの値は%dです。\n",i);
	printf("変数dの値は%.1lfです。\n",d);
	
	int *pi;double *pd;
	pi=&i;pd=&d;
	*pi/=2;*pd/=2;
	printf("変数iとdの値を2で割りました。\n");
	printf("変数iの値は%dです。\n",i);
	printf("変数dの値は%.1lfです。\n",d);
	
	*pd/=*pi;
	printf("変数dの値をiで割りました。\n");
	printf("変数dの値は%.3lfです。\n",d);
	}