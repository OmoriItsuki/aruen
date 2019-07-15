#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_word(FILE *fp,char *buf){
	char chr;
	int i=0;
	memset(buf,'\0',20);
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
	char *words[400];
	char buf[20];
	FILE *fp;
	
	fp=fopen("anne_short.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
	
	int n,k=0;
	while((n=read_word(fp,buf))>0){
		words[k]=malloc(n);
		strcpy(words[k], buf);
		k++;
		}
	
	k=0;
	while(words[k]!=NULL)
	{
		printf("%s\n",words[k]);
		k++;
	}
	fclose(fp);
	return 0;
	}
