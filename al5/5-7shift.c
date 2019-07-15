#include <stdio.h>

int main(void){
	unsigned int x,t;
	scanf("%u\n",&x);
	t=x;
	
	int i=0;
	while(!(t&1))
	{
		i++;
		t>>=1;
	}
	
	printf("%uは%u×2^%dです。",x,t,i);
	}