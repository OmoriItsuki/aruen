#include<stdio.h>

int prime(int a){
	int i=2;
	int flag=1;
	while(i*i<=a){
		if(a%i==0){
			flag=0;
			break;
		}else{
			i++;
		}
	}
	return flag;
}

void main(){
	int m;
	printf("Input m:");
	scanf("%d",&m);
	int b=0;
	int a=2;
	while(1){
		b+=prime(a);
		if(b==m){
			break;
		}
		a++;
	}
	printf("%d番目の素数は%dです。\n",m,a);
}
