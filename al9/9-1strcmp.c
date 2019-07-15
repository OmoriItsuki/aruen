#include <stdio.h>
#include <string.h>

void swap(char *s1,char *s2){
	char tmp[128];
	strcpy(tmp, s1);
	strcpy(s1, s2);
	strcpy(s2, tmp);
	}
int main(void){
	char str1[128],str2[128],str3[128];
	printf("str1の文字列を入力してください:");scanf("%s\n",&str1);
	printf("str2の文字列を入力してください:");scanf("%s\n",&str2);
	printf("str3の文字列を入力してください:");scanf("%s\n",&str3);

	if(strcmp(str1, str2)>0)swap(str1, str2);
	if(strcmp(str2, str3)>0)swap(str2, str3);
	if(strcmp(str1, str2)>0)swap(str1, str2);
	printf("文字列を辞書順に並び替えました。\n");
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	printf("str3:%s\n",str3);
	}
