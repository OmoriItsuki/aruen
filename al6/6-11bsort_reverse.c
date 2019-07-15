#include <stdio.h>

void bsort(int *p,int l){
	int t=1;
	while(t)
	{
		t=0;
		l--;
		for(int i=0;i<l;i++)
		{
			if(p[i]>p[i+1])
			{
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=t;
				t=1;
			}
		}
	}
	}
	
int main(void){
	int ary[10]={72,74,50,71,77,84,61,90,73,75};
	bsort(ary,10);
	for(int i=0;i<10;i++)
	{
		printf("%d",ary[i]);printf("%s",i==9?"\n":" ");
	}
	}
