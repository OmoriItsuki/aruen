#include <stdio.h>

int main(void){
	char str[20]="Wakayama University";
	for(int i=0;i<sizeof(str);i++)
	{
		switch(str[i])
		{
			case 'a':str[i]='A';break;
			case 'e':str[i]='E';break;
			case 'i':str[i]='I';break;
		}
	}
	printf("%s\n",str);
	}
