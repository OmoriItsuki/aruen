#include <stdio.h>
int main(void){ 
	int k,n=0;
	char num[12][8] ={"one","two","three", "four","five","six","seven","eight","nine","ten","eleven","twelve"};
    printf("Input k:");
	scanf("%d\n",&k);
	if(k<0 | 12<k){
	    printf("12以下の値は入力してください。\n");
	}else{
	    for(int i=0;i<k;i++){
	        printf("%s ",num[i]);
	    }
	}
}