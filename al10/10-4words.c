#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp;
	char chr;
	char buf[20];
	
	fp=fopen("anne_short.txt","r");
	if(fp==NULL){
		printf("そのファイルは存在しません。\n");
		return -1;
	}
	
	int i=0;
	while((chr = fgetc(fp))!= EOF){
		switch(chr)
		{
			case ' ':
			case ',':
			case '.':
			case '\n':
			case '\r':
			    if(i==0)break;
			    printf("%s\n",buf);
			    i=0;
			    for(int j=0;j<20;j++)buf[j]='\0';
			    break;
			default:buf[i]=chr;i++;break;
		}
	}
	
	fclose(fp);
	return 0;
}
