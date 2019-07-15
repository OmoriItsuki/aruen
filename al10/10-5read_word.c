#include <stdio.h>
#include <stdlib.h>

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
	char buf[20];
	FILE *fp;
	
	fp=fopen("anne_short.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
		
	while(read_word(fp,buf)>0){
		  printf("%s\n",buf,);
		}
	
	fclose(fp);
	return 0;
	}
