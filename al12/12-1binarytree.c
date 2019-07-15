#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
	struct word *left;
	struct word *right;
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

Word *create_node(char *word){
	Word *node=(Word*)malloc(sizeof(Word));
	strcpy(node->name,word);
	node->count=1;
	node->left=NULL;
	node->right=NULL;
	return node;
	}
	
void add_node(Word *root,char *buf){
	while(root!=NULL)
	{
		if(strcmp(root->name, buf)>0){
			if(root->left!=NULL){
				root=root->left;
			}else{
				root->left=create_node(buf);
				return;
			}
		}else if(strcmp(root->name, buf)<0){
			if(root->right!=NULL){
				root=root->right;
			}else{
				root->right=create_node(buf);
				return;
			}	
		}else{
			root->count++;
			return;	
		}
	}
	}
	
void print_nodes(Word *word){
	if(word->left!=NULL){
	    print_nodes(word->left);
		}
	if(word!=NULL){
		printf("%s %d\n",word->name,word->count);
	}
	if(word->right!=NULL){
		print_nodes(word->right);
	}
	}
		
int main(void){

	char buf[20];
	FILE *fp;
	
	fp=fopen("anne.txt", "r");
	if(fp==NULL){
		printf("File read error\n");
		exit(1);
		}
	
	read_word(fp,buf);
	Word *root=(Word*)malloc(sizeof(Word));
	root=create_node(buf);
		
	while(read_word(fp,buf)>0){
		add_node(root,buf);
		}
	
	print_nodes(root);
	fclose(fp);
	return 0;
	}
