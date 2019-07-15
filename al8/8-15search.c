#include <stdio.h>

int strstr(char *str,char *query){
    int i=0,j=0;
    while(str[i]!=NULL){
        if(query[j]==NULL)return 1;
        if(str[i]==query[j]){
            j++;
        }else{
            j=0;
        }
        i++;
    }
    return 0;
}

int main(void){
	char str[]="Wakayama University is a good university in Wakayama.";
	char query[128];
	printf("検索対象文字列strは、%sです。\n",str);
	printf("検索文字列queryを入力してください:");scanf("%s",&query);
	printf("queryはstrに%s",strstr(str, query)!=0?"含まれます。":"含まれません。");
	}
