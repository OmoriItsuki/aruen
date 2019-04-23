#include<stdio.h>

int max(int x,int y,int z){
	return x>y ? x>z ? x : z : y>z ? y : z;
}

int min(int x,int y,int z){
	return x>y ? y>z ? z : y : x>z ? z : x;
}
int mid(int x,int y,int z){
	return max(x,y,z)==x ? min(x,y,z)==y ? z : y : max(x,y,z)==y ? min(x,y,z)== x ? z : x : min(x,y,z)==x ? y : x;
}

void main(){
	int a,b,c;
	printf("Input(a,b,c)");
	scanf("%d %d %d",&a,&b,&c);
	
	printf("最大値は%dです。\n中央値は%dです。\n最小値は%dです。\n",max(a,b,c),mid(a,b,c),min(a,b,c));
	}
