#include <stdio.h>

int main(void){
	char  str[128];
	printf("現在のstrの値:%s\n",str);
	printf("文字列を入力してください:");scanf("%s\n",&str);
	printf("現在のstrの値:%s\n",str);
	}