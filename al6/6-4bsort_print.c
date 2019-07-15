#include <stdio.h>

void bsort(int *p,int l){
	int t=1,s=0;
	while(t)
	{
		t=0;
		for(int i=l-1;i>=s;i--)
		{
			if(p[i]>p[i+1])
			{
				t=p[i];
				p[i]=p[i+1];
				p[i+1]=t;
				t=1;
				for(int i=0;i<10;i++)
				{
					printf("%d",p[i]);printf("%s",i==9?"\n":" ");
				}
			}
		}
		s++;
	}
	}
	
int main(void){
	int ary[10]={72,74,50,71,77,84,61,90,73,75};
	bsort(ary,10);
	printf("\n");
	for(int i=0;i<10;i++)
	{
		printf("%d",ary[i]);printf("%s",i==9?"\n":" ");
	}
	}
