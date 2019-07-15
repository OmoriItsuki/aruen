#include <stdio.h>

void reverse(char s[][9],int n){
	for(int i=0;i<n;i++)
	{
	    int m=0;
	    while(s[i][m]!=NULL){
	        m++;
	    }
	    
		for(int j=0;j<m/2;j++){
		    char t=s[i][j];
		    s[i][j]=s[i][m-j-1];
		    s[i][m-j-1]=t;
		}
	}
	}
	
int main(void){
	char str2[4][9]={"Wakayama","Univ.","System","Engineer"};
	printf("文字列を出力します。\n");
	for(int i=0;i<4;i++)printf("%s\n",str2[i]);
	printf("配列の大きさは%dバイトです。\n",sizeof(str2));
	
	reverse(str2, 4);
	printf("文字列を出力します。\n");
	for(int i=0;i<4;i++)printf("%s\n",str2[i]);
	}
