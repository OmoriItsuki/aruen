#include <stdio.h>

int main(void){
	char str[128];
	printf("文字列を入力してください:");scanf("%s",str);
	for(int i=0;i<3;i++)
	{
		int j=0;
		while(str[j]!=NULL){
		    putchar(str[j]);
		    j++;
	}
	}
}