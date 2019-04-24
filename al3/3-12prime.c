#include <stdio.h>

int main(void){
	int k;
	printf("input k:");
	scanf("%d\n",&k);
	
	if(k==1)
	{
		printf("%dは素数ではありません。\n",k);
		return 0;
	}
	if(k==2|k==3){
		printf("%dは素数です。\n",k);
		return 0;
	}
	if(k%2==0|k%3==0)
	{
		printf("%dは素数ではありません。\n",k);
		return 0;
	}
	
	int i = 5;
	while(i*i<=k)
	{
		if(k%i==0)
		{
			printf("%dは素数ではありません。\n",k);
			return 0;
		}
		if(k%(i+2)==0)
		{
			printf("%dは素数ではありません。\n",k);
			return 0;			
		}
		i+=6;
	}
	
	printf("%dは素数です。\n",k);
	}
