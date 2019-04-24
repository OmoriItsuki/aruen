#include <stdio.h>
int main(void){ 
	int k;
    printf("Input k:");
	scanf("%d\n",&k);
	for(int i=1;i<k;i+=2){
	    printf("%d, ",i);
	}
}