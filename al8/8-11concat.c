#include <stdio.h>
#include <string.h>

int main(void){
	char str1[128],str2[128],concat[256];
	printf("str1の文字列を入力してください:");scanf("%s",&str1);
	printf("str2の文字列を入力してください:");scanf("%s",&str2);
	strcpy(concat, str1);
	strcat(concat,str2);
	printf("concat:%s",concat);
	}
