#include <stdio.h>
int main(void){ 
	int k,n=0;
    printf("Input k:");
	scanf("%d\n",&k);
	for(int i=1;i<=k;i++){
	    if(k%i==0){
	        printf("%d ",i);
	        n++;
	    }
	}
	printf(":%d",n);
}