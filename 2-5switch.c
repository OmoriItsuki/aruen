#include<stdio.h>

void main(){
	int a,b,c;
	printf("Input a:");
	scanf("%d",&a);
	
	switch(a%2){
		case 1:
			printf("aは奇数です。\n");
			break;
		case 0:
			printf("aは偶数です。\n");
			break;
	}
}

