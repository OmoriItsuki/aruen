#include <stdio.h>
#include <string.h>

int main(void){
	char str1[128],str2[128],str3[128];
	printf("str1の文字列を入力してください:");scanf("%s",&str1);
	printf("str2の文字列を入力してください:");scanf("%s",&str2);
	printf("str3の文字列を入力してください:");scanf("%s",&str3);
	int n=(strcmp(str1, str2)==0)+(strcmp(str2, str3)==0)+(strcmp(str3, str1)==0);
	switch(n)
	{
		case 0:printf("全て異なる文字列です。\n");break;
		case 1:printf("2つの文字列が同じです。\n");break;
		case 3:printf("3つの文字列は全て同じです。\n");break;
	}
	}
