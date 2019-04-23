#include<stdio.h>

void put_chars(char s,int a){
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(j<i)printf(" ");
			else printf("%c",s);
		}
		printf("\n");
	}
}

void main(){
	int n;
	printf("正の整数:");
	scanf("%d",&n);
	put_chars('*',n);
}
