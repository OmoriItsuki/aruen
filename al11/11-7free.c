#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
void print_nodes(Word *word){
	while(word!=NULL){
		printf("%s %d\n",word->name,word->count);
		word=word->next;
	}
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
		if(strcmp(root->name, buf)==0){
			root->count++;
			return;
		}else if(strcmp(root->next->name,buf)>0){
			root->next=create_node(buf,root);
			return;
		}
		root=root->next;
	}
	root->next=create_node(buf,root);
	return;
	}

void free_nodes(Word *root){
	while(root!=NULL){
		Word *r;
		r=root->next;
		free(root);
		root=r;
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

	Word *root=(Word*)malloc(sizeof(Word));
		
	while(read_word(fp,buf)>0){
		add_node(root,buf);
		}
	
	print_nodes(root->next);
	free_nodes(root->next);
	fclose(fp);
	return 0;
	}
