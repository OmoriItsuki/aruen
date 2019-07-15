#include <stdio.h>

int main(void){
	char str1[128],str2[128],concat[256];
	printf("str1の文字列を入力してください:");scanf("%s",&str1);
	printf("str2の文字列を入力してください:");scanf("%s",&str2);
	int l1=0,l2=0;
	while(str1[l1]!=NULL)
	{
		concat[l1]=str1[l1];
		l1++;
	}
	while(str2[l2]!=NULL)
	{
		concat[l1+l2]=str2[l2];
		l2++;
	}
	printf("concat:%s",concat);
	}
