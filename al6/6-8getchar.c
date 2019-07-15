#include <stdio.h>

int main(void){
	int even=0,odd=0;
	int c;
	while((c=getchar())!=EOF)
	{
		if(48<=c&&c<=57)
		{
			if(c%2==0)even++;
			else odd++;
		}
	}
	if(odd!=even)printf("%sの方が多い\n",even>odd?"偶数":"奇数");
	else printf("偶数と奇数は同じ数");
	}
