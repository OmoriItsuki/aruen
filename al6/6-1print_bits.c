#include <stdio.h>

int main(void){
	char c;
	scanf("%c",&c);
	for(int i=7;i>=0;i--)
	{
		putchar((c>>i)&1?'1':'0');
	}
	}