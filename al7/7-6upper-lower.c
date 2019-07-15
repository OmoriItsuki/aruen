#include <stdio.h>
#include <ctype.h>

int main(void){
	char str[128];
	printf("文字列を入力してください:");scanf("%s\n",&str);
	for(int i=0;i<sizeof(str);i++)
	{
		if(islower(str[i]))
		{
			str[i]=toupper(str[i]);
		}
		else if(isupper(str[i]))
		{
			str[i]=tolower(str[i]);
		}
	}
	printf("%s\n",str);
	}
