#include <stdio.h>
int main(void){
    
	int a;
	printf("Input a:\n");
	scanf("%d",&a);
	if(a%3==0){
	    printf("3の倍数です\n");
	}else{
	    printf("3の倍数ではありません\n");
	}
}