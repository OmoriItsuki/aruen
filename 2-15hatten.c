#include<stdio.h>

int main(){

	char number[12][10]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"};
	int k;
	printf("12以下の自然数を入力してください。\n");
	scanf("%d",&k);

	if(k>12 && k<1){
		printf("12以下の値を入力してください。\n");
		return 0;
	}

	for(int i=0;i<k;i++){
		printf("%s ",number[i]);
	}
	printf("\n");
	return 0;
}
