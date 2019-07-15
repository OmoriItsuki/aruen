#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char str1[128],str2[128],concat[256];
	printf("整数部分を入力してください:");scanf("%s",&str1);
	printf("小数部分を入力してください:");scanf("%s",&str2);
	strcpy(concat, str1);
	strcat(concat,".");
	strcat(concat,str2);
	double d=atof(concat);
	printf("入力された実数は、%lfです。",d);
	}
