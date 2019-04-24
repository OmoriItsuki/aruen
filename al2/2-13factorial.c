#include <stdio.h>
int main(void){ 
	int k,n=1;
    printf("Input k:");
	scanf("%d\n",&k);
	for(int i=1;i<=k;i++){
	    n*=i;
	}
	printf("%d",n);
}