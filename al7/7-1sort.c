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
	}
	}

int main(void){
	int ary[5];
	printf("数字を入力:");
	for(int i=0;i<5;i++)
	{
		char c;
		do
		{
			c=getchar();
		}while(c<48|57<c);
		ary[i]=c-48;
	}
	ssort(ary, 5);
	printf("整列完了:");
	for(int i=0;i<5;i++)
	{
		printf("%d",ary[i]);printf("%s",i==4?"\n":" ")
	}
	}
