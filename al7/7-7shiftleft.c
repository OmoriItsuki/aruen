#include <stdio.h>

void shiftleft(char s[][9],int n){
	for(int i=0;i<n;i++)
	{
		char t=s[i][0];
		int j=0;
		while(s[i][j+1]!=NULL && j<8){
		    s[i][j]=s[i][j+1];
		    j++;
		}
		s[i][j]=t;
	}
	}
	
int main(void){
	char str2[4][9]={"Wakayama","Univ.","System","Engineer"};
	printf("文字列を出力します。\n");
	for(int i=0;i<4;i++)printf("%s\n",str2[i]);
	printf("配列の大きさは%dバイトです。\n",sizeof(str2));
	
	shiftleft(str2, 4);
	printf("文字列を出力します。\n");
	for(int i=0;i<4;i++)printf("%s\n",str2[i]);
	}
