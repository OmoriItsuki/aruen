#include <stdio.h>

int judge(int k){
	if(k%2==0||k%3==0)
	{
		return 0;
	}
	
	int i = 5;
	while(i*i<=k)
	{
		if(k%i==0||k%(i+2)==0)
		{
			return 0;
		}
		i+=6;
	}
	return 1;
	}
	
int main(void){
	int m;
	printf("input m:");
	scanf("%d\n",&m);
	
	switch(m)
	{
		case 1:printf("%d",2);return 0;
		case 2:printf("%d",3);return 0;
	}
	
	int n = 2,k = 1;
	while(n<m){
		k=k%6==1?k+4:k+2;
		n+=judge(k);
		}
	
	printf("%d\n",k);
	}
