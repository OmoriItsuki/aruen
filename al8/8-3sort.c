#include <stdio.h>

int *max_element(int *ary,int n){
	int p=0;
	for(int i=0;i<n;i++)
	{
		p=ary[p]>ary[i]?p:i;
	}
	return &ary[p];
	}
	
void swap(int *x,int *y){
	int t=*x;
	*x=*y;
	*y=t;
	}
	
int main(void){
	int ary[10]={72,74,50,71,77,84,61,90,73,75};
	for(int i=0;i<10;i++)
	{
		swap(max_element(ary+i, 10-i), &ary[i]);
	}
	for(int i=0;i<10;i++)
	{
		printf("%d%s",ary[i],i!=9?" ":"\n");
	}
	}
