#include <stdio.h>
int main(void){
    
	int a;
	printf("Input a:");
	scanf("%d\n",&a);
	switch(a%2){
	    case 0:printf("aは偶数です。");break;
	    case 1:printf("aは奇数です。");break;
	}
}