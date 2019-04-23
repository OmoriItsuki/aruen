#include<stdio.h>

void main(){
	int ary[10];
	for(int i=0;i<10;i++){
		ary[i]=i*i;
	}
	for(int i=0;i<10;i++){
		if(i<9){
			printf("%d, ",ary[i]);
		}else{
			printf("%d\n",ary[i]);
		}
	}

}
