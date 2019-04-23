#define NUM_ELEMENTS 10

#include<stdio.h>
#include<limits.h>

void main(){
	int ary[NUM_ELEMENTS]={72,74,50,71,77,84,61,90,73,75};
	int max,min,sum;
	max=INT_MIN;
	min=INT_MAX;
	sum=0;
	float ave=0;
	float var=0;

	for(int i=0;i<NUM_ELEMENTS;i++){
		max=ary[i]>max ? ary[i] : max;
		min=ary[i]<min ? ary[i] : min;
		sum+=ary[i];
	}
	ave =(float) sum / NUM_ELEMENTS;
	printf("%d %d %.3f",sum,NUM_ELEMENTS,ave);
	
	for(int i=0;i<NUM_ELEMENTS;i++){
		var+=(ary[i]-ave)*(ary[i]-ave);
	}
	var/=NUM_ELEMENTS;

	printf("最大値は%d、最小値は%d、平均は%.3f、分散は%.3fです。\n",max,min,ave,var);
}
