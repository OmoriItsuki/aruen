#include <stdio.h>

int main(void){
	char str1[128],str2[128];
	printf("str1の文字列を入力してください:");scanf("%s",&str1);
	printf("str2の文字列を入力してください:");scanf("%s",&str2);
	int l1=0,l2=0;
	while(str1[l1]!=NULL)
	{
		l1++;
	}
	while(str2[l2]!=NULL)
	{
		l2++;
	}
	printf("2つの文字列の長さは%s",l1==l2?"同じです。\n":"異なります。\n");
	}
