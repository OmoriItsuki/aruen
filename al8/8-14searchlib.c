#include <stdio.h>
#include <string.h>

int main(void){
	char str[]="Wakayama University is a good university in Wakayama.";
	char query[128];
	printf("検索対象文字列strは、%sです。\n",str);
	printf("検索文字列queryを入力してください:");scanf("%s",&query);
	printf("queryはstrに%s",strstr(str, query)!=NULL?"含まれます。":"含まれません。");
	}
