#include <stdio.h>

void ssort(int *p,int l){
	int s=0;
	while(s<l)
	{
		int min =s;
		for(int i=s;i<l;i++)
		{
			min=p[min]<p[i]?min:i;
		}
		int t=p[s];
		p[s]=p[min];
		p[min]=t;
		s++;
		for(int i=0;i<10;i++)
		{
			printf("%d",p[i]);printf("%s",i==9?"\n":" ");
		}
	}
	}
	
int main(void){
	int ary[10]={72,74,50,71,77,84,61,90,73,75};
	ssort(ary,10);
	printf("\n");
	for(int i=0;i<10;i++)
	{
		printf("%d",ary[i]);printf("%s",i==9?"\n":" ");
	}
	}
