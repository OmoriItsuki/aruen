#include <stdio.h>
#include <string.h>

int main(void){
	char str[1024]="Wakayama University is a good university in Wakayama.";
	char query[128],replace[128];
	printf("検索対象文字列strは、%sです。\n",str);
	printf("検索文字列queryを入力してください:");scanf("%s\n",&query);
	printf("置換文字列replaceを入力してください:");scanf("%s\n",&replace);

	char* pos;
	int *n;n=&str;
	int q=strlen(query),r=strlen(replace);
	
	while((pos=strstr(n,query))!=NULL){
　    if (q < r){
　　    memmove(pos+r, pos+q,strlen(str)-q-(pos-str)+1);
　　    memcpy(pos, replace, r);
　    }else{
　　    memcpy(pos, replace, r);
　　    if (q > r){
　　　  memmove(pos+r, pos+q,strlen(str)-r-(pos-str)+1);
　　  }
　  }
    n=pos+r;
    }
	printf("%s",str);
	}
