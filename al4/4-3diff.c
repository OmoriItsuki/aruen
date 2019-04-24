#include <stdio.h>
	
int max(int a,int b,int c){
	int t;
	t=a>b?a:b;
	t=c>t?c:t;
	return t;
	}
	
int min(int a,int b,int c){
	int t;
	t=a<b?a:b;
	t=c<t?c:t;
	return t;
	}
	
int difference(int a,int b,int c){
	return max(a,b,c)-min(a,b,c);
	}
	
int main(void){
	int a,b,c;
	printf("一つ目の整数:");
	scanf("%d\n",&a);
	printf("二つ目の整数:");
	scanf("%d\n",&b);
	printf("三つ目の整数:");
	scanf("%d\n",&c);
	
	printf("最大値と最小値の差は%dです。\n",difference(a,b,c));
	}
