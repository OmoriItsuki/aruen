#include<stdio.h>

void main(){
	int ary[10];
	for(int i=0;i<10;i++){
		ary[i]=i*i;
	}
	int tmp;
	for(int i=0;i<10;i++){
		tmp=ary[i];
		ary[i]=ary[9-i];
		ary[9-i]=tmp;
	}
	for(int i=0;i<10;i++){
		if(i<9)printf("%d, ",ary[i]);
		else printf("%d\n",ary[i]);
	}


}
