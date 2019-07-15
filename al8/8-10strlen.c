#include <stdio.h>
#include <string.h>

int main(void){
	char str1[128],str2[128];
	printf("str1の文字列を入力してください:");scanf("%s",&str1);
	printf("str2の文字列を入力してください:");scanf("%s",&str2);
	printf("2つの文字列の長さは%s",strlen(str1)==strlen(str2)?"同じです。\n":"異なります。\n");
	}
