#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_word(FILE *fp,char *buf){
	char chr;
	int i=0;
    for(int j=0;j<20;j++)buf[j]='';
	while(1){
		chr = fgetc(fp);
		switch(chr)
		{
			case ' ':
			case ',':
			case '.':
			case '\n':
			    if(i==0)break;
			    return i;
			case EOF:return 0;
			default:buf[i]=chr;i++;break;
		}
	}
	}
	
int main(void){
	char buf[500][20];
	FILE *fp;
	
	fp=fopen("anne_short.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
		
	int n=0;
	while(read_word(fp,buf[n])>0){
		  n++;
		}
	qsort((void *)buf, n, 20, strcasecmp);
	
	for(int i=0;i<n;i++)
	{
		printf("%s\n",buf[i]);
	}
	fclose(fp);
	return 0;
	}
