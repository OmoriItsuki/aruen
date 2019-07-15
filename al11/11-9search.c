#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct word{
	struct word *next;
	int count;
	char name[20];
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
			case '\r':
			    if(i==0)break;
			    return i;
			case EOF:return 0;
			default:buf[i]=chr;i++;break;
		}
	}
	}
	
void low(char *buf){
	for(int i=0;i<strlen(buf);i++)
	{
		buf[i]=tolower(buf[i]);
	}
	}
	
void search(Word *word,char *query){
	while(word!=NULL){
		if(strcmp(word->name,query)==0){
			printf("出現回数は%d回です。\n",word->count);
			return;
		}
		word=word->next;
	}
	printf("その単語はありません。\n");
	}

Word *create_node(char *word,Word *root){
	Word *node=(Word*)malloc(sizeof(Word));
	strcpy(node->name,word);
	node->next=root->next;
	node->count=1;
	return node;
	}
	
void add_node(Word *root,char *buf){
	while(root->next!=NULL)
	{
		if(strcasecmp(root->name, buf)==0){
			root->count++;
			return;
		}else if(strcasecmp(root->next->name,buf)>0){
			root->next=create_node(buf,root);
			return;
		}
		root=root->next;
	}
	root->next=create_node(buf,root);
	}
	
int main(void){
	char buf[20];
	FILE *fp;
	
	fp=fopen("anne_short.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
	
	Word *root=(Word*)malloc(sizeof(Word));
		
	while(read_word(fp,buf)>0){
		low(buf);
		add_node(root,buf);
		}
	
	fclose(fp);
	while(1){
		char query[20];
		printf("単語を入力してください:");
		scanf("%s\n",&query);
		if(strcmp(query,"quit")==0){
			printf("終了しました。\n");
			break;
			}
		search(root->next,query);
		}
	return 0;
	}
