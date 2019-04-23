#include<stdio.h>

void main(){
	int ary[10];
	for(int i=0;i<10;i++){
		ary[i]=i*i;
	}
	int ary2[10];
	ary2[0]=ary[0];
	for(int i=1;i<10;i++)
		ary2[i]=ary2[i-1]+ary[i];

	for(int i=0;i<10;i++){
		if(i<9)printf("%d, ",ary2[i]);
		else printf("%d\n",ary2[i]);
	}

}
