#include <stdio.h>

int main(void){
	char str2[4][9]={"Wakayama","Univ.","System","Engineer"};
	
	printf("文字列を出力します。\n");
	for(int i=0;i<4;i++)printf("%s\n",str2[i]);
	printf("配列の大きさは%dバイトです。\n",sizeof(str2));
	printf("置き換える文字列を入力してください:");scanf("%s\n",&str2[1]);
	
	printf("文字列を出力します。\n");
	for(int i=0;i<4;i++)printf("%s\n",str2[i]);
	}