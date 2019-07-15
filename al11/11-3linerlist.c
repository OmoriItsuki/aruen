#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
	char name[20];
	struct word *next;
	};
typedef struct word Word;

int read_word(FILE *fp,char *buf){
	char chr;
	int i=0;
    for(int i=0;i<20;i++)buf[i]='\0';
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

void print_nodes(Word *word){
	do
	{
		printf("%s ",word->name);
		word=word->next;
	}while(word!=NULL);
	}
	
int main(void){
	Word *root = NULL;
	char buf[20];
	FILE *fp;
	
	fp=fopen("anne_short.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
	
	Word *r;r=&root;
	while(read_word(fp,buf)>0){
		Word *word=malloc(sizeof(Word));
		r->next=&word;
		strcpy(word->name,buf);
		r=&r->next;
		}
	
	print_nodes(root);
	fclose(fp);
	return 0;
	}
